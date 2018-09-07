#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ull = unsigned long long;
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<unsigned int> A(N), B(N);
    //cin >> A >> B;
    rep(i, N) A[i] = i;
    rep(i, N) B[i] = i;
    unsigned int sum = 0;
    rep(i, N) {
        rep(j, N) sum ^= A[i] + B[j];
    }
    cout << sum << endl;
    return 0;
}
