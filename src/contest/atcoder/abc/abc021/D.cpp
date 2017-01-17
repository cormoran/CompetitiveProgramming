/*
  ABC021 D 多重ループ
  Q :
  入力 1 <= N,K <= 10^5 に対し,
  1<=a1<=a2,...,ak<=N となるa1...akの整数組を求める

  A :
  Nこの中からK個選ぶ重複組み合わせを計算する
  ( n H k = n+k-1 C k = n+k-1 C n-1 )
 */

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cassert>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

template<typename T>
class ModInt{
  public:
    static const T MOD = 1000000007LL; 
    T x;
    ModInt():x(0){};
    ModInt(T x_){
        x_%=MOD;
        if(x_<0)x_+=MOD;
        x=x_;
    }
    ModInt& operator += (const ModInt &l){x+=l.x;if(x>=MOD)x-=MOD;return *this;};
    ModInt& operator -= (const ModInt &l){x-=l.x;if(x<0)x+=MOD;return *this;}
    ModInt& operator *= (const ModInt &l){x=x*l.x%MOD;return *this;}
    ModInt operator +(const ModInt &l)const{return ModInt(x+l.x);}
    ModInt operator -(const ModInt &l)const{return ModInt(x-l.x);}
    ModInt operator *(const ModInt &l)const{return ModInt(x*l.x);}

    static ModInt pow(const ModInt &n,T r){
        if(r==0)return 1;
        ModInt ret=pow(n,r/2);
        ret=ret*ret;
        if(r%2!=0)ret= ret*n;
        return ret;
    }
    static ModInt inverse(const ModInt &n){return pow(n, MOD-2);}

    static ModInt factorial(const ModInt &n){
        T ret =1;
        for(T i=n.x;i>1;i--){ret*=i;}
        return ModInt(ret);
    }
    
    friend std::ostream& operator << (std::ostream& os,ModInt& a){os<<a.x;return os;}
    friend std::istream& operator >> (std::istream& is,ModInt& a){is>>a.x;return is;}
};

//Combination
ll nCk(ll n,ll k){
    vector<ModInt<ll>> fact(n+1);
    fact[0]=1;
    for(int i=1;i<=n;i++){
        fact[i]=fact[i-1]*i;
    }

    return (fact[n] * ModInt<ll>::inverse(fact[k]*fact[n-k])).x;
}

//Homogeneous product : 重複組み合わせ
ll NHK(ll n,ll k){
    return nCk(n+k-1,n-1);
}

int main()
{
    int N,K;cin>>N>>K;
    cout <<NHK(N,K)<<endl;
    return 0;
}
