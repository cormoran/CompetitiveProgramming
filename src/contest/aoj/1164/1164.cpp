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
#include<complex>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

typedef pair<int,int> pii;


struct Point{
  int x,y;
  Point(int x_,int y_):x(x_),y(y_){};
  const Point operator -(const Point &p)const{
    return Point(x+p.x,y+p.y);
  }
};

int ccw(Point a,Point b,Point c){
  //vector a-->b , a-->c
  b=b-a;
  c=c-a;

  
}

int main()
{
  int m,n;
  cin>>m>>n;
  vector<pii> pt(m);
  vector<pii> pin(n);
  rep(i,m)cin>>pt[i].first>>pt[i].second;
  rep(i,n)cin>>pin[i].first>>pin[i].second;
  
  
  return 0;
}
