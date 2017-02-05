
#include <cstring>
#include <cmath>
#include <cstdio>
#include <set>
#include <iostream>
 
using namespace std;
 
#define REP(i,n) for(int i=0; i<(int)(n); i++)
 
inline int getInt(){ int s; scanf("%d", &s); return s; }
 
const int _dx[] = {0,1,0,-1};
const int _dy[] = {-1,0,1,0};
#define IN(x,s,g) ((x) >= (s) && (x) < (g))
#define ISIN(x,y,w,h) (IN((x),0,(w)) && IN((y),0,(h)))
 
bool canGo[500][500][4];
int dp[500][500][2];
int h, w;
 
int solve(int x, int y, int rev){
  if(!ISIN(x, y, w, h)) return 1;
  if(dp[y][x][rev] == -2) return 0;
  if(dp[y][x][rev] >= 0) return dp[y][x][rev];
  dp[y][x][rev] = -2;
 
  int ret = 0;
  REP(i,4) if(rev ^ canGo[y][x][i]){
    const int xx = x + _dx[i];
    const int yy = y + _dy[i];
    ret |= solve(xx, yy, 1) && solve(xx, yy, 0);
  }
 
  return dp[y][x][rev] = ret;
}
 
int main(){
  while(true){
    const int h = ::h = getInt();
    const int w = ::w = getInt();
    const int y = getInt();
    const int x = getInt();
 
    if(h + w + y + x == 0) break;
 
    REP(i,h+1){
      REP(j,w){
        const int b = getInt();
        if(i != h) canGo[i][j][0] = !b;
        if(i != 0) canGo[i - 1][j][2] = !b;
      }
      if(i != h){
        REP(j,w+1){
          const int b = getInt();
          if(j != w) canGo[i][j][3] = !b;
          if(j != 0) canGo[i][j - 1][1] = !b;
        }
      }
    }
 
    memset(dp, -1, sizeof(dp));
    puts(solve(x - 1, y - 1, 0) ? "Yes" : "No");
  }
  return 0;
}
 
