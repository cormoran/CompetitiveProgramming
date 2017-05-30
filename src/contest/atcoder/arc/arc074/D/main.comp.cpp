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
        int N; cin >> N;
        vector<int> A(N), B(N), C(N); cin >> A >> B >> C;
        vector<pii> Bl(2 * N), Br(2 * N);
        rep(i, N) {
            Bl[i] = make_pair(A[i], 1);
            Br[i] = make_pair(C[i], 1);
            Bl[i + N] = make_pair(B[i], -i);
            Br[i + N] = make_pair(B[i], -i);            
        }
        sort(all(Bl)); reverse(all(Bl));
        sort(all(Br));

        queue<pii> Aq, Bq;
        set<int> Ain, Bin;
        ll As = 0, Bs = 0;
        rep(i, N) {
            As += Bl[i].first;
            Bs += Br[i].first;
            if(Bl[i].second <= 0) Ain.insert(-Bl[i].second);
            if(Br[i].second <= 0) Bin.insert(-Br[i].second);
            Aq.push(Bl[i + N]);
            Bq.push(Br[i + N]);
        }
       
        ll ans = -(1LL << 60);
        vector<ll> Ass(N + 1), Bss(N + 1);
        rep(i, N) {
            Ass[N - i] = As;
            Bss[N - i] = Bs;
            if(Ain.count(N - i - 1)) {
                As -= B[N - i - 1];
                while(Aq.front().second <= 0 and -Aq.front().second > N - i - 1) Aq.pop();
                if(Aq.front().second <= 0) Ain.insert(Aq.front().second * -1);
                As += Aq.front().first; Aq.pop();                                         
            }
            if(Bin.count(i)) {
                Bs -= B[i];
                while(Bq.front().second <= 0 and -Bq.front().second < i) Bq.pop();
                if(Bq.front().second <= 0) Bin.insert(Bq.front().second * -1);
                Bs += Bq.front().first; Bq.pop();
            }
        }
        Ass[0] = As;
        Bss[0] = Bs;
        // debug(Ass); debug(Bss);
        rep(i, N + 1) set_max(ans, Ass[i] - Bss[N - i]);
        
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
