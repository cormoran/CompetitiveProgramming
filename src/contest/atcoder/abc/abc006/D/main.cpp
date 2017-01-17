#include<iostream>
#include<algorithm>
#define rep(i,j) for(i=0;i<j;i++)
using namespace std;
/*最長列が欲しい！！*/
int main(){
  unsigned n;
  cin>>n;
  unsigned c[n],dp[n],i,j;
  rep(i,n){cin>>c[i];dp[i]=0;}
  unsigned cnt,ans=0;
  rep(i,n){
    cnt=ans;
    while(true){
      if(dp[cnt]<c[i]){
	dp[++cnt]=c[i];
	ans=max(cnt,ans);
	break;
      }
      cnt--;
    }
  }
  
  cout<<n-ans<<endl;
  return 0;
}
