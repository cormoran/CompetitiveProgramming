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


#define rep(i,j) for(i=0;i<j;i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

typedef struct Point
{
  int x;
  int y;
  int d;
  Point(int x_,int y_,int d_):x(x_),y(y_),d(d_){};
}Point ;

 

int solve(bool bd[60][60],int w,int h)
{
  queue<Point> bf;
  int ans=INF;
  bf.push(Point(0,0,1));
  while(!bf.empty())
    {
      Point now=bf.front();bf.pop();
      if(bd[now.y][now.x])continue;
      else
	bd[now.y][now.x]=true;


      if(now.x==2*w-2 && now.y==2*h-2){//ゴール
	ans=now.d;
	break;
      }
      else{
	if(now.x<2*w-2&&!bd[now.y][now.x+1])bf.push(Point(now.x+2,now.y,now.d+1));
	if(now.y<2*h-2&&!bd[now.y+1][now.x] )bf.push(Point(now.x,now.y+2,now.d+1));
	if(now.x>0&& !bd[now.y][now.x-1])bf.push(Point(now.x-2,now.y,now.d+1));
	if(now.y>0&&!bd[now.y-1][now.x])bf.push(Point(now.x,now.y-2,now.d+1));
      }
      /*
      //探索の視覚化
      int i,j;
      rep(i,2*h-1)
	{
	  if(i%2==0){
	  rep(j,2*w-1)
	    if(j%2==0)cout<< (bd[i][j] ? "O" : " ");
	  cout<<endl;
	  }
	}
	  cout<<endl;
      */
    }
  if(ans==INF)ans=0;
  cout<<ans<<endl;
}

int main()
{
  while(true){
    bool bd[60][60]={};//[2h-1][2w-1]
    int w,h;
    cin>>w>>h;
    if(!w && !h)break;
    string hline,wline;
    int i,j;
    getline(cin,hline);//読み捨て
    rep(i,h-1)
      {
	getline(cin,hline);
	getline(cin,wline);
	rep(j,hline.size())
	  bd[i*2][j]= (hline[j]=='1' ? true:false);
	rep(j,wline.size())
	  bd[i*2+1][j]= (wline[j]=='1' ? true:false);
	//      cout<<"hline : "<<hline<<endl;
	//      cout<<"wline : "<<wline<<endl;
      }
    i=h-1;
    getline(cin,hline);
    rep(j,hline.size())
      bd[i*2][j]= (hline[j]=='1' ? true:false);
    
    /*
    rep(i,2*h-1)
      {
	rep(j,2*w-1)
	  cout<<bd[i][j]<<" ";
	cout<<endl;
      }
    */
 
    //探索
    solve(bd,w,h);
  }
    return 0;
    
}
