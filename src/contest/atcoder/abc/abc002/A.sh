#!/bin/bash
read a b
if [ $a -gt $b ]
then
    echo $a
else
    echo $b
fi
exit 0
