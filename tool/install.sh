#!/usr/bin/env bash
target='~/.bash_profile'

if [ $# -ge 1 ]; then
    target=$1
fi

here="$( cd "$(dirname "$0")"; pwd)"/bin

echo "append $here to PATH (write setting to $target)"
echo -n "ok? ok/y/yes >"
read OK
case $OK in
    "ok" | "y" | "yes" ) ;;
    * )
        echo "canceled"
        exit 0 ;;
esac
touch $target
echo "export PATH=$here:\$PATH" >> $target
