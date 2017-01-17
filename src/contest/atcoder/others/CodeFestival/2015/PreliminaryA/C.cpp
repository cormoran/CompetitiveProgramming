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
#define rall(v) v.rbegin(),v.rend()

int main()
{
    int N,T;
    cin>>N>>T;
    vector<int> D(N);
    ll sum=0;
    rep(i,N){
        int A,B;
        cin>>A>>B;
        D[i]=A-B;
        sum+=A;
    }
    sort(rall(D));

    rep(i,N){
        if(sum<=T){
            cout<<i<<endl;
            return 0;
        }
        sum-=D[i];
    }

    cout<<(sum==0?N:-1)<<endl;
    
    return 0;
}
