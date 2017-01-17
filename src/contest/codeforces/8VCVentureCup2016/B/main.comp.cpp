//  codeforces -  - B  / 2016-02-14
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

typedef pair<int,pair<int,int>> ti;
#define make_it(x,y,z) make_pair(x,make_pair(y,z))

map<ti,int> memo;
int dfs(int num[3]){
    if(memo.count(make_it(num[0],num[1],num[2])))
        return memo[make_it(num[0],num[1],num[2])];
    int ret = 0;
    if(accumulate(num, num+3, 0) == 1){
        rep(i,3) if(num[i]) return memo[make_it(num[0],num[1],num[2])] = (1<<i) ;
    }
    rep(i,3){
        if(num[i] >= 2){
            --num[i];
            ret |= dfs(num);
            ++num[i];
        }
        if(num[(i+1)%3] > 0 and num[(i+2)%3] > 0){
            ++num[i];
            --num[(i+1)%3];
            --num[(i+2)%3];
            ret |= dfs(num);
            --num[i];
            ++num[(i+1)%3];
            ++num[(i+2)%3];
        }
    }
    return memo[make_it(num[0],num[1],num[2])] = ret;
}

bool solve(){
    int n;
    string s;
    cin >> n >> s;
    int num[3] = {};
    rep(i,n){
        if(s[i] == 'B')num[0]++;
        else if(s[i] == 'G')num[1]++;
        else if(s[i] == 'R')num[2]++;
    }
    int ans = dfs(num);
    char c[] = {'B','G','R'};
    rep(i,3){
        if(ans & (1<<i)) cout << c[i];
    }
    cout << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
