#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll ;
typedef pair<int,int> pii;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
template<class T>
using Mat = vector<vector<T>>;

#define X first
#define Y second
#define mp make_pair
const int INF = 1<<30;
 
int H,W,T;
vector< string > G;
pii st;

struct State{
    pii pos;
    ll cost;
    bool operator<(const State &l)const{
        return cost>l.cost;
    }
};


bool C(int x){
    priority_queue<State> que;
    Mat<bool> visited(H,vector<bool>(W,false));
    visited[st.Y][st.X]=true;
    
    que.push({st,0});
    const int dx[]={1,0,-1,0};
    const int dy[]={0,1,0,-1};
    
    while(!que.empty()){
        pii now = que.top().pos;
       ll cost = que.top().cost;
        que.pop();
        if(G[now.Y][now.X] == 'G')return true;
        
        rep(d,4){
            pii nxt = {now.X+dx[d] , now.Y+dy[d]};
            if(0<=nxt.X and nxt.X<W and 0<=nxt.Y and nxt.Y < H
               and !visited[nxt.Y][nxt.X]){
                ll nxt_time = cost + (G[nxt.Y][nxt.X]=='#' ? x : 1);
                if(nxt_time <= T){
                    que.push({nxt,nxt_time});
                    visited[nxt.Y][nxt.X]=true;
                }
            }
        }
    }
    return false;
}

int main()
{
  cin>>H>>W>>T;
  G.resize(H);
  rep(y,H){
    cin>>G[y];
    rep(x,W){
      if(G[y][x]=='S')st=mp(x,y);
    }
  }

  int l=1,r=1E9+1;
  while(l+1<r){
      int mid = (l+r)/2;
      if(!C(mid))r=mid;
      else l=mid;
  }
  cout<<l<<endl;
  
  return 0;
}
