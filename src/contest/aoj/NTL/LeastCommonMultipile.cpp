#include<iostream>
#include<cstdio>
#include<cstdlib>
//#include<>
using namespace std;

long long get_G(long long a,long long b){
  //Eucledean algorithm
  if(a%b==0)return b;
  else return get_G(b,a%b);
}

int main(){

  int n,a[1000];
  long long L;
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  L=a[0];
  //Å‘åŒö–ñ”‚ğ‹‚ß‚é
  for(int i=1;i<n;i++){
    L=L*a[i]/get_G(L,a[i]);
  }
  cout<<L<<endl;
  return 0;
}
