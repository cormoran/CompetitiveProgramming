#include<iostream>
#include<vector>
//#include<

using namespace std;

#define rep(i,j) for(int i=0;i<(j);i++)

int main(){
  vector< vector<int> > G(4,vector<int>(4));
  rep(i,4){
    rep(j,4){
      int t;cin>>t;
      G[i][j]=t;
    }
  }

  int dx[]={1,0,-1,0};
  int dy[]={0,1,0,-1};

  rep(i,4){
    rep(j,4){
      rep(k,4){
        int x=i+dx[k];
        int y=j+dy[k];
        if(0<=x and x<4 and 0<=y and y<4){
          if(G[i][j]==G[x][y]){
            cout<<"CONTINUE"<<endl;
            return 0;
          }
        }
      }
    }
  }
  cout<<"GAMEOVER"<<endl;
  
  return 0;
}
