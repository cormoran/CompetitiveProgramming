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

#define repeat(i,j,k) for(i=(j),i<(k);i++)
#define repeat_eq(i,j,k) for(i=(j),i<=(k);i++)
#define rev_rep(i,j,k) for(i=(j)-1;i>=k;i--)
#define rep(i,j) for(i=0;i<j;i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

int main()
{
  int n,num,sum=0;
  cin>>n;
  num=n;
  int i;
  rep(i,n)
    {
      int temp;cin>>temp;
      if(!temp)num--;
      sum+=temp;
    }
  if(num)
    cout<<ceil((double)sum/num)<<endl;
  else
    cout<<0<<endl;
  return 0;
}










