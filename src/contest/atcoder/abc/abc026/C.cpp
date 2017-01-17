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


int search(const vector<vector<int>> &P,int now){
    if(P[now].size()==0)return 1;

    int mx=0,mn=1<<30;
    for(int s : P[now]){
        int g = search(P,s);
        mx=max(mx,g);
        mn=min(mn,g);
    }

    return mx + mn + 1;
}

int main()
{
    int N;cin>>N;
    vector<vector<int>> P(N);
    rep(i,N-1){
        int B;cin>>B;
        P[B-1].push_back(i+1);
    }

    cout <<search(P,0) <<endl;
    
    return 0;
}
