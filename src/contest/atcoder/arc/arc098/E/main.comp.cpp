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
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;


class Solver {
  public:
    bool solve() {
        ll N, K, Q; cin >> N >> K >> Q;
        vector<ll> A(N); cin >> A;
        vector<ll> B = A;
        sort(all(B));
        B.erase(unique(B.begin(), B.end()), B.end());
        ll ans = INFL;

        for(ll mini : B) {
            ll cnt = 0;
            vector<ll> vv;
            rep(l, N) {
                while(l < N and A[l] < mini) l++;
                ll r = l;
                while(r < N and A[r] >= mini) r++;
                if(r - l + 1 >= K) {
                    cnt += r - l - K + 1;
                    vector<ll> v;
                    repeat(j, l, r) v.push_back(A[j]);
                    sort(all(v));
                    rep(j, r - l -  K + 1) vv.push_back(v[j]);
                }
                l = r;
            }
            //cerr << i << " ~ :" <<  cnt << " : " << mx << " - " << mini << endl;
            if(cnt >= Q) {
                sort(all(vv));
                ll mx = vv[Q - 1];
                assert(mx >= mini);
                if(vv[0] == mini) set_min<ll>(ans, mx - mini);
            }
        }
        assert(ans != INFL);
        cout << ans << endl;
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
