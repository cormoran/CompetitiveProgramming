#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<cstdint>
#include<cassert>
#include<sstream>
using namespace std;

typedef int64_t i64;typedef int32_t i32;
typedef int16_t i16;typedef int8_t i8;
typedef uint64_t ui64;typedef uint32_t ui32;
typedef uint16_t ui16;typedef uint8_t ui8;

typedef i32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//=10E10

struct ns{
  string s;
  bool operator<(const ns &r)const{
    return (s.size()==r.s.size() ? s<r.s :s.size()>r.s.size());
  }
};

int main()
{
  i32 n;
  typedef pair<int,int> pii;
  vector<vector<pii> > vect(1000001);//[b,index]
  cin>>n;
  i32 lastt=0;
  rep(i,n){
    i32 a,b;cin>>a>>b;
    vect[a].push_back(make_pair(b,i+1));
    lastt=max(lastt,b);
  }

  ns ans;
  ans.s="";
  
  vector<ns> dp(1000001,(ns){""});  
  repeat_eq(i,0,lastt){
    if(i!=0)
      dp[i]=min(dp[i],dp[i-1]);

    cout<<i<<" : "<<dp[i].s<<endl;
    
    ans=min(ans,dp[i]);
    for(auto item : vect[i]){
      stringstream ss;
      ss<<item.second;
      ns temp=dp[i];temp.s.append(ss.str());
      dp[item.first]=min(dp[item.first],temp);
    }
  }

  cout<<ans.s.size()<<endl;
  rep(i,ans.s.size()-1){
    cout<<ans.s[i]<<" ";
  }
  cout<<ans.s.back()<<endl;

  return 0;
  
}
