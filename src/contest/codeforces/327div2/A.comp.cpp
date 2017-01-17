/*
  --- 
  title : -A.comp.cpp
  date : 2015-10-25
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


bool solve(){
    int l,p,q;cin>>l>>p>>q;

    double first = (double)l/(p+q) * p;
    
    printf("%.8f\n",first);
    
    return false;
}

int main()
{
    while(solve());
    return 0;
}
