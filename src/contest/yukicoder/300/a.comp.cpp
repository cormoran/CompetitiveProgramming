#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<tuple>
#include<numeric>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl


bool solve() {
    ll X; cin >> X;
    map<int, int> factors;
    for(ll i = 2; X > 1;) {
        if( X % i == 0) {
            X /= i;
            factors[i] += 1;
        }
        else i++;
    }
    ll Y = 1;
    for(auto p : factors) {
        if(p.second % 2 == 1) Y *= p.first;
    }
    cout << Y << endl;
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
