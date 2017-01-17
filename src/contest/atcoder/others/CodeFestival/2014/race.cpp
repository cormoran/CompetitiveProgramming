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
  int n;
  cin>>n;
  bool map[101][101]={};
  int i,j;
  rep(i,n)
    rep(j,n)
    {
      char a;
      cin>>a;
      if(a=='X'||a=='Y')
	map[i][j]=true;
    }
  int X=0,Y=0;
  rep(i,n)
    rep(j,n)
    {
      if(map[j][i])X+=j;
    }
  rep(i,n)
    rep(j,n)
    {
      if(map[n-j-1][n-i-1])Y+=j;
    }
  if(X==Y)
    cout<<"Impossible"<<endl;
  else if(X>Y)cout<<"X"<<endl;
  else cout<<"Y"<<endl;
  return 0;
}
