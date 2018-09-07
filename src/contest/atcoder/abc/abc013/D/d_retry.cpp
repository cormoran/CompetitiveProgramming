#include<iostream>
#include<cmath>
#define rep(i,j) for(i=0;i<j;i++)
using namespace std;
typedef long long ll;

int main()
{
  int n,m;
  ll d;
  cin>>n>>m>>d;
  int a;
  int i,j;
  int revline[n];
  int line[19][n];//20 logn/log2より大きい数
  rep(i,n){
    revline[i]=i;
  }
  rep(i,m)
    {
      cin>>a;
      a--;
      swap(revline[a],revline[a+1]);
    }
  rep(i,n)
    line[0][revline[i]]=i;
  //line[0][i] := 列iの出口の列
  //doubling  
  int log2n=log(d)/log(2);//dより小さい2^kの最大値
  rep(j,log2n+1)rep(i,n)
    line[j+1][i]=line[j][line[j][i]];
  //答え
  rep(j,n)
    {
      int ans=j;
      for(i=log2n+1;i>=0;i--)
	if((d>>i)&1){
	  ans=line[i][ans];
	}
      cout<<ans+1<<endl;      
    }
  return 0;
}
