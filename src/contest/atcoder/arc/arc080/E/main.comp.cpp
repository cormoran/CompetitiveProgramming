#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
//#define debug(x) cerr << #x << " : " << x << endl
#define debug(...)

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

class Segment_Tree
{
public:

  int n;
  vector<int> data;

  Segment_Tree(int n_)
  {
    n=1;
    while(n<n_)n*=2;
    data.resize(2*n-1,INF);
  }

  //index k(=0,1,2...)の値をaにする。
  void update(int k,int a)
  {
    k+=n-1;
    data[k]=a;
    while(k>0){
      //親は1-index では k/2なので 0-indexでは (k+1)/2 - 1 = (k-1)/2
      k=(k-1)/2;
      data[k]=min(data[k*2+1],data[k*2+2]);
    }
  }

  int query(int a,int b)
  {
    return search(a,b+1,0,0,n);
  }
private:
  //[a,b)の最小値,kは今の場所,[l,r)はkの守備範囲
  int search(int a,int b,int k,int l,int r)
  {
    //目的範囲からずれた無効
    if(r<=a||b<=l)return INF;
    //目的範囲より狭くなったら終了
    if(a<=l&&r<=b)return data[k];
    else {
      //左の子側の範囲
      int vl=search(a,b,k*2+1,l,(l+r)/2);
      //右の子側の範囲
      int vr=search(a,b,k*2+2,(l+r)/2,r);
      return min(vl,vr);
    }
  }

};

struct S;

struct PS {
    S *a;
};

struct S {
    pii front;
    priority_queue<PS> back;
    pii pop() {        
        pii res = front;
        if(back.size() > 0) {
            S *a = back.top().a;
            back.pop();
            front = a->front;
            while(a->back.size()) {
                back.push(a->back.top());
                a->back.pop();
            }
        } else {
            front = make_pair(INF, INF);
        }        
        return res;
    }
};



bool operator < (const PS &a, const PS &b) {
    return a.a->front > b.a->front;
}


class Solver {
  public:
    int N;
    vector<int> P;
    Segment_Tree *rmq1, *rmq2;
    map<int, int> to_index;
    PS solve(int s, int e) {
        assert(e > s);
        int p = to_index[(s % 2 == 0 ? rmq1 : rmq2)->query(s, e -1)];
        int q = to_index[(s % 2 == 1 ? rmq1 : rmq2)->query(p + 1, e-1)];
        debug(s); debug(e);
        debug(p); debug(q);
        assert(p >= 0 and q >= 0);
        S *res = new S();
        res->front = make_pair(P[p], P[q]);
        if(s < p) res->back.push(solve(s, p));
        if(p + 1 < q) res->back.push(solve(p + 1, q));
        if(q + 1 < e) res->back.push(solve(q + 1, e));
        return PS{res};
    }
    bool solve() {
        cin >> N;
        P.resize(N); cin >> P;
        rmq1 = new Segment_Tree(N);
        rmq2 = new Segment_Tree(N);

        for(int i = 0; i < N; i += 2) rmq1->update(i, P[i]);
        for(int i = 1; i < N; i += 2) rmq2->update(i, P[i]);
        to_index[INF] = -1;
        rep(i, N) to_index[P[i]] = i;
        
        auto res = solve(0, N);
        debug(res);
        vector<int> ans;

        rep(i, N) {
            pii a = res.a->pop();
            ans.push_back(a.first);
            ans.push_back(a.second);
        }
        rep(i, N) {
            cout << ans[i] << (i == N - 1 ? "\n" : " ");
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
