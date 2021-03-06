#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

typedef long long ll;

class ModInt{
 public:
  static const ll MOD = 1000000007LL;
  
  long long x;
  ModInt(){};
  ModInt(ll x_):x((x_%MOD+MOD)%MOD){};
  static const ModInt pow(const ModInt n,ll r);
  static const ModInt inverse(const ModInt n);  
  const ModInt operator +(const ModInt &l)const{return ModInt(x+l.x);}
  const ModInt operator -(const ModInt &l)const{return ModInt(x-l.x);}
  const ModInt operator *(const ModInt &l)const{return ModInt(x*l.x);}
  const ModInt operator += (const ModInt &l)const{return (*this)+l;};
  const ModInt operator -= (const ModInt &l)const{return (*this)-l;};
  const ModInt operator *= (const ModInt &l)const{return (*this)*l;};
  //MOD needs to be prime.
  const ModInt operator /(const ModInt &l)const{return ModInt((*this) * inverse(l));}
  const ModInt operator /= (const ModInt &l)const{return (*this)/l;};
  
  friend ostream& operator << (ostream& os,ModInt& a){os<<a.x;return os;}
  friend istream& operator >> (istream& is,ModInt& a){is>>a.x;return is;}
};

const ModInt ModInt::pow(const ModInt n, ll r){
  if(r==0)return 1;
  ModInt ret=pow(n,r/2);
  ret=ret*ret;
  if(r%2!=0)ret= ret*n;
  return ret;
}

const ModInt ModInt::inverse(const ModInt n){
  return pow(n, MOD-2);
}

int main()
{
  ModInt a,b,c;
  cin>>a>>b>>c;

  ModInt C=(b*c-a*c)/(b*a-b*c+a*c);
  ModInt R=(b*c-a*b)/(c*a-b*c+a*b);
  cout<<C<<" "<<R<<endl;
  
  return 0;
}
