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
    int N, K; cin >> N >> K;
    vector<int> X(K);
    rep(i, K) {
        int y;
        cin >> X[i] >> y;
        X[i]--;
    }
    vector<int> AA(N); cin >> AA;
    rep(i, N) AA[i]--;
    vector<int> A(N);
    rep(i, N) A[AA[i]] = i;
    
    
    vector<int> bar(N);
    rep(i, N) bar[i] = i;

    rep(i, K) swap(bar[X[i]], bar[X[i] + 1]);    
    // debug(bar);
    vector<int> ans;
    rep(i, N) {
        // iを合わせる
        vector<int> tmp;
        repeat(j, i, N) if(A[i] == bar[j]) {
            for(int k = j - 1; k >= i; k--) {
                swap(bar[k + 1], bar[k]);
                tmp.push_back(k);
            }
            break;
        }
        ans.insert(ans.end(), all(tmp));        
    }
    // debug(bar);
    cout << ans.size() << endl;
    for(int a : ans) {
        cout << a + 1 << " " << a + 2 << endl;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
