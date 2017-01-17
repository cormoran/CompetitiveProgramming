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
    int N;
    cin>>N;
    vector<ll> V(N),D(N),P(N);
    rep(i,N){
        cin >>V[i]>>D[i]>>P[i];
    }
    vector<int> ans;
    ans.reserve(N);
    rep(i,N){
        if(P[i]<0)continue;
        ans.push_back(i+1);
        ll sum1=V[i];
        ll sum2=0;
        for(int j=i+1;j<N;j++){
            if(P[j]<0)continue;
            P[j]-=sum1+sum2;
            if(P[j]<0)sum2+=D[j];
            sum1=max(0LL,sum1-1);
        }
    }

    cout << ans.size() <<endl;

    if(ans.size()>0){
        rep(i,(int)ans.size()-1){
            cout << ans[i] <<" ";
        }
        cout <<ans.back()<<endl;
    }
    return 0;
}
