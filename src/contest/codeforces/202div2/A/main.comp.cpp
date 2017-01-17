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

bool solve(){
    int N; cin >> N;
    map<int,int> coin;
    bool flg = true;
    rep(i, N){
        int c; cin >> c;
        if(c == 100) {
            coin[25]--;
            if(coin[50] > 0) coin[50]--;
            else coin[25] -= 2;
            coin[100]++;
        } else if(c == 50){
            coin[25]--;
            coin[50]++;
        } else coin[25]++;
        for(auto p : coin) if(p.second < 0) flg = false;
    }
    cout << (flg ? "YES" : "NO") << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
