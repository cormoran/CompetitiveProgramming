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
// QueryFunc   : 演算子
// UpdateFunc  : (以前の値, 適用する値) => 新しい値
// query_unit  : QueryFuncの単位元
template<class T, class QueryFunc, class UpdateFunc, T query_unit>
class SegmentTree {
  public:
    int n;
    vector<T> data;
    QueryFunc qf;
    UpdateFunc uf;
    SegmentTree(int nn, T init) : n(1) {
        while(n < nn) n *= 2;
        data.resize(2 * n - 1, query_unit);
        fill(begin(data) + n - 1, end(data), init);
        for(int i = n - 2; i >= 0; i--) {
            data[i] = qf(data[left_child(i)], data[right_child(i)]);
        }
    }
    SegmentTree(vector<T> init) : n(1) {
        int nn = init.size();
        while(n < nn) n *= 2;
        data.resize(2 * n - 1, query_unit);
        copy(begin(init), end(init), begin(data) + n - 1);
        for(int i = n - 2; i >= 0; i--) {
            data[i] = qf(data[left_child(i)], data[right_child(i)]);
        }
    }
    //index k in [0, n) の値を val に更新
    void update(int k, T val) {
        assert(0 <= k and k < n);
        k += n - 1;
        data[k] = uf(data[k], val);
        while(k > 0) {
            k = parent(k);
            data[k] = qf(data[left_child(k)], data[right_child(k)]);
        }
    }
    T query(int a) const {
        return query(a, a + 1);
    }
    // [a, b) 
    T query(int a, int b) const {
        assert(0 <= a and a < b and b <= n);
        return query(a, b, 0, 0, n);
    }
  private:
    //[a, b) のクエリ, nowは今の場所, [l,r)は見ている場所
    T query(int a, int b, int now, int l, int r) const {
        if( out_of_range(a, b, l, r) ) return query_unit;
        if( within_range(a, b, l, r) ) return data[now];
        else { // cross range
            T vleft = query(a, b, left_child(now), l, (l + r) / 2);
            T vright = query(a, b, right_child(now), (l + r) / 2, r);
            return qf(vleft, vright);
        }
    }
    static bool out_of_range(int a, int b, int l, int r) { return r <= a or b <= l; }
    static bool within_range(int a, int b, int l, int r) { return a <= l and r <= b; }
    static int left_child(int i) { return i * 2 + 1; }
    static int right_child(int i) { return i * 2 + 2; }
    static int parent(int i) { return (i - 1) / 2; }
};

// -----------------------------------------------------------------------

template <class T> struct Min {
    T operator() (const T& x, const T& y) const { return min(x, y); }
};
template <class T> struct Max {
    T operator() (const T& x, const T& y) const { return max(x, y); }
};
template <class T> struct OverWrite {
    T operator() (const T& x, const T& y) const { return y; }
};


template<class T, T MINF>
using RangeMaximumQuery = SegmentTree<T, Max<T>, OverWrite<T>, MINF>;

struct P {
    int x;
    int y;
};
istream& operator >> (istream &is , P &p) { return is >> p.x >> p.y; }
ostream& operator << (ostream &os , const P &p) { return os << "(" << p.x << "," << p.y << ")"; }

map<int, int> compress(vector<int> &x) {
    map<int,int> zip;
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    for(int i = 0; i < x.size(); i++){
        zip[x[i]] = i;
    }
    return zip;
}


class Solver {
  public:
    ll solve2(int sx, int ex, P s, P e, vector<P> &S, int y_size) {
        RangeMaximumQuery<ll, 0LL> query(y_size, 0LL);
        for(int i = S.size() - 1; i >= 0; i--) {
            if(S[i].x > e.x) continue;
            if(S[i].x < s.x) break;
            if(s.y <= S[i].y and S[i].y <= e.y) {
                ll v = query.query(S[i].y, y_size);
                query.update(S[i].y, v + 1);
            }
        }
        return query.query(s.y, y_size);
    }
    
    bool solve() {
        P s, e; cin >> s >> e;
        ll N; cin >> N;
        
        if(s.x > e.x) swap(s, e);
        bool reverse_y = e.y < s.y;
        if(reverse_y) {
            s.y *= -1;
            e.y *= -1;
        }
        ll dx = e.x - s.x;
        ll dy = e.y - s.y;
        
        vector<int> ys = {s.y, e.y};
        ys.reserve(N + 2);
        vector<P> S;
        S.reserve(N);
        rep(i, N) {
            P ss; cin >> ss;
            if(reverse_y) ss.y *= -1;
            if(s.x <= ss.x and ss.x <= e.x and s.y <= ss.y and ss.y <= e.y) {                
                ys.push_back(ss.y);
                S.push_back(ss);
            }
        }
        double ans = (dx + dy) * 100.0;
        map<int, int> map_y = compress(ys);
        auto map = [&] (P &a) { a.y = map_y[a.y]; };
        map(s); map(e);
        rep(i, S.size()) map(S[i]);
        
        sort(all(S), [](P &a, P &b) { return a.x < b.x; });
        ll num = solve2(s.x, e.x, s, e, S, map_y.size());
        const double half_round = 2 * M_PI * 10 / 2.0 - 20.0;
        {
            if(num == dx + 1 || num == dy + 1) {
                ans += half_round;
                num--;
            }
            ans -= num * 20.0;
            ans += 2 * M_PI * 10.0 / 4.0 * num;
        }
        printf("%.15lf\n", ans);
        return 0;
    }
};

int main() {
    Solver s;
    s.solve();
    return 0;
}
