//  atcoder -  - B  / 2016-02-27
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
    double a,b,c; cin >> a >> b >> c;
    if(b > a) swap(a,b);
    double l = a + b + c;
    double s = abs( a - c );
    s = max(s - b, 0.0);
    cerr << l << " " << s << endl;
    printf("%.9f\n", l * l * M_PI - s * s * M_PI );
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
