#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
//#include<functional>
#include<algorithm>
//#include<>

using namespace std;


int main(){
  vector<int> cost;
  long n;
  int m,v;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>v;
    cost.push_back(v);
  }
  long dp[50001];//dp[i]:=�~�����̂ɕK�v�ȃR�C���̍ŏ�����
  for(long i=0;i<=n;i++)dp[i]=n+1;
  dp[0]=0;
  for(vector<int>::iterator itr=cost.begin();itr!=cost.end();itr++){
    //cout<<"1!";
    for(long i=*itr;i<=n;i++)
      dp[i]=min(dp[i],dp[i-*itr]+1);
  }
  cout<<dp[n]<<endl;
  return 0;
}

