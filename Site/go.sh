#!/usr/bin/env bash


#
# Copyright 2015 Gu Zhengxiong <rectigu@gmail.com>
#


if [[ $# -ne 1 ]]
then
    printf 'an argument where headers reside, please.\n'
    exit 233
fi


(cd "$1" && hl *.h)
