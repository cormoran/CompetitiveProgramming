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
        int T; cin >> T;
        rep(t, T) {
            int S; cin >> S;
            vector<int> D(S), A(S), B(S);
            rep(i, S) cin >> D[i] >> A[i] >> B[i];
            vector<int> DA(S + 1, -INF), DB(S + 1, -INF);
            rep(i, S) {
                DA[i] = D[i] + A[i];
                DB[i] = D[i] - B[i];
            }

            vector<int> da_next(S, -1), db_next(S, -1);
            auto calc_next = [&] (vector<int> &next, const vector<int> &arr) {
                rep(i, S) {
                    if(next[i] < 0) {
                        int j = i + 1; while(j < S and arr[j] == arr[i]) j++;
                        repeat(k, i, j) next[k] = j;
                    }
                }
            };
            calc_next(da_next, DA);
            calc_next(db_next, DB);

            map<int, int> cnt;
            vector<map<pii, int>> jump(S);
            set<pii> used;
            rep(i, S) {
                int j = da_next[i];
                int k = j == S ? j : db_next[j];
                int N = DA[i], M = DB[j];
                if(jump[i].count(pii(N, M))) k = jump[i][pii(N, M)];
                vector<int> pos;
                while(k < S and (DA[k] == DA[i] or DB[k] == DB[j])) {
                    pos.push_back(k);
                    if(DA[k] == DA[i]) k = da_next[k];
                    else if(DB[k] == DB[j]) k = db_next[k];
                }
                for(int p : pos) jump[p][pii(N, M)] = k;
                if(used.count(pii(i, k))) continue;
                cnt[k - i]++;
                used.insert(pii(i, k));
            }
            rep(i, S) {
                int j = db_next[i];
                int k = j == S ? j : da_next[j];
                int M = DB[i], N = DA[j];
                if(jump[i].count(pii(N, M))) k = jump[i][pii(N, M)];
                vector<int> pos;
                while(k < S and (DB[k] == DB[i] or DA[k] == DA[j])) {
                    pos.push_back(k);
                    if(DB[k] == DB[i]) k = db_next[k];
                    else if(DA[k] == DA[j]) k = da_next[k];
                }
                for(int p : pos) jump[p][pii(N, M)] = k;
                if(used.count(pii(i, k))) continue;
                cnt[k - i]++;
                used.insert(pii(i, k));
            }
            pii ans = pii(-1, -1);
            for(auto p : cnt) set_max<pii>(ans, p);
            cout << "Case #" << t + 1 << ": " << ans.first << " " << ans.second << endl;
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
