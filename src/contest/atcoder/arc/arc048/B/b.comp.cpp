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

bool solve() {
    int N; cin >> N;
    vector<pii> RH(N);
    vector<vector<int>> R(100001, vector<int>(3));
    vector<int> sum(100001);
    rep(i, N) {
        cin >> RH[i].first >> RH[i].second;
        RH[i].second--;
        R[RH[i].first][RH[i].second]++;
        sum[RH[i].first]++;
    }
    rep(i, sum.size() - 1) sum[i+1] += sum[i];
    
    rep(i, N) {
        int loose = N - sum[RH[i].first];
        int win = sum[RH[i].first - 1];
        vector<int> &g = R[RH[i].first];
        int my = RH[i].second;
        win += g[(my + 1) % 3];
        loose += g[(my + 2) % 3];
        int draw = g[my] - 1;
        cout << win << " " << loose << " " << draw << endl;
    }
    
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
