//  atcoder - abc034 - D  / 2016-03-12
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
using namespace std;

typedef long long ll;
typedef pair<int, int > pii;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}
template<typename T>istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R> void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}


bool solve(){
    int N, K; cin >> N >> K;
    vector<pair<int,int>> WP(N);
    rep(i, N)cin >> WP[i].first >> WP[i].second;

    double l = 0, r = 100;
    while( abs(r - l) > 1e-8 ){
        double m = (l + r) / 2;

        sort( all(WP) , [&](const pii a, const pii b){
                return (a.second - m) *  a.first > (b.second - m) *  b.first;
            });

        double sum = 0;
        vector<bool> used(N);
        int k = K;
        rep(i, K){
            if(not used[i]){
                sum += (WP[i].second - m) * WP[i].first;
                k--;
            }
        }
        (sum >= 0 ? l : r) = m;
    }

    printf("%.8f\n", l);
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
