#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
#define rep(i,j) for(i=0;i<j;i++)
int n,k;

int main()
{
  vector <long> winners;
  vector <long> winners2;
  cin >>n>>k;
  long long a[n][k];
  bool wflg[n][k];
  int i,j,l;
  rep(i,n)rep(j,k)wflg[i][j]=0;
  rep(i,n)rep(j,k)cin>>a[i][j];
  int val[n];//各回での確定人数
  int sval=0;
  rep(i,n)
    {
      if((double)(k-i)/n>=1)
	val[i]=k/n+1;
      else
	val[i]=k/n;
      //第i回予選で通過する人を出力
      rep(j,val[i])
	{
	  if(find(winners.begin(),winners.end(),a[i][j])==winners.end())
	    {
	      winners.push_back(a[i][j]);//val番目までは確定
	      winners2.push_back(a[i][j]);//val番目までは確定
	    }
	  
	}
      sval+=val[i];
      int dec=min(sval-winners.size(),k-winners.size());//確定できる人数
      int num=0;
      bool flg1=0;
      for(l=val[i];l<k;l++){
	for(j=0;j<=i;j++)
	  {
	    //	    cout <<"t "<<a[j][l]<<"o"<<(find(winners.begin(),winners.end(),a[j][l])>=winners.end()) <<" ";
	    
	    if(dec>0 && !wflg[j][l] && find(winners.begin(),winners.end(),a[j][l])>=winners.end())
	      {
		wflg[j][l]=true;
		num++;
		winners.push_back(a[j][l]);
		winners2.push_back(a[j][l]);
		if(num==dec)
		  {
		    flg1=1;
		    break;
		  }
	      }
	  }
	if(flg1)break;
      }
      sort(winners2.begin(),winners2.end());
      if(winners2.size()>0)rep(j,winners2.size()-1)cout<<winners2.at(j)<<" ";
      if(winners2.size()>0)cout <<winners2.at(winners2.size()-1)<<endl;
      else cout <<endl;
      winners2.clear();
    }
    
return 0;
}
