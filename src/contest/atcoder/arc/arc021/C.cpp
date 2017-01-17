#include<iostream>
#include<vector>
#include<queue>
//#include<

using namespace std;

#define rep(i,j) for(int i=0;i<(j);i++)

int main(){

  int K,N;
  cin>>K>>N;
  vector<int> A(N);
  vector<int> D(N);
  priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > que;
  rep(i,N){
    cin>>A[i]>>D[i];
    que.push(make_pair(A[i],i));
  }

  long long ans=0;
  rep(i,K){
    long long cost=que.top().first;
    int idx=que.top().second;
    que.pop();
    ans+=cost;
    que.push(make_pair(cost+D[idx],idx));
  }
  cout<<ans<<endl;
  return 0;
}
