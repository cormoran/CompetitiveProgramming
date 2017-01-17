//eps:非常に小さい数字　を使って　誤差の影響をキャンセルする
#include<iostream>
#include<cmath>
#define rep(i,j) for(i=0;i<j;i++)
using namespace std;

double norm(int x1,int y1,int x2,int y2)
{
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
  int sx,sy,ex,ey,T,V,n;
  cin>>sx>>sy>>ex>>ey>>T>>V>>n;
  int i;
  rep(i,n)
    {
      int x,y;
      cin>>x>>y;
      if(norm(sx,sy,x,y)+norm(x,y,ex,ey)<=T*V)
	{
	  cout<<"YES"<<endl;
	  return 0;
	}
    }
  cout<<"NO"<<endl;

  return 0;
}
