/*
  --- 
  title : -C.comp.cpp
  date : 2015-10-24
  status : NULL
  ---
  
  # Memo

  
 */

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cassert>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()
typedef vector<vector<int>> Mat;

bool solve(){
    int T;cin>>T;

    while(T--){
        int N;cin>>N;
        Mat G(N,vector<int>(N));
        rep(i,N)rep(j,N)cin>>G[i][j];

        

    }
    
    return false;
}

int main()
{
    while(solve());
    return 0;
}
