//#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<string>
#include<cmath>
#include<cassert>
#include<map>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

int main()
{
    ios::sync_with_stdio(false);
    int N;cin>>N;
    vector<int> A1(N),A2(N);
    A1[0]=0;
    rep(i,N){
        if(i==0)continue;
        int a;cin>>a;
        A1[i]=A1[i-1]+a;
    }
    A2[0]=0;
    rep(i,N){
        if(i==0)continue;
        int a;cin>>a;
        A2[i]=A2[i-1]+a;
    }
    vector<int> B(N);
    rep(i,N)cin>>B[i];

    int ans = 1<<30;
    rep(i,N){
        rep(j,i){
            int sum = B[i] +B[j];
            sum += A1[i] + A2[N-1] - A2[i];
            sum += A1[j] + A2[N-1] - A2[j];
            ans = min(ans,sum);
        }
    }

    cout <<ans<<endl;
    
    return 0;
}
