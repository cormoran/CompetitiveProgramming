//#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
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
    int N;
    cin>>N;
    vector<int> V(N+1);
    rep(i,N){
        cin>>V[i];
    }
    V[V.size()-1]=0;
    bool school=false;
    int ans=0;
    rep(i,N){
        if(V[i]==1 || (school && V[i+1] != 0)){
            ans++;
            school=true;
        }else{
            school=false;
        }
    }
    cout << ans << endl;
    
    return 0;
}
