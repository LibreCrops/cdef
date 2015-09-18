;; demo.scm
;;
;; An implementation in Scheme of my algorithm to extract complex
;; structs (with anonymous unions in) stored in PDB files.
;;
;; Author: kbridge@github
;;
;; This program is free software: you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation, either version 3 of the License, or
;; (at your option) any later version.
;;
;; This program is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.
;;
;; You should have received a copy of the GNU General Public License
;; along with this program.  If not, see <http://www.gnu.org/licenses/>.

;; Part I

;; mb --> member
(define (mb offset name)
  (vector name offset))

(define (mb-name mb)
  (vector-ref mb 0))

(define (mb-offset mb)
  (vector-ref mb 1))

(define (mb-size mb)
  4)

(define (mb-bottom-offset mb)
  (+ (mb-offset mb)
     (mb-size mb)))

(define data1
  (vector (mb 0 "a")
          (mb 4 "b")
          (mb 4 "c")
          (mb 8 "d")
          (mb 8 "e")
          (mb 12 "f")
          (mb 4 "g")
          (mb 8 "h")
          (mb 16 "i")))

(define data2
  (vector (mb 0 "a")
          (mb 0 "b")
          (mb 4 "c")
          (mb 4 "d")
          (mb 4 "e")
          (mb 4 "f")
          (mb 8 "g")
          (mb 8 "h")
          (mb 12 "i")
          (mb 12 "j")
          (mb 12 "k")
          (mb 16 "l")
          (mb 20 "m")
          (mb 24 "n")))

(define data3
  (vector (mb 0 "a")
          (mb 4 "b")
          (mb 4 "c")
          (mb 8 "d")
          (mb 8 "e")
          (mb 12 "f")
          (mb 12 "g")))

(define data4
  (vector (mb 0 "a")
          (mb 4 "b")
          (mb 8 "c")
          (mb 12 "d")
          (mb 16 "e")
          (mb 4 "f")
          (mb 4 "g")
          (mb 8 "h")
          (mb 8 "i")
          (mb 12 "j")
          (mb 16 "k")
          (mb 20 "l")))

(define (calc-columns members)
  (define (calc-reset-list)
    (let ((len (vector-length members)))
      (let rec ((i 0)
                (last-offset 0))
        (if (= i len)
            '()
            (let* ((member (vector-ref members i))
                   (this-offset (mb-offset member)))
              (if (<= this-offset last-offset)
                  (cons (list this-offset i)
                        (rec (+ i 1) this-offset))
                  (rec (+ i 1) this-offset)))))))
  (list->vector (calc-reset-list)))

(define (column-top-offset column)
  (car column))

(define (column-top-member-index column)
  (cadr column))

(define (column-above? abover column)
  (< (column-top-offset abover)
     (column-top-offset column)))

(define (column-parallel? column1 column2)
  (= (column-top-offset column1)
     (column-top-offset column2)))  

