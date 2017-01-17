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
  int n,t;cin>>n>>t;
  t--;
  int now=0;
  bool flg=false;
  rep(i,n-1){
    int temp;
    cin>>temp;
    if(now==i){
      now=i+temp;
      if(now==t)flg=true;
      //cout<<"v : "<<now<<endl;
    }
  }
  cout<<(flg ? "YES":"NO")<<endl;
  return 0;
}
