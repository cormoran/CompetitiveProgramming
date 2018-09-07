#include<iostream>
using namespace std;

int main(){
  int n,n_,ng[3],i;
  bool flg=0;

  cin >>n>>ng[0]>>ng[1]>>ng[2];
  i=100;
  if(n!=ng[0]&&n!=ng[1]&&n!=ng[2]){
  while(flg!=1&&i-->0){
    n_=n-3;
    if(n_!=ng[0]&&n_!=ng[1]&&n_!=ng[2]&&n_>=0)n-=3;
    else{
      n_=n-2;
      if(n_!=ng[0]&&n_!=ng[1]&&n_!=ng[2]&&n_>=0)n-=2;
      else{
	n_=n-1;
	if(n_!=ng[0]&&n_!=ng[1]&&n_!=ng[2]&&n_>=0)n-=1;
	else break;
      }
    }
    if(n==0)flg=1;
  }
  }
  if(flg==1)cout << "YES"<<"\n";
  else cout << "NO"<<"\n";
}
