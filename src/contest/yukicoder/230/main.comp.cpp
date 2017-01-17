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
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << " " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

using Index = int;
template<typename Data>
class SegmentTree{
  public:
    int size; // 末端arrayのsize (2^k)
    vector<Data> data; // size -1 to end が末端
    SegmentTree(int n){
        size = 1;
        while(size < n) size *= 2;
        data.resize( 2 * size - 1, -1);
    }
    
    void update(Index a, Index b, Data val){
        update(a, b, 0, 0, size, val);       
    }

    // [a, b) に含まれるvalの数
    Data query(Index a, Index b, Data val){
        return query(a, b, 0, 0, size, val);
    }

  private:
    // [a, b) 更新区間, i 今いるNode, [l, r) はNode[i]の担当区間
    void update(Index a, Index b, Index i, Index l, Index r, Data val){
        if(val < 0 or data[i] == val) return;
        //cerr << "UPDATE 区間 [" << a << "," << b << "]" << " 今 " << i << " [" << l << "," << r << ") VAL" << val << endl;
        if(out_of_range(a, b, l, r)); // do nothing
        else if(in_range(a, b, l, r)) {
            data[i] = val;
        } else {
            Index m = (l + r) / 2;
            if(l < a) {
                update(l, a, left_child(i), l, m, data[i]);
                update(l, a, right_child(i), m, r, data[i]);
            }
            if(b < r) {
                update(b, r, left_child(i), l, m, data[i]);
                update(b, r, right_child(i), m, r, data[i]);
            }
            update(a, b, left_child(i), l, m, val);
            update(a, b, right_child(i), m, r, val);            
            data[i] = -1;
        }
    }
    
    Data query(Index a, Index b, Index i, Index l, Index r, Data val){
        Data ret = 0;
        if(out_of_range(a, b, l, r)) ret =  0;
        else if(data[i] >= 0) ret = data[i] == val ? min(b, r) - max(a, l) : 0;
        else if(is_leaf(i)) ret = data[i] == val;
        else {
            Index m = (l + r) / 2;
            ret =   query(a, b, left_child(i), l, m, val) + query(a, b, right_child(i), m, r, val);            
        }
        //cerr << "Q 区間 [" << a << "," << b << "]" << " 今 " << i << " [" << l << "," << r << ") SEARCH " << val << " DATA " << data[i] << " RET " << ret << endl;
        return ret;
    }
    // Nodeの担当[l, r) に対してクエリの区間[a, b)が...
    bool out_of_range(Index a, Index b, Index l, Index r) { return r <= a or b <= l; }
    bool in_range(Index a, Index b, Index l, Index r) { return a <= l and r <= b; }
    bool is_leaf(Index i) { return i >= size - 1; }
    Index left_child(Index i) { return i * 2 + 1; }
    Index right_child(Index i) { return i * 2 + 2; }
};

class Solver {
  public:
    int N, Q;
    bool solve() {
        cin >> N >> Q;
        SegmentTree<int> st(N);
        ll pa = 0, pb = 0;
        rep(i, Q) {
            int x, l, r;
            cin >> x >> l >> r;
            r++; // 開区間
            if(x == 0) {
                int na = st.query(l, r, 1);
                int nb = st.query(l, r, 2);
                if(na != nb) {
                    (na > nb ? pa : pb) += max(na, nb);
                }
            } else if(x == 1) {
                st.update(l, r, 1);
            } else if(x == 2) {
                st.update(l, r, 2);
            } else assert(false);
        }
        pa += st.query(0, N, 1);
        pb += st.query(0, N, 2);
        cout << pa << " " << pb << endl;
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
