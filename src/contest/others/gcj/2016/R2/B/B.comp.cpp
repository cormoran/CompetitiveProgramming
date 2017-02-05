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
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl
// vector
template<class T> ostream& operator << (ostream &os , const vector<T> &v) {
    for(const T &t : v) os << "\t" << t; return os << endl;
}
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) {
    return os << "<" << v.first << " " << v.second << ">";
}


double solve2(vector<double> &D) {
    //debug(D);
    vector<double> P[2];
    rep(i, 2) P[i].resize(D.size() + 1);
    P[0][0] = 1;
    rep(i, D.size()) {
        fill(all(P[(i+1)%2]), 0);
        rep(j, i+2) {
            if(j > 0) P[(i+1)%2][j] += P[i%2][j-1] * D[i];
            P[(i+1)%2][j] += P[i%2][j] * (1 - D[i]);            
        }
        //debug(P[(i+1)%2]);
    }
    return P[D.size() % 2][D.size() / 2];
}

bool solve(int t) {
    int N, K; cin >> N >> K;
    vector<double> D(N); cin >> D;
    double ans = 0;    
    rep(i, 1 << 16) {
        if(__builtin_popcount(i) == K) {
            vector<double> DD;
            rep(j, N) {
                if((1 << j) & i) DD.push_back(D[j]);
            }
            if(DD.size() == K) ans = max(ans, solve2(DD));
        }
    }
    printf("Case #%d: %.10lf\n", t, ans);
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);    
    int T; cin >> T;
    int t = 1;
    while(t <= T) {
        solve(t++);
    }
    return 0;
}
