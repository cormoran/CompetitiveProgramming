#include<vector>
#include<iostream>
#include<map>
#include<set>

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
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;


class Solver {
  public:
    bool solve() {
        int n, m, k; cin >> n >> m >> k;
        vector<int> a(n); cin >> a;

        map<int, set<int>> xor_acc_to_index;
        vector<int> xor_acc(n + 1); // [r + 1] := xor of [0, r]
        xor_acc[0] = 0;
        xor_acc_to_index[0].insert(-1);
        rep(i, n) {
            xor_acc[i + 1] = xor_acc[i] ^ a[i];
            xor_acc_to_index[xor_acc[i + 1]].insert(i);
        }
        
        // cerr << "acc" << endl;
        // cerr << xor_acc << endl;
        /*
        vector<pair<pii, int>> queries;
        rep(q, m) {
            int l, r; cin >> l >> r;
            queries.push_back(make_pair(make_pair(l, r), q));
        }

        
        sort(all(queries));
        
        auto f = [&](int l, int r) -> ll {
            l--;
            static int l1 = 0, r1 = 0;
            ll ans = 0;
            // cerr << "[" << l << ", " << r << "]" << endl;
            auto cnt = [&] (int i) {
                int ik = xor_acc[i + 1] ^ k;
                // cerr << "[" << l << "," << i << "] : " << " find " << ik << endl; 
                int cnt = 0;
                for(auto itr = xor_acc_to_index[ik].rbegin(); itr != xor_acc_to_index[ik].rend() and *itr >= l1 - 1; itr++) {
                    if(*itr <= i) cnt++;
                }
                // cerr << "[" << l << "," << i << "] : " << cnt << endl; 
                return cnt;
            };
            int l2 = l1, r2 = r1;
            while(r2 > r) ans -= cnt(r2--);
            while(r2 < r) ans += cnt(r2++);
            while(l2 < l) ans -= cnt(l2++);
            while(l2 > l) ans += cnt(l2--);            
            l1 = l2;
            r1 = r1;
            return ans;
        };
        

        vector<ll> ans(m);
        rep(q, m) {
            int l = queries[q].first.first;
            int r = queries[q].first.second;
            int no = queries[q].second;
            ans[no] = f(l, r);
        }
        rep(i, m) cout << ans[i] << endl;
        
        return 0;
        */
        rep(q, m) {
            int l, r; cin >> l >> r;
            l--; // [l, r)
            ll ans = 0;
            // cerr << "[" << l << ", " << r << "]" << endl;
            repeat(i, l, r) {                
                int ik = xor_acc[i + 1] ^ k;
                // cerr << "[" << l << "," << i << "] : " << " find " << ik << endl; 
                int cnt = 0;
                for(auto itr = xor_acc_to_index[ik].rbegin(); itr != xor_acc_to_index[ik].rend() and *itr >= l - 1; itr++) {
                    if(*itr <= i) cnt++;
                }
                // cerr << "[" << l << "," << i << "] : " << cnt << endl; 
                ans += cnt;
            }
            cout << ans << endl;
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
