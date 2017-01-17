#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
// vector
template<class T> ostream& operator << (ostream &os , const vector<T> &v) {
    for(const T &t : v) os << "\t" << t; return os << endl;
}
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}

bool check(int N, vector<int> &X, ll t) {
    ll pos = 1;
    for(ll x : X) {
        if(pos >= x) pos = max(pos, x + t + 1);
        else if(x - pos > t) return false;
        else {
            ll d = x - pos;            
            ll mx = max(x + (t - d) / 2, x + t - d * 2);
            pos = max(pos, mx + 1);
        }
    }
    return pos > N;
}


bool solve() {
    ll N, M; cin >> N >> M;
    vector<int> X(M); cin >> X;
    sort(all(X));

    ll l = -1, r = N * 2;
    while(l + 1 < r) {
        ll m = (l + r) / 2;
        if(check(N, X, m)) r = m;
        else l = m;
    }
    cout << r << endl;
    
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
