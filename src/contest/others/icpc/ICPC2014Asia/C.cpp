#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<utility>
//#include<>
using namespace std;

#define rep(i,j) for(i=0;i<j;(i)++)

int main()
{
  int N,m;
  cin >>N>>m;
  int i;
  pair<int,int> restricts[500],restricts_d_c[500];//(ci,di)と(di,ci)
  rep(i,m){
    cin>>restricts[i].first>>restricts[i].second;
    restricts_d_c[i].first=restricts[i].second;
    restricts_d_c[i].second=restricts[i].first;
  }
  sort(restricts,restricts+m);
  sort(restricts_d_c,restricts_d_c+m);
  int line[1002]={};
  line[0]=1;
  i=0;
  int start,end,j;
  while(i<m){
    start=restricts[i].first;
    end=restricts[i].second;
    i++;
    for(;i<m;i++)
      if(restricts[i].first<=end && end<restricts[i].second)
	end=restricts[i].second;
      else if(end<restricts[i].first)
	break;
    line[start]+=1;
    line[start+1]+=1;
    line[end]-=1;
    line[end+1]-=1;
  }
  int ans=line[0];
  rep(i,N){
    line[i+1]+=line[i];
    ans+=line[i+1];
    //cout<<line[i+1]<<" ";
  }
  
  cout<<ans<<endl;

  return 0;
}
