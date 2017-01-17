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
    int N;cin>>N;
    double ans=0;
    vector<int> R(N);
    rep(i,N){
        cin>>R[i];
    }
    sort(R.rbegin(),R.rend());
    rep(i,N){
        ans += R[i]*R[i] * (i%2==0 ? 1 : -1); 
    }
    printf("%.10f\n",ans*M_PI);
    return 0;
}
