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
  int a,b,c;cin>>a>>b>>c;
  if(a+b==c&&a-b==c)cout<<"?"<<endl;
  else if(a+b==c)cout<<"+"<<endl;
  else if(a-b==c)cout<<"-"<<endl;
  else cout<<"!"<<endl;
  return 0;
}

















