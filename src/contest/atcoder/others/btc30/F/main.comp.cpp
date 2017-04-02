#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }

class ModInt{
 public:
  static const ll MOD = 1000000007LL;
  long long x;
  ModInt(){};
  ModInt(ll x_):x((x_%MOD+MOD)%MOD){};
  static const ModInt pow(const ModInt &n,ll r);
  static const ModInt inverse(const ModInt &n);
  const ModInt operator +(const ModInt &l)const{return ModInt(x+l.x);}
  const ModInt operator -(const ModInt &l)const{return ModInt(x-l.x);}
  const ModInt operator *(const ModInt &l)const{return ModInt(x*l.x);}
  const ModInt operator += (const ModInt &l)const{return (*this)+l;};
  const ModInt operator -= (const ModInt &l)const{return (*this)-l;};
  const ModInt operator *= (const ModInt &l)const{return (*this)*l;};
  const ModInt operator /(const ModInt &l)const{return ModInt((*this) * inverse(l));}
  friend std::ostream& operator << (std::ostream& os,const ModInt& a){os<<a.x;return os;}
};

const ModInt ModInt::pow(const ModInt &n, ll r){
  if(r==0)return 1;
  ModInt ret=pow(n,r/2);
  ret=ret*ret;
  if(r%2!=0)ret= ret*n;
  return ret;
}

const ModInt ModInt::inverse(const ModInt &n){
  return pow(n, MOD-2);
}

class Solver {
  public:        
    bool solve() {
        int N; cin >> N;
        vector<ll> A(N); cin >> A;

        vector<ModInt> prod(N + 1); // [i] := product of [0, i)
        {
            prod[0] = 1;
            rep(i, N) prod[i + 1] = prod[i] * A[i];
        }
        vector<ModInt> prod_sum(N + 1); // [i] := prod の sum of [0, i)
        {
            prod_sum[0] = 0;
            rep(i, N) prod_sum[i + 1] = prod_sum[i] + prod[i + 1] * (N - i - 2 >= 0 ? ModInt::pow(2, N - i - 2) : 1);
        }
        
        //
        // f(n) := an ... aN-1 までの配列での部分解
        // f(N) := 0
        //
        // def f(n):
        //   ans = 0
        //   for i = n; i < N; i++
        //     ans += an*...*ai * (N-i-2 >= 0 ? pow(2, N-i-2) : 1) + f(i+1)
        //            <-(1)-------------------------------------->   <-(2)->
        //   return ans
        //
        // for をつぶす
        // (1) -> sigma i in [n, N) { an*...*ai * (N-i-2 >= 0 ? pow(2, N-i-2) : 1) }
        //        = (a0*...*an-1)^-1 * sigma i in [n, N) { a0*...*ai * (N-i-2 >= 0 ? pow(2, N-i-2) : 1) }
        //          <-------------->   <---------------------------------------------------------------->
        //          inverse(prod[n])    prod_sum[N] - prod_sum[n]
        // 
        // (2) -> sigma f(i) for i in [n+1, N)
        //
        vector<ModInt> memo_sum(N + 1); // [i] := sum of f(n) for n in [i, N)
        memo_sum[N] = 0;
        function<ModInt(int)> f = [&](int n) {
            if(n == N) return 0LL;
            memo_sum[n] = f(n + 1) + memo_sum[n + 1];
            auto a = (prod_sum[N] - prod_sum[n]) * ModInt::inverse(prod[n]);
            ModInt ret = a + memo_sum[n];
            // cerr << "f(" << n << ") = " << ret << endl;
            return ret.x;
        };
        cout << f(0) << endl;
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
