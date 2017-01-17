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
// pair
template<class T, class U> istream& operator >> (istream &is , pair<T, U> &v) { return is >> v.first >> v.second; }
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << " " << v.second << ">"; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }


struct UnionFind{
  int n;
  vector<int> p;
  UnionFind(int nn):n(nn+1){
      p.resize(n);
      rep(i,n) p[i] = i;
  }
  int root(int x){
    if(p[x] == x) return x;
    else return p[x] = root(p[x]);
  }
  void unite(int x,int y){
      x = root(x);
      y = root(y);
      if(x != y) p[y] = x;
  }
  bool query(int x,int y){
    return root(x) == root(y);
  }
};


const int INF = 1 << 30;
const ll INFL = 1LL << 60;
class Solver {
  public:
    int N;
    vector<pii> P;

    ll distance2(pii &a, pii &b) {
        ll x = a.first - b.first, y = a.second - b.second;
        return (ll)x * x + (ll)y * y;
    }
    bool check(ll l) {
        l *= l;
        UnionFind uf(N);
        rep(i, N) {
            rep(j, i) {
                if(distance2(P[i], P[j]) <= l) uf.unite(i, j);
            }
        }
        return uf.query(0, N - 1);
    }
    bool solve() {
        cin >> N;
        P.resize(N);
        cin >> P;

        ll l = 0, r = 1e10;
        while(l + 1 < r) {
            ll m = (l + r) / 2;
            (check(m) ? r : l) = m;
        }
        while(r % 10) r++;
        cout << r << endl;
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
