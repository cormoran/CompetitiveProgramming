// #ifndef MY_LIBRARY
// #define MY_LIBRARY
// #include<iostream>
// using namespace std;
// #endif

//#pragma once
#include<iostream>


using namespace std;

template<typename T>
//ax + by = gcd(a,b)
T ext_gcd(T a,T b,T &x,T &y){
    if(b==0){x=1;y=0;return a;}    
    T d = ext_gcd(b, a%b,y,x);
    y-=a/b*x;
    return d;
}

int main(){
    int a,b;
    cin>>a>>b;
    int x,y;
    ext_gcd(a, b, x, y);
    printf("%d %d\n",x,y);
    return 0;
}
