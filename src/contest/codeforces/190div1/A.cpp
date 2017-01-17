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

typedef pair<int,int> pii;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

const int dx[4]={0,1,0,-1};
const int dy[4]={-1,0,1,0};

int main()
{
  ll a,b;
  cin>>a>>b;
  string s;
  cin>>s;
  vector<pll> p;
  p.reserve(s.size()+1);
  pll now={0,0};
  p.push_back(now);
  rep(i,(int)s.size()){
    if(s[i]=='U')now.second++;
    else if(s[i]=='D')now.second--;
    else if(s[i]=='R')now.first++;
    else if(s[i]=='L')now.first--;
    //else assert(0);
    if(now==(pll){a,b}){
      cout<<"Yes"<<endl;
      return 0;
    }
    p.push_back(now);
  }

  ll off_x=now.first;
  ll off_y=now.second;
  rep(i,(int)p.size()){
    ll x=p[i].first;
    ll y=p[i].second;
    if(off_x==0 && off_y==0){
      if(a==x && b==y){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
    else if(off_x==0){
      if(a==x && abs(b-y) % off_y == 0 && (b-y) / off_y >= 0){
          cout<<"Yes"<<endl;
          return 0;
      }
    }
    else if(off_y==0){
      if(abs(a-x) % off_x == 0 && b==y && (a-x) / off_x >= 0){
          cout<<"Yes"<<endl;
          return 0;
      }
    }
    else{
      if(abs(a-x) % off_x == 0 && abs(b-y) % off_y == 0){
        ll k=(a-x) / off_x;
        if(k>=0 && k == (b-y) / off_y){
          cout<<"Yes"<<endl;
          return 0;
        }
      }
    }
  }
  cout<<"No"<<endl;
  
  return 0;
}
