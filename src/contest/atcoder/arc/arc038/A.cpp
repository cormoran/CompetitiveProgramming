#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<string>
#include<cmath>
#include<cassert>
#include<map>
using namespace std;

typedef long long i64;typedef int i32;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)


int main()
{
  int N;
  cin>>N;
  vector<int> v(N);
  rep(i,N){
    cin>>v[i];
  }
  sort(all(v),greater<int>());
  int ans=0;
  rep(i,N){
    if(i%2==0)ans+=v[i];
  }
  cout<<ans<<endl;
  return 0;
}
