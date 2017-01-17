//  atcoder - abc032 - A  / 2016-03-30
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define all(v) v.begin(),v.end()

bool solve(){
    ll a, b, n;
    cin >> a >> b >> n;
    ll g = a * b / __gcd(a , b);
    cout << ceil( (double)n / g ) * g << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
