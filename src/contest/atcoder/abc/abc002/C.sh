#!/bin/bash
read xa ya xb yb xc yc
x1=`expr $xb - $xa`
y1=`expr $yb - $ya`
x2=`expr $xc - $xa`
y2=`expr $yc - $ya`
ans2=`expr $x1 \* $y2 - $x2 \* $y1`
echo "scale=3; sqrt( ($ans2 / 2.0 ) ^2 )" | bc
exit 0
