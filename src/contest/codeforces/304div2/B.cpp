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

typedef long long int64;typedef int int32;
typedef long long ll;

typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)


int main()
{
  int n;
  cin>>n;
  priority_queue<int,vector<int>,greater<int> > que;
  rep(i,n){
    int a;
    cin>>a;
    que.push(a);
  }

  int ans=0;
  int lst=1;

  while(!que.empty()){
    int q=que.top();que.pop();
    if(q<lst){
      ans+=lst-q;
      lst++;
    }
    else lst=q+1;//lst=qになる
  }
  cout<<ans<<endl;
  return 0;
}
