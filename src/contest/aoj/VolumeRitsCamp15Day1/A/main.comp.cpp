//  aoj -  - A  / 2016-03-06
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
typedef pair<ll,ll> pll;
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

double norm(double x, double y){
    return sqrt(x*x + y*y);
}

bool solve(){
    int N; cin >> N;
    int f[2], a[2], t[2], x[2], y[2];
    double ans_d[2] = {-1, -1};
    double ans_t[2] = {-1, -1};
    rep(i, N){
        cin >> f[i%2] >> a[i%2] >> t[i%2] >> x[i%2] >> y[i%2];
        if(i == 0) continue;
        if( t[i%2] == t[(i+1)%2] and a[i%2] != a[(i+1)%2] ){
            double d = norm(x[0] - x[1], y[0] - y[1]);
            if(abs(ans_d[t[0]] - d) < 1e-8){
                ans_t[t[0]] = min(ans_t[t[0]], (f[i%2] - f[(i+1)%2]) / 60.0);
            } else if(ans_d[t[0]] < d){
                ans_d[t[0]] = d;
                ans_t[t[0]] = (f[i%2] - f[(i+1)%2]) / 60.0;
            }

        }
    }
    rep(i, 2){
        printf("%.6f %.6f\n", ans_d[i], ans_t[i]);
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
