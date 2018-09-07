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

    ll H, M, S; cin >> H >> M >> S;
    ll C1, C2; cin >> C1 >> C2;
    H %= 12;
    
    ll ds0 = S * 60 - (M * 60 + S);
    while(ds0 < 0) ds0 += 3600;
    ds0 %= 3600;
    ll min_s = (3600 * C1 - ds0) / 59 + 1;
    ll max_s = (3600 * (C1 + 1) - ds0) / 59 - ((3600 * (C1 + 1) - ds0) % 59 == 0);
    debug(ds0);
    debug(min_s);
    debug(max_s);

    ll dm0 = (M * 60 + S) * 60 - (H * 60 * 60 + M * 60 + S);
    while(dm0 < 0) dm0 += 60 * 60 * 60;
    dm0 %= 60 * 60 * 60;
    
    ll min_m = (60 * 60 * 60 * C2 - dm0) / 59 / 60 ; // need s != 0
    ll max_m = (60 * 60 * 60 * (C2 + 1) - dm0) / 59 / 60; // need s != 0
       
    debug(dm0);
    debug(min_m);
    debug(max_m);

    // min_s *= 12;
    // max_s *= 12;
    
    // min_s += start;
    // max_s += start;
    // min_m += start;
    // max_m += start;

    cout << max(min_s, min_m) << " ";
    cout << min(max_s, max_m) << endl; 
    
    return 0;
}
