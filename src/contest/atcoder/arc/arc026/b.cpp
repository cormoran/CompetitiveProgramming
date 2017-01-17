#include<iostream>
using namespace std;
 
int main(){
  long long n,i,sum=1;
  cin >> n;
  if(n==1)sum=0;
 
  for(i=2;i*i<n;i++)if(n%i==0)sum+=i+n/i;
 
  if(i*i==n)sum+=i;
 
  if(sum>n)cout<<"Abundant\n";
  else if(sum==n)cout<<"Perfect\n";
  else cout<<"Deficient\n";
 
  return 0;
}
