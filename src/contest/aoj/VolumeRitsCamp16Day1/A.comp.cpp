#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()
#define sign(x) ((x) >= 0 ? 1 : -1)

bool solve(){
    int L, N; cin >> L >> N;
    int power = 0;
    rep(i, N){
        int x, w; cin >> x >> w;
        power += x * w;
    }
    if(power == 0) cout << 0 << endl;
    else {
        cout << 1 << endl;
        cout << -1 * sign(power) << " " << abs(power) << endl;
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
