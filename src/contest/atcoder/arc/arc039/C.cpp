#include<iostream>
#include<vector>
#include<map>

using namespace std;

typedef long long i64;typedef int i32;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//10E10
typedef pair<int,int> pii;

int main()
{
  int K;
  cin>>K;
  string s;
  cin>>s;

  map<pii,pii> mp[4];

  int dx[]={1,0,-1,0};
  int dy[]={0,1,0,-1};

  //rep(i,4)
  // mp[i][make_pair(0,0)]=make_pair(0,0);
  
  pii now=make_pair(0, 0);
  rep(i,s.size()){
    int dir;
    switch(s[i]){
      case 'L':
        dir=2;
        break;
      case 'R':
        dir=0;
        break;
      case 'U':
        dir=1;
        break;
      case 'D':
        dir=3;
        break;
    }

    rep(i,4){
      if(i!=dir)
        mp[i][now]=make_pair(now.first+dx[i],now.second+dy[i]);
    }
    
    pii np=now;
    np.first+=dx[dir];
    np.second+=dy[dir];
    while(mp[dir].find(np)!=mp[dir].end())np=mp[dir][np];

    now=mp[dir][now]=np;
    
    //cout<<now.afirst<<" "<<now.second<<endl;
  }
  cout<<now.first<<" "<<now.second<<endl;
  
  return 0;
}
