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
  int n,m;cin>>n>>m;
  vector< pair<string,string> > correspond;
  correspond.resize(m);
  rep(i,m)
    cin>>correspond[i].first>>correspond[i].second;
  sort(all(correspond));

  pair<string,string> sample;
  sample.second="";
  rep(i,n){
    string fword;cin>>fword;
    sample.first=fword;
    string sword=lower_bound(all(correspond),sample)->second;

    if(i!=n-1)
      cout<< (fword.size()<=sword.size()?fword:sword)<<" ";
    else
      cout<< (fword.size()<=sword.size()?fword:sword)<<endl;
  }
  
  return 0;
}










