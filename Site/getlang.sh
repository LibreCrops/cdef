#!/usr/bin/env bash


#
# Copyright 2015 Gu Zhengxiong <rectigu@gmail.com>
#


ROOT=/usr/share/source-highlight


mkdir -p lang

cp -n $ROOT/c.lang lang/

for i in $(cat $ROOT/c.lang | grep -oP '(?<=include ").+?(?=")')
do
    cp $ROOT/$i lang/

    for j in $(cat $ROOT/$i | grep -oP '(?<=include ").+?(?=")')
    do
        cp $ROOT/$j lang/

        for k in $(cat $ROOT/$j | grep -oP '(?<=include ").+?(?=")')
        do
            cp $ROOT/$k lang/
        done
    done
done
