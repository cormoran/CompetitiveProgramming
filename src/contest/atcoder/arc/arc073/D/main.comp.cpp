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
    ll N, W_CAP; cin >> N >> W_CAP;
    vector<ll> W(N), V(N);
    rep(i, N) cin >> W[i] >> V[i];
    
    map<ll, vector<ll>> group_by_w;
    rep(i, N) group_by_w[W[i]].push_back(V[i]);

    for(auto &p : group_by_w) {
        sort(all(p.second), greater<ll>());
        p.second.insert(begin(p.second), 0);
        rep(i, p.second.size() - 1) p.second[i + 1] += p.second[i];
    }
    
    function<ll(decltype(group_by_w)::iterator, ll)> dfs = [&] (decltype(group_by_w)::iterator itr, ll left) {
        if(itr == end(group_by_w)) return 0LL;
        ll res = 0;
        rep(i, (*itr).second.size()) {
            auto itr2 = itr; itr2++;
            ll add_w = (*itr).first * i;
            if(left - add_w >= 0) {
                set_max(res, (*itr).second[i] + dfs(itr2, left - add_w));
            }
        }
        return res;
    };
    cout << dfs(begin(group_by_w), W_CAP) << endl;
    
    return 0;
}
