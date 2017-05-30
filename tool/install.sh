#!/usr/bin/env sh
target='~/.bash_rc'

if [ $# -ge 1 ]; then
    target=$1
fi

echo "append some alias to $target (you can change target by 1st arg)"
echo -n "ok? ok/y/yes >"
read OK
case $OK in
    "ok" | "y" | "yes" ) ;;
    * )
        echo "canceled"
        exit 0 ;;
esac

for f in ./*; do
    if [ `basename $f` != `basename $0` ]; then
        echo "alias `basename ${f%.*}`=`pwd`/$f"
        echo "alias `basename ${f%.*}`=`pwd`/$f" >> $target
    fi
done
