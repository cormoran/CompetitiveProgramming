#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<set>
//#include<>
using namespace std;


int main(){
  set<long long> primefacts;
  long long n,i,ans;
  cin>>n;
  ans=n;
  i=2;
  //n‚Ì‘fˆö”‚ð—…—ñ
  while(n>1 && i*i<=n){
    if(n%i==0){
      primefacts.insert(i);
      n/=i;
    } 
    else i+=1;
  }
  if(n!=1)primefacts.insert(n);


  
  //ƒIƒCƒ‰[ŠÖ”
  set<long long>::iterator itr;
  long long  v1=1,v2=1;
  itr=primefacts.begin();
  do{
    v1*=*itr-1;
    v2*=*itr;
  }while(++itr!=primefacts.end());

  ans=llroundl((long double)ans*v1/v2);

  cout<<ans<<endl;
  return 0;
}
