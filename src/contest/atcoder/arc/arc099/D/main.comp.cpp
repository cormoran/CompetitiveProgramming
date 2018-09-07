#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a >= b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;


class Solver {
  public:
    ll S(ll n) {
        ll res = 0;
        while(n > 0) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
    double f(ll n) {
        return (double)n / S(n);
    }
    bool solve() {
        vector<pair<double, ll>> p;
        repeat(i, 1, 10000000) {
            p.emplace_back(f(i), i);
            // cout << p.back().first << " " << p.back().second << endl;
        }
        double m = INFL;
        vector<string> true_ans;
        for(int i = p.size() - 1; i >= 0; i--) {
            if(set_min(m, p[i].first)) {
                true_ans.push_back(to_string(p[i].second));
            }
        }
        reverse(all(true_ans));
        vector<string> ans;
        int N; cin >> N;
        rep(i, 9) {
            ans.push_back(to_string(i + 1));
            if(--N == 0) break;
        }
        if(N > 0) rep(i, 9) {
                ans.push_back(to_string(i + 1) + "9");
                if(--N == 0) break;
            }
        if(N > 0) rep(i, 9) {
                ans.push_back(to_string(i + 1) + "99");
                if(--N == 0) break;
            }
        int x = 10;
        int y = 1;
        int z = 10;
        string s = "9";
        while(N > 0) {
            repeat(i, 10, x) {
                ans.push_back(to_string(i) + s);
                if(--N == 0) break;
            }
            int xx = x;
            while(xx > z) xx /= 10;
            if(N > 0) repeat(i, xx, 10) {
                    int xxx = x / 10;
                    string ss;
                    rep(j, y) ss.push_back('9');
                ans.push_back(to_string(i) + s + ss);
                if(--N == 0) break;
            }
            x += 10;
            s.push_back('9');
            if(x == 100) z *= 10;
            cerr << "---" << x << endl;
        }
        // rep(i, min(true_ans.size(), ans.size())) {
        //     if(true_ans[i] != ans[i]) {
        //         cout << true_ans[i] << " but " << ans[i] << endl;
        //     } else {
        //         //cout << ans[i] << endl;
        //     }
        // }
        int mn = 0;
        rep(i, ans.size()) {
            // if(f(stoll(ans[i])) < mn) {
            //     cout << "Err : " << ans[i] << endl;
            // }
            // mn = f(stoll(ans[i]));
            cout << ans[i] <<  endl;
        }
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Solver s;
    s.solve();
    return 0;
}
