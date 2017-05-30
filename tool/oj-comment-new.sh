#!/usr/bin/env bash

MYPWD=$PWD

cd `dirname $0`/../
ROOT=$PWD/src/

if [[ $MYPWD =~ ${ROOT}contest.* ]]
then
    filename=${MYPWD#$ROOT}/comment.md
    hugo new $filename
else
    echo "you should run this script in '$ROOT'"
fi


