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

template<typename T>
struct BIT {
    vector<T> data;
    BIT(size_t n) {
        data.resize(n + 1, 0);
    }
    //sum of [1, i]
    T sum(int i){
        assert(0 <= i);
        T s = 0;
        for(; i > 0; i -= i & -i) s += data[i];
        return s;
    }
    // sum of [i, j]
    T sum(int i,int j){
        assert(0 < i and i <= j);
        return sum(j) - sum(i - 1);
    }
    //add x to index i
    void add(int i, T x){
        assert(0 < i);
        for(; i < data.size(); i += i & -i) data[i] += x;
    }
    // seach min i such that sum(i) >= x
    int lower_bound(T x){
        int r = data.size() - 1, l = 0; // (l, r]
        while(r - l > 1){
            int m = (r + l) / 2;
            (sum(m) >= x ? r : l) = m;
        }
        return r;
    }
};

class Solver {
  public:
    bool solve() { 
        int N; cin >> N;
        ll D; cin >> D;
        vector<ll> G(N); cin >> G;
        vector<ll> sum(N + 1);
        rep(i, N) sum[i + 1] = sum[i] + G[i];
        BIT<int> bit(N + 5);

        map<int, vector<int>> positions;
        rep(i, N) positions[G[i]].push_back(i);
        vector<pii> sorted(N);
        rep(i, N) {
            sorted[i].first = G[i];
            sorted[i].second = i;
        }
        sort(all(sorted));
        reverse(all(sorted));
        set<int> used;
        used.insert(-1);
        used.insert(N);
        vector<int> ans;
        rep(foo, N) {
            int i = sorted[foo].second;
            if(used.count(i)) continue;
            auto e = used.lower_bound(i);
            auto s = e; s--;
            if(bit.sum(*s+2, *e) > 0) continue;
            //cerr << i << " " << *s << " " << *e << endl;
            
            ll w = sum[*e] - sum[*s + 1];
            //debug(w);
            int ok = 0;
            if(*s == -1 or w + D >= G[*s]) {
                w = sum[*e];
                ok++;
            }
            if(*e == N or w + D >= G[*e]) {
                ok++;
                w += sum[N] - sum[*e];
                if(*s == -1 or w + D >= G[*s]) {
                    ok++;
                }
            }

            if(ok >= 2) {
                ans.push_back(i + 1);
                //debug("o");
            } else {
                bit.add(*e - 1+1, 1);
                bit.add(*s+1, -1);

            }
            used.insert(i);
        }
        sort(all(ans));
        rep(i, ans.size()) {
            cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
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

