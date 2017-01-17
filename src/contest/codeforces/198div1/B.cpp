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
    int n;cin>>n;
    vector<int> v;
    v.reserve(n);
    rep(i,n){
        int a;
        cin>>a;
        auto itr =lower_bound(all(v), a);
        if(itr==end(v))v.push_back(a);
        else *itr=a;
    }
    cout<<v.size()<<endl;
    
    return 0;
}
