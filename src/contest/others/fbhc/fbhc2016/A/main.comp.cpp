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

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
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

int dist2(int x1,int y1, int x2, int y2){
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

bool solve(const int C){
    int N; cin >> N;
    vector<int> X(N),Y(N);
    rep(i,N) cin >> X[i] >> Y[i];
    ll ans = 0;
    rep(i,N){
        map<int,int> distance2;
        rep(j,N){
            if(i != j){
                int d2 = dist2(X[i], Y[i], X[j], Y[j]);
                distance2[d2]++ ;
            }
        }
        for(auto item : distance2){
            int num = item.second;
            ans += num * (num-1) /2;
        }
    }

    printf("Case #%d: %lld\n", C, ans);
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);

    int T; cin >> T;
    int C = 1;
    while( C <= T ) solve(C++);
    return 0;
}
