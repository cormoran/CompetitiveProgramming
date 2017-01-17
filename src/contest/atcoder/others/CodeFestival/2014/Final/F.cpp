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

long long get_G(long long a,long long b){
  //Eucledean algorithm
  if(a%b==0)return b;
  else return get_G(b,a%b);
}

bool is_conf(ll a,ll b,ll c)
{
  //aとcの最大公約数を求める
  

}

int main()
{
  long N;
  cin>>N;
  vector<ll> B;
  long i;
  B.push_back(0);
  rep(i,N)
    {
      ll templ;
      cin>>templ;
      B.push_back(templ);
    }
  //B[0]=B[B.size()-1];
  B.push_back(B[0]);
  B.push_back(B[1]);
  //Bは1からになる

  ll ans=0;
  bool bad[N+1]={};
  rep(i,N)
    {
      if(i==0)continue;
      if(B[i]%get_G(B[i-1],B[i+1]))bad[i]=true;
    }
  rep(i,N)
    {
      if(bad[i]&&(bad[i+1]))
	{
	  bad[i]=false;
	  bad[i+1]=false;
	  ans++;
	}
      else if (bad[i]&&bad[i+2])
	{
	  bad[i]=false;
	  bad[i+2]=false;
	  ans++;
	}
      else if(bad[i])ans++;
    }
  cout<<ans<<endl;


  return 0;
}
