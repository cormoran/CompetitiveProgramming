#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream&
operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream&
operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream&
operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    int max_i = -1;
    bool different = false;
    rep(i, N) {
        if(A[i] > B[i] and max_i < 0) max_i = i;
        if(max_i >= 0 and A[i] > B[i] and (B[max_i] > B[i])) max_i = i;
        different |= A[i] != B[i];
    }
    if(not different) {
        cout << 0 << endl;
        return 0;
    }
    assert(max_i >= 0);
    ll sum = 0;
    rep(i, N) if(i != max_i) sum += A[i];
    sum += A[max_i] - B[max_i];
    cout << sum << endl;
    return 0;
}
