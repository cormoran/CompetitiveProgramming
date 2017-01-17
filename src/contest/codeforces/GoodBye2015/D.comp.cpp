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
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>
ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}

template<typename T>
istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R>
void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}

const int MOD = 1000000000 + 7;

typedef unsigned long long ull;
const ull HashBase = 100000007;
vector<ull> pow_base;

vector<ull> build_rolling_hash(const string &s){
    vector<ull> hash(s.size()+1);
    pow_base.resize(s.size()+1);
    hash[0] = 0;
    pow_base[0] = 1;
    rep(i, s.size()){
        hash[i+1] = hash[i] * HashBase + s[i];
        pow_base[i+1] = pow_base[i] * HashBase;
    }
    return hash;
}

// hash of (l,r]
ull get_rolling_hash(const vector<ull> &hash,int l,int r){
    return hash[r] - hash[l] * pow_base[r-l];
}

bool is_larger_than(const string &s,int e1,int e2,int len,const vector<ull> &hash){
    int s1 = e1 - len +1;
    int s2 = e2 - len +1;
    if(get_rolling_hash(hash, s1,e1+1) == get_rolling_hash(hash, s2, e2+1)) return false;
    assert(s1 >= 0 and s2 >= 0);
    rep(i,len){
        if(s[s1+i] > s[s2+i]) return true;
        else if(s[s1+i] < s[s2+i]) return false;
    }
    return false; // equal
}


/*
    s := s1 s2 ... sn

      hash[1_to_i] := s1*b^(i-1) + s2*b^(i-2) + ... + si*b^0

        hash[1_to_j] := s1*b^(j-1) + s2*b^(j-2) + ... + si*b^(j-i) + ... + sj*b^0


          hash[(i+1)_to_j] = hash[1_to_j] - hash[1_to_i]*b^(j-i)

                             = s(i+1)*b^(j-i-1) + ... + sj*b^0
*/

bool solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;

    vector<ull> hash = build_rolling_hash(s);

    // dp[i][j] := s.substr(0,i)において、s[i+1]を終わりとする長さjの数字を採用する場合の数
    vector<vector<int>> dp(n+1,vector<int>(n+1,0)); //累積

    rep(i,n+1){
        dp[i][0] = 1;
        dp[0][i] = 1;
    }
    
    repeat_eq(i,1,n){
        repeat_eq(j,1,i){
            if( j == 1 and s[i] <= s[i-1] ){ // 増加列にならないもの
                dp[i][j] = 0; 
            } else if( s[i-(j-1)] == '0' ){  // 先頭が0のもの
                dp[i][j] = 0; 
            } else {
                if( i-j >= j and not is_larger_than(s, i, i-j, j, hash) ){
                    dp[i][j] += dp[i-j][j-1];
                } else {
                    dp[i][j] += dp[i-j][min(j,i-j)];
                }
                dp[i][j] %= MOD; 
            }
            if( j > 1 ) dp[i][j]  += dp[i][j-1];
            dp[i][j] %= MOD; 
        }
    }
    cout << dp[n][n] << endl;

    //debug(dp);
    
    
    return false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
