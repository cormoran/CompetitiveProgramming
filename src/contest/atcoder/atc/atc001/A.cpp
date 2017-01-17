#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<complex>
using namespace std;

typedef complex<double> P;
#define X real()
#define Y imag()

int main(){
  int H,W;
  vector< string > G;
  cin>>H>>W;
  G.resize(H);
  P s,g;
  for(int i=0;i<H;i++){
    cin>>G[i];
    for(int j=0;j<W;j++){
      if(G[i][j]=='s')s=P(j,i);
      else if(G[i][j]=='g')g=P(j,i);
    }
  }

  
  //bfs
  queue< P > que;

  vector< vector<bool> > visited(H,vector<bool>(W,false));

  que.push(s);
  int dx[]={1,0,-1,0};
  int dy[]={0,1,0,-1};
  while(!que.empty()){
    P now = que.front();que.pop();
    
    for(int i=0;i<4;i++){
      P nxt=P(now.X+dx[i],now.Y+dy[i]);
      if(0<=nxt.X and nxt.X<W and 0<=nxt.Y and nxt.Y<H and !visited[nxt.Y][nxt.X]){
        if(G[nxt.Y][nxt.X]=='g'){
          cout<<"Yes"<<endl;
          return 0;
        }
        if(G[nxt.Y][nxt.X]=='.')que.push(nxt);
        visited[nxt.Y][nxt.X]=true;
      }
    }
  }
  cout<<"No"<<endl;
  return 0;
}
