#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cassert>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

double func(double A,double B,double C,double t){
    return A*t + B*sin(C*M_PI*t);
}

int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    double l=0,r=300;
    double f =200;
    while(abs(f-100)>10E-10){
        double t=(l+r)/2;
        if((f=func(A,B,C,t))>=100.0)r=t;
        else l=t;
    }

    printf("%.10f\n",r);
    
    return 0;
}
