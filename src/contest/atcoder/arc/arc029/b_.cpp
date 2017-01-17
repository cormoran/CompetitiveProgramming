#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<math>
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
    if(((c1>=a) && (c2>=b) )|| ((c1>=b)&&(c2>=a))){
      cout<<"YES";
    }
    else if(a!=b){
      double cos=(c1*a-c2*b)/sumdev1,sin=(c2*a-c1*b)/sumdev1;
      if(cos*cos>=0.25 && cos>=0 && sin*sin<=0.25 && sin>=0)
	cout<<"YES";
      else cout<<"NO";
      cout<<sin<<" "<<cos;
    }
    else cout<<"NO";
    cout<<endl;
  }
  return 0;
}
