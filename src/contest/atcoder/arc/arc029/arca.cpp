#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
//#include<>
using namespace std;

#define rep(i,j) for(i=0;i<j;(i)++)


int n,t[10];
int rec(pair<int,int> ni,int num){
  int ans1,ans2;
  if(num==n)return max(ni.first,ni.second);
  else{
    ni.first+=t[num];
    ans1=rec(ni,num+1);
    ni.first-=t[num];
    ni.second+=t[num];
    ans2=rec(ni,num+1);
    if(ans1<=ans2){
      return ans1;
    }
    else return ans2;
  }
  return -1;
}

int main()
{
  int i;
  cin>>n;
  rep(i,n){
    cin>>t[i];
  }
  pair<int,int> ans;
  ans.first=0;
  ans.second=0;
  cout <<rec(ans,0)<<endl;

  return 0;
}
