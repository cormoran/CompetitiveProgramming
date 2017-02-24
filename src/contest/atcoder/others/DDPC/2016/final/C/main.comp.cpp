#include<iostream>
#include<string>
#include<cassert>
#include<map>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

const int MOD = 1000000007;

// ()
map<int,ll> base(int K){
    if(K < 2) return { {0, 2} };
    else return { {0, 2}, {-2, 1}, {2, 1} };
}

// ( ... ) ( ... ) など
map<int,ll> merge(map<int,ll> &A, map<int,ll> &&B){
    map<int,ll> d;
    for(auto a : A){
        for(auto b : B){ // 括弧の並列では >K でもOK
            d[a.first + b.first] += a.second * b.second;
            d[a.first + b.first] %= MOD;
        }
    }
    return d;
}

// ( ( ... ) ( ... ) ) など
map<int,ll> wrap(map<int,ll> &A, int K){
    map<int,ll> d;
    map<int,ll> B = base(K);
    for(auto a : A){
        for(auto b : B){
            if( abs(a.first + b.first) <= K ){
                d[a.first + b.first] += a.second * b.second;
                d[a.first + b.first] %= MOD;
            }
        }
    }
    return d;
}

// S[now] から S[now]に対応する閉じ括弧まで
map<int,ll> calc(const string &S, int &now, int K){
    assert( S[now] == '(' );
    map<int,ll> d = { {0, 1} };
    bool flg = false;
    now++;
    while(S[now] != ')'){
        d = merge(d, calc(S,now, K));
        flg = true;
    }
    now++;
    return flg ? wrap(d, K) : base(K);
}

bool solve(){
    string S; cin >> S;
    int K; cin >> K;
    int now = 0;
    ll ans = 1;
    while(now < S.size()){
        map<int,ll> d = calc(S, now, K);
        ll partial = 0;
        for(auto a : d){
            if(abs(a.first) <= K){
                partial = (partial + a.second) % MOD;
            }
        }
        ans = ans * partial % MOD;
    }
    cout << ans << endl;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
