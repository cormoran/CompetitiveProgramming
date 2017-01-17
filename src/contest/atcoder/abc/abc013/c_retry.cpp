//教訓：数学的に解く
#include<iostream>
#include<cmath>
typedef long long ll;
using namespace std;
int main(){
  ll n,h,a,b,c,d,e;
  cin>>n>>h>>a>>b>>c>>d>>e;
  ll mincost=n*a;
  for(ll nd=0;nd<=n;nd++)
    {
      ll var=n*e-(d+e)*nd-h;
      ll nb=ceil((double)var/(b+e));
      if(!(var%(b+e)))nb++;
      if(nb<0)nb=0;
      if(n-nd-nb>=0)
	{
	  ll cost=a*nb+c*nd;
	  if(mincost>cost)mincost=cost;
	}
    }
  cout<<mincost<<endl;

  return 0;
}
