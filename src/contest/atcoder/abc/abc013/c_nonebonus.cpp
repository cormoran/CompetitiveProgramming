#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
  long long n,h,a,b,c,d,e;
  cin >>n>>h>>a>>b>>c>>d>>e;
  double val=(double)(e*n-h)/(d+e);
  long long pooronly=ceil(val);//質素な食事のみでやっていったときの質素な食事最低現必要日数
  if(pooronly!=0 && pooronly==val)pooronly+=1;
  if(pooronly<0)pooronly=0;
  if(pooronly>n)pooronly=n;
  long long pooronlycost=pooronly*c;
  long long mincost=pooronlycost;
  long long manpuku=h+d*pooronly-e*(n-pooronly);
  int i;
  bool flg;
     cout <<"pooronly:"<<pooronly <<endl;
  
  //豪華なのを１つだけ、２つだけ・・・・ふやす
  for(i=1;i<=pooronly;i++)
    {
      //豪華なのがi日の場合 i日の質素を豪華で置き換え
      long long ncost=pooronlycost+(a-c)*i,
	   nmanp=manpuku+(b-d)*i;
      
      //消せるだけ質素を消して空腹に置き換え
      bool flg=true;
      int j=0;
      while(flg)
	{
	  j++;
	  if(nmanp-d-e>0 && j+i<=pooronly)
	    {
	      nmanp-=d+e;
	      ncost-=c;
	    }
	  else flg=false;
	  
	}
      mincost=min(mincost,ncost);
      // cout <<"j="<<j<<" ";
      
    }
  cout <<mincost<<endl;

  return 0;
}
