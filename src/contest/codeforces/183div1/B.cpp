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

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)

const double INF=1e10;

long long gcd(long long a,long long b){
  if(a%b==0)return b;
  else return gcd(b,a%b);   
}

ll lca(ll a,ll b){
  return a*b/gcd(a,b);
}


ll n,m,x,y,a,b;


bool check_ratio(ll k){
  return a*k<=n && b*k<=m;
}

ll calc_ratio(){
  ll gcd_ab=gcd(a,b);
  a/=gcd_ab;
  b/=gcd_ab;

  ll l=0,r=INT_MAX;
  while(l+1<r){
    ll m=(l+r)/2;
    if(check_ratio(m))l=m;
    else r=m;
  }
  return l;
}

pair<double,double> calc_center(ll ratio){
  //x
  ll w=a*ratio;

  double lx=(w/2.0);
  double cx=x;
  double rx=n-(w/2.0);

  double lx_d;
  if(lx-w/2.0<0 || lx+w/2.0>n)lx_d=INF;
  else lx_d=abs(lx-x);
  double rx_d;
  if(rx-w/2.0<0 || rx+w/2.0>n)rx_d=INF;
  else rx_d=abs(rx-x);
  double cx_d;
  if(cx-w/2.0<0 || cx+w/2.0>n)cx_d=INF;
  else cx_d=abs(cx-x);
  
  double ans_x=-1;
  if(rx_d<=lx_d && rx_d<=cx_d)ans_x=rx;//順序
  if(cx_d<=rx_d && cx_d<=lx_d)ans_x=cx;
  if(lx_d<=rx_d && lx_d<=cx_d)ans_x=lx;
  if(ans_x<0)assert(0);
  
  //y
  ll h=b*ratio;

  double ly=(h/2.0);
  double cy=y;
  double ry=m-(h/2.0);
  
  double ly_d;
  if(ly-h/2.0<0 || ly+h/2.0>m)ly_d=INF;
  else ly_d=abs(ly-y);
  double ry_d;
  if(ry-h/2.0<0 || ry+h/2.0>m)ry_d=INF;
  else ry_d=abs(ry-y);
  double cy_d;
  if(cy-h/2.0<0 || cy+h/2.0>m)cy_d=INF;
  else cy_d=abs(cy-y);
  
  double ans_y=-1;
  if(ry_d<=ly_d && ry_d<=cy_d)ans_y=ry;//順序
  if(cy_d<=ry_d && cy_d<=ly_d)ans_y=cy;
  if(ly_d<=ry_d && ly_d<=cy_d)ans_y=ly;
  if(ans_y<0) assert(0);
  
  return make_pair(ans_x,ans_y);
}

int main()
{
  
  cin>>n>>m>>x>>y>>a>>b;
  ll ratio =calc_ratio();
  
  pair<double,double> center=calc_center(ratio);

  double hw=a*ratio/2.0;
  double hh=b*ratio/2.0;

  ll lx,rx,ly,ry;
  lx=floor(center.first-hw);
  rx=floor(center.first+hw);
  ly=floor(center.second-hh);
  ry=floor(center.second+hh);

  cout<<lx<<" "<<ly<<" "<<rx<<" "<<ry<<endl;
  
  return 0;
}
