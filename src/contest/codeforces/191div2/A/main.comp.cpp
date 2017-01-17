//  codeforces-191div2-A  / 2015-12-17
#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}
template<typename T>istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R> void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}


bool solve(){
    int n; cin >> n;
    vector<int> sum(n+1);
    sum[0] = 0;
    rep(i,n){
        cin >> sum[i+1];
        sum[i+1] += sum[i];
    }
    int ans = sum[n];
    bool flg = false;
    repeat(i,1,n+1){
        rep(j,i){
            int up = (i - j) - 2*(sum[i] - sum[j]);
            if( ans <= sum[n] + up){
                flg = true;
                ans = max(ans, sum[n] + up);
            }
        }
    }
    if(not flg) cout << ans -1 << endl;
    else cout << ans <<endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
