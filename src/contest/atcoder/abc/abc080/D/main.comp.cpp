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

    int N, C; cin >> N >> C;
    int ans = 0;
    vector<int> used_cnt(31);
    using T = pair<double, int>;
    priority_queue<T, vector<T>, greater<T>> que;
    vector<tuple<double, double>> q[31];
    rep(i, N) {
        double s, t;
        int c;
        cin >> s >> t >> c;
        q[c].emplace_back(s, t);
    }
    rep(i, 31) sort(all(q[i]));
    rep(c, 31) {
        if(q[c].size() == 0) continue;
        auto prev = q[c][0];
        rep(i, q[c].size() - 1) {
            if(get<1>(prev) >= get<0>(q[c][i])) {
                get<1>(prev) = get<1>(q[c][i]);
            } else {
                que.emplace(get<0>(prev) - 0.5, c);
                que.emplace(get<1>(prev), -c);
                prev = q[c][i];
            }
        }
        que.emplace(get<0>(prev) - 0.5, c);
        que.emplace(get<1>(prev), -c);
    }
    while(que.size()) {
        auto p = que.top(); que.pop();
        int c = p.second;
        if(c > 0) used_cnt[c]++;
        else used_cnt[-c]--;
        set_max(ans, accumulate(all(used_cnt), 0));
    }
    cout << ans << endl;
    return 0;
}

