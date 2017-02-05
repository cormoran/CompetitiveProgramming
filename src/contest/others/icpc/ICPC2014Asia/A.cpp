#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
//#include<>
using namespace std;

#define rep(i,j) for(i=0;i<j;(i)++)

int main()
{
  int n,m;
  bool b[15];
  int p[15];
  cin>>n>>m;
  int i,j,k,one_cnt=0,zero_cnt=0;
  rep(i,n){
    char ch;
    cin>>ch;
    if(ch=='1'){
      b[i]=true;
      one_cnt++;
    }
    else{
      b[i]=false;
      zero_cnt++;
    }
  }
  rep(i,m)cin>>p[i];
  
  bool ansline[2][15];
  int cnt[2]={};
  k=0;
  rep(i,m){
    j=0;
    while(j++<p[i]){
      ansline[0][k]=i%2;
      ansline[1][k++]=(i+1)%2;
      cnt[i%2]++;
    }
  }
  
  //  rep(i,n)cout<<ansline[0][i]<<" ";


  //swapしていく
  bool b2[15];
  rep(i,n)b2[i]=b[i];
  int swapcnt=100,swapcnt2=100;
  i=0;j=0;k=0;
  //0..1..0..な順の奴
  if(one_cnt==cnt[1] &&zero_cnt==cnt[0]){
    swapcnt=0;
    while(i<n){
      for(j=i;j<n;j++)if(b[j]==ansline[0][i])break;
      if(j!=i){
	swap(b[i],b[j]);
	swapcnt+=j-i;
      }
      i++;
    }
  }
  i=0;j=0;k=0;
  if(one_cnt==cnt[0] &&zero_cnt==cnt[1]){
    swapcnt2=0;
    while(i<n){
      for(j=i;j<n;j++)if(b2[j]==ansline[1][i])break;
      if(j!=i){
	swap(b2[i],b2[j]);
	swapcnt2+=j-i;
      }
      i++;
    }
  }
  cout<<min(swapcnt,swapcnt2)<<endl;;
  return 0;
}
