/*
  file : /1258.comp.cpp
  date : 2015-10-19
  summmary :
  {
  シミュレーション
  input
  m c n 1to10 , 1to30 , 1to100
  k1
  b11 ... b1k
  .
  .
  kn
  bn1 ... bnk

  ki : 1to50
  bij : 1to99
  }
  status :
  {
  
  }
  memo :
  {
  
  }
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


bool solve(){
    int m,c,n;cin>>m>>c>>n;
    if(m==0)return false;
    vector<queue<int>> book(n);
    rep(i,n){
        int k;cin>>k;
        int b;
        rep(j,k){
            cin>>b;
            book[i].push(b);
        }
    }

    //simulation
    int i=0;
    {
        while(book[i].empty()){
            i+=1;i%=n;
        }
        

        
    }
    
    return true;
}

int main()
{
    while(solve());
    return 0;
}
