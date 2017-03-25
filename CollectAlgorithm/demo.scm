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
          (mb 16 "i")
	  ;;
	  (mb 20 "j")
          (mb 24 "k")
          (mb 24 "l")
          (mb 28 "m")
          (mb 28 "n")
          (mb 32 "o")
          (mb 24 "p")
          (mb 28 "q")
          (mb 36 "r")
	  ))

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

(define data5
  (vector (mb 0 "a")
	  (mb 4 "b")
	  (mb 8 "c")
	  (mb 0 "d")
	  (mb 4 "e")
	  (mb 8 "f")
	  (mb 12 "g")))

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

(define (get-column-head-point index return)
  (return (get-column-members index)
	  (get-column-resetters index)))

(define (is-n? members resetters) ;; otherwise is an `h'
  (and (pair? resetters)
       (= (get-column-top-offset (car resetters)) (mb-offset (car members)))))

(define (collect-g members resetters)
  (if (is-n? members resetters)
      (collect-union members resetters)
      (collect-struct members resetters)))

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

  ;; 把collect-union的条件拆到了这里
  ;; 这样更明显
  (if (is-n? members resetters)
      (set! resetters (cdr resetters)))

  (if (null? resetters)
      (make-struct members)
      (make-struct (make-member-list))))

(define (collect-union members resetters)
  (define (make-member-list)
    (let rec ((members members)
	      (resetters resetters))
      (cons (collect-struct members resetters)
	    (if (is-n? members resetters)
		;; 沿着这列的resetters继续，这会找到reset它的第一列，相当于水平向右平移
		;; 借助了resetter的传递关系。这一列的第一个resetter→下一列→下一列的第一个resetter→…
		;; 每列第一个resetter，是最后一个加入的
		;; 而剩下的resetters，必然属于本struct
		(get-column-head-point (car resetters) rec)
		'()))))
  (make-union (make-member-list)))

;; 一个从未被触过的列，它的members和resetters是根据列号就能获取到的
;; 这启发我们，怎样获得表示列头那一点的ResetPointNode

;; 如何表示ResetPointNode?
;; (members resetters) --> 是的!交给collect-*函数的参数，正好可以表示ResetPointNode
;; OR
;; (column-index member-index resetters)
;;   resetters甚至可以省略

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
	    ;; 一种可能是，被切的位置恰好最后一项的union中
	    ;;       或者，被切的位置在最后一项之后
	    ;; 没办法，只能把切点移动到这一项后
	    ;; 也就相当于没有切割
            (split-children-at-offset members offset))
        (lambda (part1 part2)
          (values max-bottom-offset
                  (make-struct-or-singleton part1)
                  part2))))))

(define (postprocess-union-with-cut union)
  (define (postprocess)
    (let rec ((lst (union-members union))
              (max-bottom-offset 0))
      ;; 传递式的递归分析
      ;; max-bottom-offset
      ;;   通过rec --> 传到最后一项的处理，传递时求出前n-1项的最大bottom-offset，用于最后一项的切割
      ;;   返回 <-- 连带最后一项的，bottom-offset的最大值
      ;;              而这个值可以是最后一项struct的最后的union处理后的返回结果，同样来自这里
      ;;                      或者就是struct最后的正常（非union）项之后的offset（最终来自）
      ;; member <-- 每次积累一项struct，返回时收集
      ;;              对最后一项，只积累part1
      ;; members-cut <-- 从最后一项返回
      (let ((first-struct (car lst)))
        (if (null? (cdr lst))
	    ;; 如果这已经是union的最后一项了
	    ;; union的最后一项会是可切开的struct
            (call-with-values
                (lambda ()
		  ;; 此union之前几项的最大bottom offset
                  (postprocess-struct-with-cut first-struct max-bottom-offset))
              (lambda (max-bottom-offset2 member members-cut)
                (values (max max-bottom-offset
                             max-bottom-offset2)
                        (list member) ;; 对应切好的struct的part1
                        members-cut)))
	    ;; 否则，不能切开
	    ;; 对这个struct进行正常处理，即：对它最后一项的union进行后处理
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
  (get-column-head-point 0 collect-g))

(define (demo-struct-2)
  (call-with-values
      ;; FIXME: demo-struct-1 may be a union
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
