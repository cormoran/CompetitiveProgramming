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
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,n)cin>>v[i];
    int sum =0;
    int rec=0;
    while(sum<n){
        rep(i,n){
            if(v[i]>=0 and v[i]<=sum){
                v[i]=-1;
                sum++;
            }
        }
        rec++;
        if(sum==n)break;
        for(int i=n-1;i>=0;i--){
            if(v[i]>=0 and v[i]<=sum){
                v[i]=-1;
                sum++;
            }
        }
        rec++;
    }

    cout << rec -1 <<endl;

    return 0;
}
