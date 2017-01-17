#include<iostream>
using namespace std;
int main(){
  int i,j,k,l;

  for(i=1;i<=9;i++){
    cout <<i<<endl;
    for(j=0;j<=9;j++){
      cout <<i<<j<<endl;
      for(k=0;k<=9;k++){
	cout <<i<<j<<k<<endl;
	if(i==1 && j==0 && k==0)cout <<"1000"<<endl;
      }
    }    
  }

  return 0;
}
