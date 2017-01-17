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

    vector<int> ans(N);

    repeat(i, 1, N+1) {
        vector<int> sum(N);
        int max_key = T[0];
        rep(j, N) {
            sum[T[j]]++;
            if(j - i >= 0) {
                
            }
            if((sum[max_key] == sum[T[j]] and max_key > T[j])
               or sum[max_key] > sum[T[j]]) {                
                max_key = T[j];                
            }
            ans[max_key]++;
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
