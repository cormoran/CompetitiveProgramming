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

// T           : データ型
// UpdateFunc  : (以前の値, 適用する値) => 新しい値 結合性必要
// update_unit : UpdateFuncの単位元 (= 配列の初期値)
template<class T, class UpdateFunc, T update_unit>
class SegmentTree {
  public:
    int n; 
    vector<T> data;
    UpdateFunc uf;
    SegmentTree(int nn) : n(1) {
        while(n < nn) n *= 2;
        data.resize( 2 * n - 1, update_unit);
    }
    SegmentTree(vector<T> init) : n(1) {
        int nn= init.size();
        while(n < nn) n *= 2;
        data.resize( 2 * n - 1, update_unit);
        copy(begin(init), end(init), begin(data) + n - 1);
    }
    // get value of index(i)
    T query(int i) {
        assert(0 <= i and i < n);
        return query(i, 0, 0, n);
    }
    // apply f(_, v) to [a, b)
    void update(int a, int b, T v) {
        assert(0 <= a and a < b and b <= n);
        update(a, b, 0, 0, n, v);
    }
  private:
    // [a, b) 更新区間, i 今いるNode, [l, r) はNode[i]の担当区間
    void update(int a, int b, int i, int l, int r, T v) {
        if(out_of_range(a, b, l, r)) return;
        if(within_range(a, b, l, r)) data[i] = uf(data[i], v);
        else {
            // 遅延伝搬させる
            int m = (l + r) / 2;
            // 関係ない範囲は今までの値を流す
            if(l < a) { // l .. a .(r). b ..(r)
                update(l, a, left_child(i), l, m, data[i]);
                update(l, a, right_child(i), m, r, data[i]);
            }
            if(b < r) { // (l).. a .(l). b .. r
                update(b, r, left_child(i), l, m, data[i]);
                update(b, r, right_child(i), m, r, data[i]);
            }
            // 関係する範囲は今の値を合わせて流す
            update(a, b, left_child(i), l, m, uf(data[i], v));
            update(a, b, right_child(i), m, r, uf(data[i], v)); 
            data[i] = update_unit; // 子に全て流したから
        }
    }
    // index(a) の値を求める, 今node[i], 
    T query(int a, int i, int l, int r) {
        if(data.size() <= i) return update_unit;
        assert(l <= a and a < r);
        int m = (l + r) / 2;
        T v = a < m ? query(a, left_child(i), l, m) : query(a, right_child(i), m, r);
        return uf(v, data[i]); // 先に流しているのでvの方が古い値
    }
    static bool out_of_range(int a, int b, int l, int r) { return r <= a or b <= l; }
    static bool within_range(int a, int b, int l, int r) { return a <= l and r <= b; }
    static int left_child(int i) { return i * 2 + 1; }
    static int right_child(int i) { return i * 2 + 2; }
    static int parent(int i) { return (i - 1) / 2; }
};

template<class T, T INIT>
using RangeAddQuery = SegmentTree<T, plus<T>, INIT>;

class Solver {
  public:
    bool solve() { 
        int N; cin >> N;
        ll D; cin >> D;
        vector<ll> G(N); cin >> G;
        vector<ll> sum(N + 1);
        rep(i, N) sum[i + 1] = sum[i] + G[i]; 

        RangeAddQuery<ll, 0> seg(N + 1);

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
            if(used.count(i) or seg.query(i) > 0) continue;
            auto e = used.lower_bound(i);
            auto s = e; s--;
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
                seg.update(*s + 1, *e, 1);
                //debug("x");
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
