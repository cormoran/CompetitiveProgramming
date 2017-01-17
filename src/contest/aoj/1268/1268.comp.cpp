// -- create markdown --
/*
--- 
  title : -1268.comp.cpp
  date : 2015-11-05
  status : NULL
---
  # Memo

  
 */
// -- start code --

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cassert>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<array>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()
typedef array<array<char,3>,3> puzzle;

// Wn R   Wr B
//   BWB    RWR
//    R      B
// Bn R   Br W
//   WBW    RBR
//    R      W
// Rn W   Rr B
//   BRB    WRW
//    W      B
const char Wn = 'W', Wr = 'w';
const char Bn = 'B', Br = 'b';
const char Rn = 'R', Rr = 'r';
const char E  = 'E';

struct State{
    puzzle g;
    int ex,ey;
    int cnt;
};

char next_row(char now){
    switch(now){
        case Wn : return Rn;
        case Wr : return Br;
        case Bn : return Rr;
        case Br : return Wr;
        case Rn : return Wn;
        case Rr : return Bn;
        default : assert(0);
    }
}

char next_colm(char now){
    switch(now){
        case Wn : return Bn;
        case Wr : return Rr;
        case Bn : return Wn;
        case Br : return Rn;
        case Rn : return Br;
        case Rr : return Wr;
        default : assert(0);
    }
}

bool does_equal_appearance(const puzzle &l,const puzzle &r){
    rep(y,3)rep(x,3){
        if(l[y][x] != r[y][x]
           and l[y][x] + r[y][x] != 7) return false;
    }
    return true;
}

bool solve(){
    State ini_state;
    cin>>ini_state.ey>>ini_state.ex;
    ini_state.ey--;ini_state.ex--;
    rep(y,3)rep(x,3)ini_state.g[y][x] = Wn;
    ini_state.g[ini_state.ey][ini_state.ex] = E;
    ini_state.cnt = 0;
    puzzle goal;
    rep(i,3)rep(j,3){
        char c;cin>>c;
        goal[i][j] = c;
    }
    
    queue<State> que;
    que.push(ini_state);

    const int dx[] = {0,1,0,-1};
    const int dy[] = {1,0,-1,0};
    
    while(not que.empty()){
        State now = que.front();que.pop();
        if(does_equal_appearance(now.g, goal)){
            cout << now.cnt <<endl;
            break;
        }

        rep(d,4){
            int nx = now.ex + dx[d];
            int ny = now.ey + dy[d];
            if(0<=nx && nx<3 and 0<=ny && ny<3){
                
            }
        }
        
        
    }
    
    return false;
}

int main()
{
    while(solve());
    return 0;
}
