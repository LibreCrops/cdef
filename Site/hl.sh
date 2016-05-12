#!/usr/bin/env bash


#
# Copyright 2015 Gu Zhengxiong <rectigu@gmail.com>
#


CSS=sh_emacs.css
DEST=../../../../lost-sdk


source-highlight --src-lang=c --gen-references=inline \
                 --out-format=html5 \
                 --lang-def=../lang/c.lang --style-css-file=$CSS \
                 --header ../header.html --footer ../footer.html \
                 $* || exit 233


sed -ri 's/(href=".+?html)#[0-9]+/\1/g' *.html || exit 233


rm -rf $DEST/files || exit 233
mkdir -p $DEST/files || exit 233
mv *.html $DEST/files || exit 233
../index.py $DEST/files


# sed -ri 's/ntdll\.h\///g' $OUT/*.html || exit 233
# sed -ri "s/$OUT\///g" $OUT/*.html || exit 233

# perl -00 -i -pe 's/\n<a.+//g' $OUT/*.html || exit 233
