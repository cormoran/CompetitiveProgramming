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

typedef long long ll;
typedef pair<int,int> Pii;
#define rep(i,j) for(i=0;i<j;i++)
#define rev_rep(i,j) for(i=j;i>=0;i—-)


int main()
{
  long double p;
  long double n;
  cin>>p>>n;
  printf("%.10Lf\n",0.5-pow(1-2*p,n)/2);
  return 0;
}
