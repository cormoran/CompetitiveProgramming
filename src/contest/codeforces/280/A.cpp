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

#define rep(i,j) for(int i=0;i<j;i++)
#define repeat(i,j,k) for(int i=(j),i<(k);i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

int main()
{
  int n,i=1;
  cin>>n;
  n*=6;
  while(true){
    if(i*(i+1)*(i+2)>n)break;
    i++;
  }
  cout<<i-1<<endl;
  return 0;
}

















