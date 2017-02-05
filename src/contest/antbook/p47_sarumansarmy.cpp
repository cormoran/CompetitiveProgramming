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

int main()
{
  int n,r,x[1000];
  cin>>n>>r;
  int i;
  rep(i,n)cin>>x[i];

  int ans=0;
  i=0;
  while(i<n){
    int s=x[i++];
    while(i<n && s+r>=x[i])i++;
    int p=x[i-1];
    while(i<n && p+r>=x[i])i++;
    ans++;
  }
  cout<<ans<<endl;

  return 0;
}
