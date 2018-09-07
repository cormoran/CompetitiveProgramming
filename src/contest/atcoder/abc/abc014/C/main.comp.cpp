#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin >>n;
  int a,b;
  int ls[1000002]={};
  for(int i=0;i<n;i++){
    cin>>a>>b;
    ls[a]++;
    ls[b+1]--;
  }
  int ans=ls[0];
  for(int i=1;i<=1000000;i++){
    ls[i]+=ls[i-1];
    ans=max(ans,ls[i]);
  }
  cout<<ans<<endl;
  return 0;
}