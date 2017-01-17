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
    
    Data query(Index i){
        return query(i, 0, 0, size);
    }


    void debug_tree() {
        int dep = ceil(log2(size));
        rep(i, dep + 1) {
            debug_tree(0, i);
            cout << endl;
        }
    }
  private:
    void debug_tree(Index i, int dep) {
        if(dep == 0) {
            cout << data[i] << " ";    
        } else {
            debug_tree(left_child(i), dep - 1);
            debug_tree(right_child(i), dep - 1);
            cout << " | ";
        }
    }
    // [a, b) 更新区間, i 今いるNode, [l, r) はNode[i]の担当区間
    void update(Index a, Index b, Index i, Index l, Index r, Data val){
        if(val < 0) return;
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
    
    Data query(Index a, Index i, Index l, Index r){
        //cerr << "QUERY " << a << "now " << i << " [" << l << "," << r << ")" << endl;        
        if(data[i] >= 0) return data[i];
        assert(l + 1 < r);
        Index m = (l + r) / 2;
        if(a < m) return query(a, left_child(i), l, m);
        else return query(a, right_child(i), m, r);
    }
    // Nodeの担当[l, r) に対してクエリの区間[a, b)が...
    bool out_of_range(Index a, Index b, Index l, Index r) { return r <= a or b <= l; }
    bool in_range(Index a, Index b, Index l, Index r) { return a <= l and r <= b; }
    Index left_child(Index i) { return i * 2 + 1; }
    Index right_child(Index i) { return i * 2 + 2; }
};

class Solver {
  public:
    int N;
    
    bool solve() {
        cin >> N;        
        map<int, vector<int>> mp;
        rep(i, N) {
            int a; cin >> a;
            mp[a].push_back(i);
        }
        SegmentTree<int> st(N);
        for(auto &p: mp) {
            if(p.second.size() == 1) p.second.push_back(p.second.front());
            sort(all(p.second));
            st.update(p.second.front(), p.second.back() + 1, p.first);
            //st.debug_tree();
        }
        
        rep(i, N) {
            cout << st.query(i) << (i == N - 1 ? "\n": " ");
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
