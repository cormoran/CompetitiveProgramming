#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
//#include<>
using namespace std;

typedef long long int64;
typedef int int32;
typedef char int8;
typedef int32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

int a(){
long long n,i;
cin>>n;
cout<<n<<":";
i=2;
while(n>1 && i*i<=n){
  if(n%i==0){
    cout<<" "<<i;
    n/=i;
        
  }
  else i+=1;
    
 }
if(n!=1)cout<<" "<<n;
cout<<endl;
}

int main()
{
  int64 a,b;cin>>a>>b;
  if(a==b){
    cout<<"infinity"<<endl;
    return 0;
  }
  if(a<b){
    cout<<0<<endl;
    return 0;
  }
  int64 ans=0,i;
  for(i=1;i*i<a-b;i++){
    if((a-b)%i==0){
      if(i>b)ans++;
      if((a-b)/i>b)ans++;
    }
  }
  if(i*i==a-b && i>b)ans++;
  cout<<ans<<endl;

  return 0;

}


















