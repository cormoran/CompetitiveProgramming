#include<iostream>
using namespace std;
int main(){
  long an[4]={0,0,0,1};
  long n;
  cin>>n;
  switch (n){
  case 1:
  case 2:
    cout<<0<<endl;;
    return 0;
  case 3:
    cout<<1<<endl;
    return 0;
  }
  for(long i=3;i<n;i++){
    an[0]=(an[1]+an[2]+an[3])%10007;
    an[i%3+1]=an[0];
  }
  cout<<an[0]%10007<<endl;
  return 0;
}
