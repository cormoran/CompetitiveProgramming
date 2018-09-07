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

#define rep(i,j) for(i=0;i<j;i++)
#define repeat(i,j,k) for(i=(j),i<(k);i++)
#define repeat_eq(i,j,k) for(i=(j),i<=(k);i++)
#define rev_rep(i,j,k) for(i=(j)-1;i>=k;i--)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

int n,k;
int box[6][6];
bool rec(int now,int  xsum)
{
  if(now==n)
    return xsum==0;
  int i;
  rep(i,k)
    {
      if(rec(now+1,xsum^box[now][i]))return true;
    }
  return false;
}

int main()
{

  cin>>n>>k;
  int i,j;
  rep(i,n)rep(j,k)
    cin>>box[i][j];

  cout<< (rec(0,0) ? "Found" : "Nothing")<<endl;

  return 0;
}
