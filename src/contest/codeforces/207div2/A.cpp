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

int main()
{
  int n;cin>>n;
  int c[101];
  int allsum=0;
  rep(i,n){
    cin>>c[i];
    allsum+=c[i];
  }
  int x,y;cin>>x>>y;
  int partsum=0;
  rep(i,n){
    partsum+=c[i];
    if(partsum>=x&&partsum<=y && allsum-partsum<=y &&allsum-partsum>=x){
      cout<<i+2<<endl;
      return 0;
    } 
  }
  cout<<0<<endl;
  return 0;
}
