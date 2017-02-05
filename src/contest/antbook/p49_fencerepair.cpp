#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
//#include<>
using namespace std;
typedef long long ll;
#define rep(i,j) for(i=0;i<j;(i)++)

int main()
{
  int n,l[20000];
  int i;
  cin>>n;
  rep(i,n)cin>>l[i];

  ll ans=0;
  while(n>1){
    int mii1=0,mii2=1;
    if(l[i]<l[mii2])swap(mii1,mii2);



    for(i=2;i<n;i++)
      if(l[i]<l[mii1]){
	  mii2=mii1;
	  mii1=i;
	}
	else if (l[i]<l[mii2]){
	  mii2=i;
	}
    int t=l[mii1]+l[mii2];  
    ans+=t;
    if(mii1==n-1)swap(mii1,mii2);
    l[mii1]=t;
    l[mii2]=l[n-1];
    n--;
  }
  cout<<ans<<endl;


  return 0;
}
