#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<tuple>
#include<numeric>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl
// vector
template<class T> ostream& operator << (ostream &os , const vector<T> &v) {
    for(const T &t : v) os << "\t" << t; return os << endl;
}
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) {
    return os << "<" << v.first << " " << v.second << ">";
}

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

bool solve() {
    int n; cin >> n;
    vector<int> p(n); cin >> p;
    rep(i, n) p[i]--;
    vector<int> org = p;
    
    UnionFind uf(n);
    
    rep(i, n) {
        if(p[i] == i) p[i] = -1;
        else {
            if(uf.query(i, p[i])) {
                p[i] = -1;
            } else {
                uf.unite(i, p[i]);
            }
        }
    }
    int root = -1;
    rep(i, n) if(org[i] == i) root = i;
    rep(i, n) if(p[i] == -1)  {
        if(root < 0) root = i;
        p[i] = root;
    }
    int cnt = 0;
    rep(i, n) cnt += org[i] != p[i];
    cout << cnt <<endl;
    rep(i, n) {
        cout << p[i] + 1 << (i == n - 1 ? "\n" : " ");
    }
    
    
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
