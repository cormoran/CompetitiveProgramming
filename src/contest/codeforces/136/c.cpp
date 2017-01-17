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
#define repeat(i,j,k) for(int__ i=(j),i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j),i<=(k);i++)
#define rev_rep(i,j,k) for(int__ i=(j)-1;i>=k;i--)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

int main()
{
  int n;
  cin>>n;
  vector<int64> arry;
  arry.resize(n);
  int maxval=-1,maxps=-1;
  rep(i,n){
    cin>>arry[i];
    if(maxval<arry[i]){
      maxval=arry[i];
      maxps=i;
    }
  }
  if(maxval!=1)
    arry[maxps]=1;
  else
    arry[maxps]=2;
  sort(all(arry));
  rep(i,n-1){
    cout<<arry[i]<<" ";
  }
  cout<<arry[n-1]<<endl;
  return 0;
}
