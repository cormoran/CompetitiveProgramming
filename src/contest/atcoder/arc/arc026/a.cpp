#include<iostream>

int main(){
  int n,a,b,c=5,ans=0,i;
  std::cin >> n>>a>>b;
  for(i=0;i<n;i++){
    if(c-->0)ans+=b;
    else ans+=a;
  }
  std::cout << ans<<std::endl;
}
