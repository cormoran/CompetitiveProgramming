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
  int n,k;cin>>n>>k;
  k--;
  vector<int> seq;
  bool flg=false;
  seq.resize(n);
  rep(i,n){
    cin>>seq[i];
    if(i>k && seq[i]!=seq[k])flg=true;
  }
  if(flg){
    cout<<-1<<endl;
    return 0;
  }
  
  int cnt=k;
  for(int i=k-1;i>=0;i--){
    if(seq[i]==seq[k])cnt--;
    else break;
  }
  cout<<cnt<<endl;
  return 0;
}
