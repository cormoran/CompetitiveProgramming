//  codeforces -  - A  / 2016-02-14
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

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()



bool solve(){
    int n; cin >> n;
    string s; cin >> s;
    ll ans = 0;
    rep(i,n){
        pair<int,int> pos = make_pair(0,0);
        repeat(j,i,n){
            if(s[j] == 'U') pos.first++;
            else if(s[j] == 'D') pos.first--;
            else if(s[j] == 'L') pos.second++;
            else if(s[j] == 'R') pos.second--;
            if(pos == make_pair(0,0)) ans++;
        }
    }
    cout << ans <<endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
