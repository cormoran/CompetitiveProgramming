/**
 * file   : B.cpp
 * date   : 2015-10-24
 */
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double n,m;
    cin>>n>>m;
    double nd = ((int)n%12) * 360 / 12.0;
    nd += m/60.0 * 360.0/12;    

    double md = m / 60.0 * 360;
    printf("%.9f\n",min(abs(nd-md),360-abs(nd-md)));
    return 0;
}
