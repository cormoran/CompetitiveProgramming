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
#define rep(i,j) for(int__ (i)=0;i<int(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)

template<typename T>
T gcd(T a,T b){
    T c=a,d=b,r;
    do{r=c%d;c=d;d=r;}while(r);
    return c;
}


int main()
{
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<int> table(n*n);
    rep(i,table.size()){
        cin>>table[i];
    }
    sort(all(table));
    reverse(all(table));

    // rep(i,n*n){
    //     cout << table[i] << endl;
    // }
    
    vector<int> ans;
    ans.reserve(n);
    
    map<int,int> used;
    
    for(auto i = begin(table);i!=end(table);i++){
        if(used[*i]>0){
            used[*i]--;
        }else{
            ans.push_back(*i);
            rep(j,ans.size()-1){
                used[gcd(ans[j],*i)]+=2;
            }
        }
    }

    rep(i,ans.size()-1){
        cout << ans[i] <<" ";
    }
    cout <<ans.back()<<endl;
    
    return 0;
}
