#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  long long  n,m;
  cin>>n>>m;
  long long a,b,c,dif;
  for(b=0;b<=1;b++){
    dif=m-3*b-2*(n-b);
    if(dif>=0 && dif%2==0){
      c=dif/2;
      a=n-b-c;
      if(a>=0){
	printf("%lld %lld %lld\n",a,b,c);
	return 0;
      }
    }
  }
  
  printf("%d %d %d\n",-1,-1,-1);
  return 0;
}
