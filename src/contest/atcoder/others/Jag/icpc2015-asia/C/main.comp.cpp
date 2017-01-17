//  atcoder-Jag-icpc2015-asia-C  / 2015-11-22
#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)

const int INF = 1 << 30;
vector<string> D;
vector<int> L;

bool solve(){
    int N; cin >> N;
    D.resize(N);
    L.resize(N);
    int left = 0;
    rep(i,N){
        cin >> D[i] >> L[i];
        if(D[i] == "y")left++;
    }
    int ans = 0;
    while(left){
        //最小を探す
        int min_len = INF,min_idx = -1;
        rep(i,N){
            if(D[i]=="y" and min_len > L[i]){
                min_len = L[i];
                min_idx = i;
            }
        }
        ans++;
        for(int i = min_idx;i>=0;i--){
            if(D[i]=="n" and L[i]>=min_len) break;
            if(D[i]=="y"){
                D[i]="";
                left--;
            }
        }
        for(int i = min_idx;i<N;i++){
            if(D[i]=="n" and L[i]>=min_len) break;
            if(D[i]=="y"){
                D[i]="";
                left--;
            }
        }
    }
    cout << ans << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
