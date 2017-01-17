#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
//#include<>
using namespace std;

typedef long long int64;
typedef int int32;
typedef char int8;
typedef int32 int__;
struct point{
  int x,y;
  point(int x_,int y_){x=x_;y=y_;}
};
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define rev_rep(i,j,k) for(int__ i=(j)-1;i>=k;i--)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10
vector< vector<int> > Map;

int main()
{
  int R,C;cin>>R>>C;
  int rs,cs,rg,cg;cin>>rs>>cs>>rg>>cg;
  int N;cin>>N;
  vector<int> temp;
  temp.resize(C+2,0);
  Map.resize(R+2,temp);
  rep(i,N){
    int r,c,h,w;cin>>r>>c>>h>>w;
    rep(j,h){
      Map[r+j][c]++;
      Map[r+j][c+w]--;
    }
  }
  rep(i,R)rep(j,C)Map[i+1][j+1]+=Map[i+1][j];

  //rep(i,R+2){rep(j,C+2)cout<<Map[i][j]<<" ";puts("");}

  if(Map[rs][cs]<=0||Map[rg][cg]<=0){cout<<"NO"<<endl;return 0;}
  
  stack<point> st;
  st.push(point(rs,cs));
  while(!st.empty()){
    point p=st.top();st.pop();
    if(p.x==cg&&p.y==rg){
      cout<<"YES"<<endl;return 0;
    }
    Map[p.y][p.x]=0;
    if(Map[p.y][p.x+1]>0)st.push(point(p.x+1,p.y));
    if(Map[p.y][p.x-1]>0)st.push(point(p.x-1,p.y));
    if(Map[p.y+1][p.x]>0)st.push(point(p.x,p.y+1));
    if(Map[p.y-1][p.x]>0)st.push(point(p.x,p.y-1));
  }
  cout<<"NO"<<endl;
  return 0;
}



