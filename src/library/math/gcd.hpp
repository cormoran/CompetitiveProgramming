#pragma once

template<typename T>
T gcd(T a,T b){
    T c=a,d=b,r;
    do{r=c%d;c=d;d=r;}while(r);
    return c;
}

template<typename T>
T lcm(T a,T b){return a*b/gcd(a,b);}

//ax + by = gcd(a,b)
template<typename T>
T ext_gcd(T a,T b,T &x,T &y){
    if(b==0){x=1;y=0;return a;}
    T d = ext_gcd(b, a%b,y,x);
    y-=a/b*x;
    return d;
}
