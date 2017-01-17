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

vector<int> X;
int N,M;

map<int,int> MEMO[500001];

int rec(int now,int s){
    if(s>N)return 0;
    if(now>=M){
        if(s<=N)return 1<<30;
        else return 0;
    }
    if(MEMO[now][s]>0)return MEMO[now][s];
    int ret = 1<<30;
    //s to e まで xさんが見る
    for(int e=X[now];e<X[now+1];e++){
        int res = rec(now+1,e+1);
        int a=X[now]-s;
        int b=e-X[now];
        res = max(res,min(a,b)*2 + max(a,b));
        //printf("s %d X %d e %d min %d\n",s,X[now],e,min(a,b)*2 + max(a,b));
        ret = min(ret,res);
    }
    return MEMO[now][s]=ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>N>>M;

    X.resize(M+1);
    rep(i,M){
        cin>>X[i];
    }
    X[M]=N+1;


    cout<<rec(0,1)<<endl;
    
    return 0;
}
