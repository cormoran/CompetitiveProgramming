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
    int N; scanf("%d", &N);
    vector<int> T(N);
    rep(i, N) {
        scanf("%d", &T[i]);
        T[i]--;
    }
    vector<map<int, int>> sum(N + 1);
    rep(i, N) {
        sum[i + 1] = sum[i];
        sum[i + 1][T[i]]++;
    }
    vector<int> ans(N);
    repeat(i, 1, N + 1) {
        rep(j, i) {
            int max_color, max_val = -1;
            for(auto p : sum[i]) {
                int key = p.first;
                int cnt = p.second - sum[j][key];
                if(cnt > max_val) {
                    max_color = key;
                    max_val = cnt;
                }
            }
            ans[max_color]++;
        }
    }
    rep(i, N - 1) printf("%d ", ans[i]);
    printf("%d\n", ans.back());
    
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
