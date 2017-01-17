#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

#define DIRTY 1
#define CLEAN 0

int main()
{
    ios::sync_with_stdio(false);
    int H,W;
    cin>>H>>W;
    vector<vector<int>> T(H,vector<int>(W));
    rep(y,H)rep(x,W){
        cin>>T[y][x];
    }
    int ans=0;
    vector<vector<int>> DP(H,vector<int>(W));
    rep(y,H){
        DP[y][0]=(T[y][0]==0?1:0);
        ans=max(ans,DP[y][0]);   
    }
    rep(x,W){
        DP[0][x]=(T[0][x]==0?1:0);
        ans=max(ans,DP[0][x]);   
    }
    
    rep(y,H){
        if(y==0)continue;
        rep(x,W){
            if(x==0)continue;
            if(T[y][x]==DIRTY){
                DP[y][x]=0;
            }else{
                DP[y][x]=min(DP[y-1][x]  , DP[y][x-1]);
                DP[y][x]=min(DP[y-1][x-1], DP[y][x]);
                DP[y][x]+=1;
            }
            ans=max(ans,DP[y][x]);
        }
    }
    cout<< ans*ans <<endl;
    return 0;
}
