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
    int N; cin >> N;
    vector<int> P(N); cin >> P;
    vector<pair<int,int>> PP(N);
    rep(i, N){
        PP[i].first = P[i];
        PP[i].second = i;
    }
    sort(all(PP));
    int ans = 0;
    rep(i, N){
        if(PP[i].first != P[i]){
            swap(P[i], P[PP[i].second]);
            ans++;
        }
    }
    printf("%.6f\n", (double)ans);
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
