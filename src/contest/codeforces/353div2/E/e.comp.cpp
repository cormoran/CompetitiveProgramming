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

using ll = long long;
using pll = pair<ll, ll>;
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

const ll INF_LL = 1LL << 60;


#include<functional>
using Index = int;
template<typename Data>
class RangeQuery{
  public:
    int n;
    vector<Data> data;
    function< Data(Data,Data) > selector;
    Data default_val;
    
    RangeQuery(int n, function< Data(Data,Data) > selector,Data default_val)
            :selector(selector),default_val(default_val){
        this->n = 1;
        while(this->n < n) this->n *= 2;
        data.resize(2*(this->n)-1, default_val);
    }

    //index k(=0,1,2...)の値をaにする。
    void update(Index k,Data val){
        assert(0<=k and k<n);
        k += n-1;
        data[k] = val;
        while( k > 0 ){
            k = (k-1)/2; //親
            data[k] = selector(data[k*2+1], data[k*2+2]);
        }
    }

    // [a,b] のクエリ b<n
    Data query(Index a,Index b){
        assert(0<=a and b<n);
        return search(a,b+1,0,0,n);
    }
  private:
    //[a,b)の最小値,kは今の場所,[l,r)はkの守備範囲
    Data search(Index a,Index b,Index k,Index l,Index r){
        if( r <= a or b <= l ) return default_val;      // 範囲からずれた
        if( a <= l and r <= b ) return data[k]; // 目的範囲より狭くなった
        else {
            //左の子側の範囲
            Data vl = search(a, b, k*2+1, l, (l+r)/2);
            //右の子側の範囲
            Data vr = search(a, b, k*2+2, (l+r)/2, r);
            return selector(vl, vr);
        }
    }

};

bool solve() {
    int N; cin >> N;
    vector<int> A(N - 1);
    rep(i, N - 1) scanf("%d", &A[i]);
    RangeQuery<pair<ll,ll>> rmq(N, [](const pll a, const pll b){ return min(a, b);} , make_pair(INF_LL, INF_LL));
    
    vector<ll> DP(N);
    DP[N-1] = 0;
    rmq.update(N - 1, make_pair(0, N - 1));
    for(int i = N - 2; i >= 0; i--) {
        ll dest = rmq.query(i+1, A[i] - 1).second;
        //DP[i] = DP[dest] + (N - dest - 1)  + dest - i;        
        DP[i] = DP[dest] + (N - A[i]) + dest - i; // A[i]までは1回で行ける, それ以上は最適なところを経由する
        rmq.update(i, make_pair(DP[i], i));
    }
    //debug(DP);
    cout << accumulate(all(DP), 0LL) << endl;
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
