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

using Index = int;
template<typename Data>
class FenwickTree{
  private:
    vector<Data> data;
  public:
    FenwickTree(int n){
        data.resize(n+1,0);
    }  
    //sum of index 0,1,..,i
    Data sum(Index idx){
        Data s = 0;
        while(idx > 0){
            s += data[idx];
            idx -= idx & (-idx);
        }
        return s;
    }  
    //sum of index i,i+1,...,j
    // sum of [i,j]
    Data sum(Index i,Index j){
        return sum(j) - sum(i-1);
    }
    //add x to index i
    void add(Index i,Data x){
        while(i < data.size()){
            data[i] += x;
            i += i & (-i);
        }
    }
};

class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        vector<int> P(N); cin >> P;
        reverse(all(P));
        FenwickTree<ll> a(N), b(N);
        repeat(i, 1, N + 1) {
            a.add(i , 1);
            b.add(i , -1);
        }
        rep(i, N) {            
            int p = P[i];
            b.add(p, -i);
            if(p < N) a.add(p + 1, i);
        }
        vector<ll> A(N), B(N);
        ll mb = INFL;
        rep(i, N) {
            A[i] = a.sum(i+1);
            B[i] = b.sum(i+1);
            set_min(mb, B[i]);
        }
        rep(i, N) cout << A[i] << (i == N - 1 ? "\n" : " ");
        rep(i, N) cout << B[i] - mb + 1 << (i == N - 1 ? "\n" : " ");
        
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
