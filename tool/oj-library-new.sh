#!/usr/bin/env bash

if [ $# -ne 1 ]; then
    echo "error: no input title"
    echo "usage: <command> title"
    echo "-> title.md will created"
    exit 1
fi

MYPWD=$PWD

cd `dirname $0`/../
ROOT=$PWD/src/

if [[ $MYPWD =~ ${ROOT}library.* ]]
then
    filename=${MYPWD#$ROOT}/${1}.md
    hugo new $filename
else
    echo "you should run this script in '$ROOT'"
fi


