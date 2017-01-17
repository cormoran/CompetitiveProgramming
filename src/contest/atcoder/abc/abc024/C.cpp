#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)
int INF=1<<30;

bool is_in_range(pair<int,int> range,int pt){
  if(range.first<=pt and pt<=range.second)return true;
  else return false;
}

int main()
{
  int N,D,K;
  cin>>N>>D>>K;

  vector< pair<int,int> > can_mv(D);
  rep(i,D){
    cin>>can_mv[i].first>>can_mv[i].second;
  }
  
  vector< pair<int,int> > range(K);
  vector<int> gl(K);
  rep(i,K){
    cin>>range[i].first>>gl[i];
    range[i].second=range[i].first;
  }
  vector<int> ans(K,INF);
  rep(d,D){
    rep(i,K){
      if(ans[i]<INF)continue;
      if(is_in_range(can_mv[d], range[i].first) or
         is_in_range(can_mv[d], range[i].second) ){
        
        range[i].first=min(range[i].first,can_mv[d].first);
        range[i].second=max(range[i].second,can_mv[d].second);
      
      }
      if(is_in_range(range[i], gl[i]))ans[i]=d+1;
    }
  }

  rep(i,K){
    cout<<ans[i]<<endl;
  }
  
  return 0;
}
