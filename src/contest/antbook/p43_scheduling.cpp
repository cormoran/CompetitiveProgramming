#include<cstdio>
#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;

#define rep(i,j) for(i=0;i<j;i++)

typedef pair<int,int> Pii;



#define MAX_N 100000
int n;
Pii itv[MAX_N];

int main()
{
  cin>>n;
  int i;
  rep(i,n)cin>>itv[i].second;
  rep(i,n)cin>>itv[i].first;
  sort(itv,itv+n);

  int ans=0,t=0;
  rep(i,n){
    if(itv[i].second>=t){
      ans++;
      t=itv[i].first;
    }
  }
  cout<<ans<<endl;

  return 0;
}