(define (calc-resetted-columns columns)
  (define (get-column i)
    (vector-ref columns i))

  ;; 1st ret val: next cols
  ;; 2nd ret val: resetted col index
  (define (adjoin-column column-index column-indices)
    (if (null? column-indices)
        (values (list column-index)
                #f)
        (let* ((column (get-column column-index))
               (this-column-index (car column-indices))
               (this-column (get-column this-column-index)))
          (cond
           ((column-above? this-column column)
            (values (cons column-index column-indices)
                    this-column-index))
           ((column-parallel? this-column column)
            (values (cons column-index (cdr column-indices))
                    this-column-index))
           (else (adjoin-column column-index (cdr column-indices)))))))

  (define (calc-resetted-list)
    (let ((len (vector-length columns)))    
      (let rec ((i 0)
                (cols '()))
        (if (= i len)
            '()
            (let ((column (get-column i)))
              (call-with-values
                  (lambda ()
                    (adjoin-column i cols))
                (lambda (next-cols resetted-column-index)
                  (cons resetted-column-index
                        (rec (+ i 1)
                             next-cols)))))))))
  (list->vector (calc-resetted-list)))

(define (calc-resetters resetteds)
  (let* ((len (vector-length resetteds))
         (resetters (make-vector len '())))
    (define (push! resetter column-index)
      (vector-set! resetters column-index
                   (cons resetter (vector-ref resetters column-index))))
    (do ((i 0 (+ i 1)))
        ((= i len) resetters)
      (let ((column-resetted (vector-ref resetteds i)))
        (if column-resetted
            (push! i column-resetted))))))

(define (make-struct lst)
  `(struct ,@lst))

(define (make-struct-or-singleton lst)
  (if (null? (cdr lst))
      (car lst)
      (make-struct lst)))

(define (struct? x)
  (and (pair? x)
       (eq? (car x) 'struct)))

(define (struct-members struct)
  (cdr struct))

(define (make-union lst)
  `(union ,@lst))

(define (union? x)
  (and (pair? x)
       (eq? (car x) 'union)))

(define (union-members union)
  (cdr union))

(define members-vector data1)
(define columns (calc-columns members-vector))
(define resetteds (calc-resetted-columns columns))
(define resetters (calc-resetters resetteds))

(define (get-column-members i)
  (let ((bgn (let ((this-column (vector-ref columns i)))
                    (column-top-member-index this-column)))
        (end (let ((last-column-index (- (vector-length columns) 1)))
               (if (= i last-column-index)
                   (vector-length members-vector)
                   (let ((next-column (vector-ref columns (+ i 1))))
                     (column-top-member-index next-column))))))

    (define (nth-member i)
      (vector-ref members-vector i))
    
    (let rec ((i bgn))
      (if (= i end)
          '()
          (cons (nth-member i)
                (rec (+ i 1)))))))

(define (split-members-at-offset members offset)
  (let rec ((lst members))
    (let ((first-member (car lst)))
      (if (= (mb-offset first-member) offset)
          (values '() lst)
          (call-with-values
              (lambda ()
                (rec (cdr lst)))
            (lambda (uncollected remain)
              (values (cons first-member uncollected)
                      remain)))))))

(define (get-column index)
  (vector-ref columns index))

(define (get-column-top-offset index)
  (column-top-offset (get-column index)))

(define (get-column-resetters index)
  (vector-ref resetters index))

(define (collect-struct members resetters)
  
  (define (make-member-list)
    (call-with-values
        (lambda ()
          (split-members-at-offset
           members
           (column-top-offset (get-column (car resetters)))))
      (lambda (collected remain)
        (append collected
                (list (collect-union remain resetters))))))
  
  (if (null? resetters)
      (make-struct members)
      (make-struct (make-member-list))))

(define (collect-union members resetters)
  (define start-offset (get-column-top-offset (car resetters)))
  (define (make-member-list)
    (cons (collect-struct members (cdr resetters))
          ;; ? FIXME: try recurse using column index rather than resetters
          (let rec ((r resetters))
            (let* ((next-column-index (car r))
                   (c2 (get-column next-column-index))
                   (m2 (get-column-members next-column-index))
                   (r2 (get-column-resetters next-column-index)))
              (if (and (pair? r2)
                       (= (get-column-top-offset (car r2)) start-offset))
                  (cons (collect-struct m2 (cdr r2))
                        (rec r2))
                  (list (collect-struct m2 r2)))))))
  (make-union (make-member-list)))

(define (print x)
  (define (inc-indent s)
    (string-append s "    "))
  (define (print-struct-or-union x indent)
    (display indent)
    (display (car x))
    (newline)
    (let ((sub-indent (inc-indent indent)))
      (for-each (lambda (y)
                  (dispatch-print y sub-indent))
                (cdr x))))
  (define (print-member m indent)
    (display indent)
    (display "+")
    (display (mb-offset m))
    (display " ")
    (display (mb-name m))
    (newline))
  (define (dispatch-print x indent)
    (cond
     ((pair? x) (print-struct-or-union x indent))
     ((vector? x) (print-member x indent))))
  (dispatch-print x ""))

;; Part II

(define (offset-of x)
  (cond
   ((struct? x)
    (struct-offset x))
   ((union? x)
    (union-offset x))
   (else
    (mb-offset x))))

(define (struct-offset struct)
  (offset-of (car (struct-members struct))))

(define (union-offset union)
  (offset-of (car (union-members union))))

(define (split-before-last lst)
  (let rec ((lst lst))
    (let ((first (car lst)))
      (if (null? (cdr lst))
          (values '() first)
          (call-with-values
              (lambda ()
                (rec (cdr lst)))
            (lambda (before last)
              (values (cons first before)
                      last)))))))

;; NOTE: unpacked structs may do some aligning, which could also cause (1)
;; FIXME:
;;   instead of checking equality,
;;   check last-child-bottom-offset < offset < this-child-offset
;;     (it can't be first child)
;;   [add array of bytes before to ensure]
(define (split-children-at-offset children offset)
  (let rec ((lst children))
    (if (null? lst)
        (values '() '())
        (let* ((first-child (car lst))
               (first-child-offset (offset-of first-child)))
          (cond
           ((= first-child-offset offset)
            (values '() lst))
           ((> first-child-offset offset) ; can't split! (1)
            (values lst '()))
           (else
            (call-with-values
                (lambda ()
                  (rec (cdr lst)))
              (lambda (uncollected remain)
                (values (cons first-child uncollected)
                        remain)))))))))

;; FIXME: postprocess-* functions won't accept empty struct/unions now.

;; returns
;;   val1 : max bottom offset
;;   val2 : [modified (with sth added)] members
(define (postprocess-struct-part1 struct)
  (call-with-values
      (lambda ()
        (split-before-last (struct-members struct)))
    (lambda (members last)
      (if (union? last)
          (call-with-values
              (lambda ()
                (postprocess-union-with-cut last))
            (lambda (max-bottom-offset union2 members-cut)
              (values max-bottom-offset
                      (append members
                              (list union2)
                              members-cut))))
          ;; if not union, then it must be ordinary member
          (values (mb-bottom-offset last)
                  (struct-members struct))))))

(define (postprocess-struct-without-cut struct)
  (call-with-values
      (lambda ()
        (postprocess-struct-part1 struct))
    (lambda (max-bottom-offset members)
      (values max-bottom-offset
              (make-struct-or-singleton members)))))

(define (postprocess-struct-with-cut struct offset)
  (call-with-values
      (lambda ()
        (postprocess-struct-part1 struct))
    (lambda (max-bottom-offset members)
      ;; SUGGESTION:
      ;;   check offset > max-bottom-offset ==>
      ;;     part1 = members AND part2 = ()
      (call-with-values
          (lambda ()
            (split-children-at-offset members offset))
        (lambda (part1 part2)
          (values max-bottom-offset
                  (make-struct-or-singleton part1)
                  part2))))))

(define (postprocess-union-with-cut union)
  (define (postprocess)
    (let rec ((lst (union-members union))
              (max-bottom-offset 0))
      (let ((first-struct (car lst)))
        (if (null? (cdr lst))
            (call-with-values
                (lambda ()
                  (postprocess-struct-with-cut first-struct max-bottom-offset))
              (lambda (max-bottom-offset2 member members-cut)
                (values (max max-bottom-offset
                             max-bottom-offset2)
                        (list member)
                        members-cut)))
            (call-with-values
                (lambda ()
                  (postprocess-struct-without-cut first-struct))
              (lambda (max-bottom-offset2 member)
                (call-with-values
                    (lambda ()
                      (rec (cdr lst)
                           (max max-bottom-offset max-bottom-offset2)))
                  (lambda (max-bottom-offset3 members members-cut)
                    (values max-bottom-offset3
                            (cons member members)
                            members-cut)))))))))
  (call-with-values
      postprocess
    (lambda (max-bottom-offset members members-cut)
      (values max-bottom-offset
              (make-union members)
              members-cut))))

;; TODO:
;;   write `postprocess-union-without-cut'
;;   this function won't work specially for last member of the union.

(define (demo-struct-1)
  (collect-struct (get-column-members 0)
                  (get-column-resetters 0)))

(define (demo-struct-2)
  (call-with-values
      (lambda () (postprocess-struct-without-cut (demo-struct-1)))
    (lambda (max-bottom-offset struct)
      ;; WARN: `struct' could be ordinary member
      struct)))

(define (demo-half)
  (print (demo-struct-1)))

(define (demo)
  (print (demo-struct-2)))

;; ,load F:\GuBigCollect\P09_StructCollectDemo\demo.scm
;; ,trace postprocess-struct-part1
;; ,trace postprocess-struct-with-cut
;; ,trace postprocess-struct-without-cut
;; ,trace postprocess-union-with-cut

;; PLEASE:
;;   help me test this algorithm!
;;     try write your test cases (dataX) after `data4' and modify this line:
;;       (define members-vector data1)
