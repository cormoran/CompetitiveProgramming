#include<iostream>
#include<vector>
#include<cassert>
#include<string>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)

using EdgeList = vector<vector<int>>;
const ll MOD = 1000000007;
EdgeList E;
int K;

#define maxIndex(x) (x.size() -1)

vector<ll> convolution(const vector<ll> &A, const vector<ll> &B){
    int max_value = maxIndex(A) + maxIndex(B);
    vector<ll> ret( min(K, max_value) + 1 );
    rep(i, A.size()){
        rep(j, B.size()){
            if(i + j <= K){
                ret[i+j] += A[i] * B[j];
                ret[i+j] %= MOD;
            }
        }
    }
    return ret;
}

vector<ll> dfs(int now, int pre){
    vector<ll> ret = {1};
    for(int nxt : E[now]){
        if(nxt != pre){
            ret = convolution(ret, dfs(nxt, now));
        }
    }
    if(maxIndex(ret) < K) ret.push_back(1);
    return ret;
}

bool solve(){
    int N; cin >> N >> K;
    E.resize(N);
    rep(i,N-1){
        int a, b; cin >> a >> b; 
        E[a].push_back(b);
        E[b].push_back(a);
    }
    vector<ll> ans = dfs(0, -1);
    cout << ( maxIndex(ans) >= K ? ans[K] : 0 )<< endl;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
