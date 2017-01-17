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
//#include<cstdint>
using namespace std;

typedef long long i64;typedef int i32;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)


int main()
{
  int n,k,p,x,y;
  cin>>n>>k>>p>>x>>y;
  vector<int> a(k);
  int sum=0;
  rep(i,k){
    cin>>a[i];
    sum+=a[i];
  }

  int leftturn=n-k;
  int leftp=x-sum;
  vector<int> ans;


  if(leftp<leftturn){
    cout<<-1<<endl;
    return 0;
  }
  leftturn--;
  for(;leftturn>=0;leftturn--){
    if(leftp-y>=leftturn){
      ans.push_back(y);
      a.push_back(y);
      leftp-=y;
    }
    else{
      ans.push_back(1);
      a.push_back(1);
      leftp-=1;
    }
  }

  sort(all(a));

  /*
  rep(i,a.size()){
    cout<<a[i]<<" ";
  }
  puts("");;
  */
  
  if(a[(n+1)/2-1]<y){
    cout<<-1<<endl;
    return 0;
  }

  rep(i,ans.size()-1){
    cout<<ans[i]<<" ";
  }
  cout<<ans.back()<<endl;
  
  return 0;
}
