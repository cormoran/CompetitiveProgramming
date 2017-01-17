#include<iostream>
using namespace std;
int main(){

  int n,m;
  cin>>n>>m;
  int ans,i=0;
  while(true){
    ans=n/2+n%2+i;
    if(ans%m==0)break;
    if(n-++i*2<0){
      ans=-1;
      break;
    }
  }
  cout<<ans<<endl;
  return 0;
}
