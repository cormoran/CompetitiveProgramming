#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int m;
  cin>>m;
  int ans=-1;
  if(m<100)ans=0;
  else if(m<=5000){
    ans=m/100;
  }
  else if(m<=30000){
    ans=m/1000+50;
  }
  else if(m<=70000){
    ans=(m/1000-30)/5+80;
  }
  else ans=89;

  printf("%02d\n",ans);
  
  return 0;
}
