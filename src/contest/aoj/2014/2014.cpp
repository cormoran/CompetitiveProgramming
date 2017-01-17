//#include<bits/stdc++.h>
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

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)

#define W    0b01
#define B    0b10
#define WW 0b0100
#define BB 0b1000


const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

int w,h;

void rec(vector< vector<unsigned char> > &s,unsigned char symbol,int x,int y){
  rep(dir,4){
    int nx =x+dx[dir];
    int ny =y+dy[dir];
    if(0<=nx and nx <w and 0<=ny and ny<h){
      if(!(s[ny][nx]&WW) && !(s[ny][nx]&BB)){
        if((s[ny][nx]&symbol) ==0){
          s[ny][nx]|=symbol;
          rec(s,symbol,nx,ny);
        }
      }
    }
  }
}


int main()
{
  while(true){
    cin>>w>>h;
    if(w==0 and h==0)break;
    vector<string> s(h);
    vector< vector<unsigned char> > flgs(h,vector<unsigned char>(w,0));
    rep(i,h)cin>>s[i];
    rep(i,h){
      rep(j,w){
        if(s[i][j]=='.')flgs[i][j]=0;
        if(s[i][j]=='W')flgs[i][j]=WW;
        if(s[i][j]=='B')flgs[i][j]=BB;
      }
    }

    rep(y,h){
      rep(x,w){
        if(flgs[y][x]&WW)rec(flgs,W,x,y);
        else if(flgs[y][x]&BB)rec(flgs,B,x,y);
      }
    }

    int white=0,black=0;
    rep(y,h){
      rep(x,w){
        if(!(flgs[y][x]&WW) && !(flgs[y][x]&BB)){
          if((flgs[y][x]&W) && (flgs[y][x]&B)){
            //putchar('A');
            continue;
          }
          else if(flgs[y][x]&W){
            //putchar('W');
            white++;
          }
          else if( flgs[y][x]&B){
            //putchar('B');
            black++;
          }
        }
        else{
          //putchar(flgs[y][x]&WW ? 'W' : 'B');
          ;
        }
      }
      //puts("");
    }

    cout<<black<<" "<<white<<endl;
    
  }
  return 0;
}
