/*
  file : /main.comp.cpp
  date : 2015-10-23

 */

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cassert>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

#define N_MAX 1130
#define K_MAX 15
int DP[N_MAX][K_MAX];//n k


void init(){
    vector<bool> is_prime(N_MAX,true);
    is_prime[0]=false;
    is_prime[1]=false;
    for(int i=2;i<N_MAX;i++){
        if(not is_prime[i])continue;
        for(int j =i*2;j<N_MAX;j+=i){
            is_prime[j]=false;
        }
    }

    rep(i,N_MAX){
        rep(j,K_MAX){
            DP[i][j]=0;
        }
    }

    // rep(p,N_MAX){
    //     if(is_prime[p])DP[p][1]=1;
    // }
    DP[0][0]=1;
    rep(p,N_MAX){
        if(is_prime[p]){
            for(int k=K_MAX-1;k>=0;k--){
                rep(n,N_MAX){
                    if(n-p>=0 and k-1>=0)DP[n][k] += DP[n-p][k-1];
                    //printf("%lld %d %d\n",n,k,DP[n][k]);
                }
            }
        }


    }
}


bool solve(){
    int n,k;
    cin>>n>>k;
    if(n==0 && k==0)return false;
    cout << DP[n][k] <<endl;    
    return true;
}

int main()
{
    init();

    // rep(n,25){
    //     cout<<n<<"  ";
    //     rep(k,3){
    //         cout <<DP[n][k] <<" ";
    //     }
    //     cout <<endl;
    // }
    
    while(solve());
    return 0;
}
