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
const ll MOD = 1000000007;
template<typename Data>
class FenwickTree{
  private:
    vector<Data> data;
  public:
    FenwickTree(int n){
        data.resize(n+1,0);
    }

    Data sum(int idx){
        Data s = 0;
        while(idx > 0){
            s += data[idx];
            idx -= idx & (-idx);
        }
        return s;
    }
    //add x to int i
    void add(int i,Data x){
        while(i <= data.size()){
            data[i] += x;
            i += i & (-i);
        }
    }
};

int main() {
    int N; cin >> N;
    vector<ll> A(N); cin >> A;

    vector<ll> factorial(N + 1);
    factorial[0] = 1;
    repeat(i, 1, N) factorial[i] = (factorial[i - 1] * i) % MOD;

    FenwickTree<ll> bit(N * 2);
    ll ans = 1;
    rep(i, N) {
        ans += (A[i] - 1 - bit.sum(A[i])) * factorial[N - i - 1];
        ans %= MOD;
        bit.add(A[i], 1);
    }
    cout << ans << endl;
    return 0;
}
