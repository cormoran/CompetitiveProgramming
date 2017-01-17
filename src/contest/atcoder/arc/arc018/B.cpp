#include<iostream>
#include<algorithm>
#include<vector>

#define rep(i,j) for(int i=0;i<(j);i++)
using namespace std;

bool check(pair<int,int> p1,pair<int,int> p2,pair<int,int> p3){
  long long v1x,v1y,v2x,v2y;
  v1x=p3.first-p1.first;
  v2x=p2.first-p1.first;

  v1y=p3.second-p1.second;
  v2y=p2.second-p1.second;

  long long S2=v1x*v2y-v2x*v1y;
  S2=abs(S2);
  if(S2==0)return false;
  if(S2%2==0)return true;
  else return false;
}

int main(){
  int N;
  cin>>N;
  vector< pair<int,int> > v(N);
  rep(i,N){
    cin>>v[i].first>>v[i].second;
  }

  int cnt=0;
  rep(i,N){
    for(int j=i+1;j<N;j++){
      for(int k=j+1;k<N;k++){
        if(check(v[i],v[j],v[k]))cnt++;
      }
    }
  }
  cout<<cnt<<endl;
  
}
