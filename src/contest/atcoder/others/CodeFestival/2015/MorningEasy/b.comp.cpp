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


int lcs(string s1,string s2){
    debug(s1,s2);
    int m = s1.size(),n=s2.size();
    vector<vector<int>> DP(m+1,vector<int>(n+1));
    rep(i,n+1)DP[0][i]=0;
    rep(i,m+1)DP[i][0]=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1])DP[i][j]=DP[i-1][j-1]+1;
            else DP[i][j]=max( DP[i-1][j] , DP[i][j-1]);
        }
    }
    debug(DP[m][n]);
    return DP[m][n];
}

bool solve(){
    int n;
    string s;cin>>n>>s;
    int ans = s.size();
    int mx =0;
    rep(cut,s.size()){
        mx = max(mx,lcs(s.substr(0,cut+1),s.substr(cut+1)));                 
    }
    cout << s.size()-mx*2<<endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
