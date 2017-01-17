//#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<string>
#include<cmath>
#include<cassert>
#include<map>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

template<typename T>
T gcd(T a,T b){
    T c=a,d=b,r;
    if(a<b)swap(a,b);
    if(b==0)return a;
    do{r=c%d;c=d;d=r;}while(r);
    return c;
}

int main()
{
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    vector<int> A(n);
    rep(i,n){
        cin>>A[i];
    }
    sort(all(A));
    ll sum=0;
    ll num=0;
    rep(i,n){
        num += (A[i]*i-sum)*2;
        num += A[i];
        sum += A[i];
    }
    ll deno=n;
    ll g=gcd(deno,num);
    deno/=g;
    num/=g;

    cout<<num<<" "<<deno<<endl;
    
    return 0;
}
