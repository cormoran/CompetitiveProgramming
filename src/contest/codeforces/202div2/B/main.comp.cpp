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

bool solve(){
    int V; cin >> V;
    vector<pair<int,int>> cost(9);
    vector<int> cost2(9);
    rep(i, 9) {
        cin >> cost[i].first;
        cost[i].second = (i+1) * -1;
        cost2[i] = cost[i].first;
    }
    sort( all(cost) );

    if(cost.front().first > V){
        cout << -1 << endl;
        return false;
    }

    int base = cost.front().second * -1;
    int len = V / cost.front().first;
    int left = V % cost.front().first;
    vector<int> ans(len);
    fill( all(ans),  base);
    int pos = 0;
    for(int i = 9; i > base and pos < len; i--){
        int d = cost2[i-1] - cost2[base-1]; // > 0
        int replace_count = left / d;
        while(pos < len and replace_count--) ans[pos++] = i;
        left = left % d;
    }
    rep(i, ans.size()){
        cout << ans[i];
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
