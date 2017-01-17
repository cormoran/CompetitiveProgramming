//  atcoder - abc032 - C  / 2016-03-30
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define all(v) v.begin(),v.end()

template<typename T>istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

bool solve(){
    int N, K; cin >> N >> K;
    vector<int> S(N); cin >> S;
    if(*min_element(all(S)) == 0) {
        cout << N << endl;
        return 0;
    }
    if( K == 0 ){
        cout << 0 << endl;
        return 0;
    }
    int maxlen = 0;
    ll pro = 1;
    int head = 0, tail = 0;
    while( head < N){
        while(head < N and pro <= K) pro *= S[head++];
        maxlen = max(maxlen, head - tail - (pro > K ? 1 : 0));
        while(pro > K) pro /= S[tail++];
    }
    cout << maxlen << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
