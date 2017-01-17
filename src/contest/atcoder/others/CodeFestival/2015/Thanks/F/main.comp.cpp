//  atcoder-CodeFestival-2015-Thanks-F  / 2015-12-05
#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()


typedef vector<vector<int>> EdgeList;

int child_num(EdgeList &E,int now,int pre){
    int sum = 0;
    for(int nxt : E[now]){
        if(nxt == pre) continue;
        sum += child_num(E, nxt, now) + 1;
    }
    return sum ;
}

bool solve(){
    int n; cin >> n;
    EdgeList E(n);
    rep(i,n-1){
        int s,t; cin >> s >> t;
        s--;t--;
        E[s].push_back(t);
        E[t].push_back(s);
    }
    if(E[0].size() == 1){
        cout << "A" << endl;
        return 0;
    }
    
    int num = 0;
    for(int child : E[0]){
        num++;
        num += (child_num(E,child,0) %2 == 1);
    }
    cout << (num % 2 == 1 ? "A" : "B") <<endl;
    
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
