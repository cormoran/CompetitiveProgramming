#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
using namespace std;

#define rep(i,j) for(i=0;i<j;(i)++)

int main()
{
  int a,b,n;
  cin>>a>>b;
  cin>>n;
  int c1,c2,v;
  if(a<b){
    v=a;a=b;b=v;
  }
  int i;
  double sumdev1=(a+b)*(a-b),sumdev2=(a+b)*(b-a);
  rep(i,n){
    cin>>c1>>c2;
    if(c1<c2){
      v=c1;c1=c2;c2=v;
    }
    double j;
    bool flg=false;
    for(j=0;j<=3.1415 /2;j+=0.001){
      if(c1>=a*sin(j)+b*cos(j) && c2>=a*cos(j)+b*sin(j)){
	cout<<"YES"<<endl;
	flg=true;
	break;
      }
    }
    if(!flg)cout<<"NO"<<endl;
  }
  return 0;
}
