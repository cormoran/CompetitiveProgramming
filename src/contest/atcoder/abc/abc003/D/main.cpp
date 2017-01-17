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

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)

class ModInt{
 public:
  //You can divide if MOD is prime number. 
  static const ll MOD = 1000000007LL; 
  long long x;
  ModInt(){};
  ModInt(ll x_):x((x_%MOD+MOD)%MOD){};
  static ModInt pow(const ModInt &n,ll r);
  static ModInt inverse(const ModInt &n);
  static ModInt inverse2(const ModInt &n);
  static ModInt factorial(const ModInt &n);
  ll c_val()const{return x;}
  ModInt operator +(const ModInt &l)const{return ModInt(x+l.x);}
  ModInt operator -(const ModInt &l)const{return ModInt(x-l.x);}
  ModInt operator *(const ModInt &l)const{return ModInt(x*l.x);}
  //warning : MOD needs to be prime.
  ModInt operator /(const ModInt &l)const{return ModInt((*this) * inverse(l));}
  ModInt operator /= (const ModInt &l)const{return (*this)/l;};
  friend std::ostream& operator << (std::ostream& os,const ModInt& a){os<<a.x;return os;}
  friend std::istream& operator >> (std::istream& is,ModInt& a){is>>a.x;return is;}
};

ModInt ModInt::pow(const ModInt &n, ll r){
  if(r==0)return 1;
  ModInt ret=pow(n,r/2);
  ret=ret*ret;
  if(r%2!=0)ret= ret*n;
  return ret;
}

ModInt ModInt::inverse(const ModInt &n){
  return pow(n, MOD-2);
}

ModInt ModInt::factorial(const ModInt &n){
  ModInt ret=1;
  int nn=n.c_val();
  while(nn>1){
    ret=ret*nn;
    nn-=1;
  }
  return ret;
}

int main()
{
  ll R,C,X,Y,D,L;
  cin>>R>>C>>X>>Y>>D>>L;
  if(X*Y!=D+L)return 0;


  
  cout << ModInt((C-Y+1)*(R-X+1))*ModInt::factorial(D+L)/(ModInt::factorial(D)*ModInt::factorial(L))<<endl;
  
  return 0;
}
