#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<tuple>
#include<numeric>
#include<sstream>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
#define rep(i,j) for(int i=0;i<(int)(j);i++)
#define repeat(i,j,k) for(int i=(j);i<(int)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>
ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}

template<typename T>
istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R>
void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}

ll getDivisor(ll n) {
    repeat(i, 2, sqrt(n) + 1) {
        if(n % i == 0) return i;
    }
    return n;
}

string asBin(ll n) {
    stringstream ss;
    while(n) {
        ss << n % 2 ;
        n /= 2;
    }
    string res = ss.str();
    reverse( all(res) );
    return res;
}

bool solve(){
    int N, J; cin >> N >> J;
    for(uint32_t i = 0; i < (1 << (N-1)) ; i++) {
        uint32_t num = (1 << (N-1)) | (i << 1) | 1 ;
        vector<ll> sum(11);
        rep(j, N) {
            if(num & (1 << j)){
                for(ll base = 2; base <= 10; base++) {                
                    sum[base] += pow(base, j);
                }
            }
        }
        vector<ll> divisors;
        for(ll base = 2; base <= 10 and J > 0; base++) {
            ll d = getDivisor(sum[base]);
            if(d != sum[base]) divisors.push_back(d);
            else break;
        }

        if(divisors.size() == 9) {
            cout << asBin(num);
            for(ll d : divisors) {
                cout << " " << d;
            }
            cout << endl;
            J--;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    int T; cin >> T;
    cout << "Case #1:" << endl;
    solve();
    return 0;
}
