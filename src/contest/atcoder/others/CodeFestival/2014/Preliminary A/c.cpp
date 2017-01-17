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
  long long a,b,ans=0;
  cin>>a>>b;
  ans=b/4-b/100+b/400;
  a--;
  ans-=a/4-a/100+a/400;

  cout<<ans<<endl;
  return 0;
}
