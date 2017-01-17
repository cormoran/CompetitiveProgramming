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
//#include<>
using namespace std;

typedef vector< vector<int> > Mat;
typedef pair<int,int> pii;

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

int h,w,c;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int count_same(Mat& vv){
  stack<pii> stk;
  vector<vector<bool> > used(h,vector<bool>(w,false));
  used[0][0]=true;
  stk.push(pii(0,0));

  int ans=0;
  while(!stk.empty()){
    int x=stk.top().second;
    int y=stk.top().first;
    stk.pop();
    ans++;
    rep(i,4){
      int nx=x+dx[i];
      int ny=y+dy[i];
      if( 0<=ny && ny<h && 0<=nx && nx<w ){
	if(vv[ny][nx]==vv[0][0] && !used[ny][nx]){
	  stk.push(pii(ny,nx));
	}
	used[ny][nx]=true;
      }
    }
  }
  return ans;
}

void change(Mat &vv,int col){
  stack<pii> stk;
  vector<vector<bool> > used(h,vector<bool>(w,false));
  
  int precol=vv[0][0];
  vv[0][0]=col;
  used[0][0]=true;
  stk.push(pii(0,0));
  
  while(!stk.empty()){
    int x=stk.top().second;
    int y=stk.top().first;
    stk.pop();
    
    rep(i,4){
      int nx=x+dx[i];
      int ny=y+dy[i];
      if( 0<=ny && ny<h && 0<=nx && nx<w ){
	if(vv[ny][nx]==precol && !used[ny][nx]){
	  vv[ny][nx]=col;
	  stk.push(pii(ny,nx));
	}
	used[ny][nx]=true;
      }
    }
  }
}

int rec(Mat vv,int col,int cnt){
  if(col>0)change(vv,col);

  int ans=0;
  if(cnt==4){
    change(vv,c);
    ans=count_same(vv);    
  }
  else{
    repeat_eq(i,1,6){
      if(vv[0][0]!=i){
	ans=max(ans,rec(vv,i,cnt+1));      	      
      }
    }
  }
  return ans;
}

int main()
{
  while(true){
    cin>>h>>w>>c;
    if(!h && !w && !c)break;
    Mat vv(h,vector<int>(w));
    rep(i,h)rep(j,w)cin>>vv[i][j];
    cout<<rec(vv,-1,0)<<endl;
  }
  return 0;
}
