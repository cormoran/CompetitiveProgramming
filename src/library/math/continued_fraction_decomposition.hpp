#ifndef CONTINUEDFRACTIONDECOMPOSITION_HPP
#define CONTINUEDFRACTIONDECOMPOSITION_HPP

// 連分数展開
// 連分数分解

#include<vector>
using namespace std;
typedef long long ll;

//begin
template<typename T>
T gcd(T a,T b){
    T c=a,d=b,r;
    do{r=c%d;c=d;d=r;}while(r);
    return c;
}

template<typename T>
void reduce_fraction(T &p,T &q){
    T g = gcd(p,q);
    p /= g; q /= g;
}

// 連分数展開
//a0 a1 a2 .... が入った配列を返す
//末尾は 4 とかになっている(3+1/1とかしないってこと)
vector<ll> ContinuedFractionDecomposition(ll p,ll q){
    reduce_fraction(p, q);
    vector<ll> ret;
    while(p>1){
        ret.push_back(p/q);
        p = p % q;
        swap(p,q);
    }
    return ret;
}

//末尾が1になるまで展開する
vector<ll> ContinuedFractionDecompositionDeepVer(ll p,ll q){
    reduce_fraction(p, q);
    vector<ll> ret;
    while(p>1){
        ret.push_back(p/q);
        p = p % q;
        swap(p,q);
    }
    if(ret.size() > 0 and ret.back() > 1){
        ll t = ret.back() -1 ;
        ret.pop_back();
        ret.push_back( t );
        ret.push_back( 1 );
    }
    return ret;
}
//end

#endif
