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
    int n;cin>>n;
    vector<bool> flg[2];
    rep(i,2)flg[i]=vector<bool>(n,false);
    int sum=0;
    vector<int> ans;
    rep(i,n*n){
        int a,b;
        cin>>a>>b;
        a--;b--;
        if(!flg[0][a] and !flg[1][b]){
            flg[0][a]=flg[1][b]=true;
            ans.push_back(i+1);
        }
    }

    rep(i,ans.size()-1){
        cout<<ans[i]<<" ";
    }
    cout<<ans.back()<<endl;
    
    return 0;
}
