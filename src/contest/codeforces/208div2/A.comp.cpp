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
istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

bool solve(){
    int N; cin >> N;
    vector<int> X(N); cin >> X;
    bool fail = false;
    rep(i, N-1){
        rep(j, i-1){
            int a = X[i], b = X[i+1];
            if(a > b) swap(a, b);
            int c = X[j], d = X[j+1];
            if(c > d) swap(c, d);
            if(a < c and c < b and b < d) fail = true;
            if(c < a and a < d and b > d) fail = true;
        }
    }
    cout << (fail ? "yes" : "no") << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
