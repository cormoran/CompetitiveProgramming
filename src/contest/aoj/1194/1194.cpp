
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

struct Building{
  int l,r,h;
};

const double EPS = 1E-9;

int r,n;

bool check(vector<Building> &B,double t){
  for(double x=-r;x<=r+EPS;x+=0.5){
    bool flg=false;
    double h=sqrt(r*r-x*x)+t-r;
    rep(i,B.size()){
      if(B[i].l-EPS<=x and x<=B[i].r+EPS and h<=B[i].h+EPS){
        flg=true;
        break;
      }
    }
    if(!flg)return false;
  }
  return true;
}

int main()
{

  while(true){
    cin>>r>>n;
    if(r==0 and n==0)break;
    vector<Building> B(n);
    rep(i,n){
      cin>>B[i].l>>B[i].r>>B[i].h;
    }

    double lr=0,rr=1000;

    while(rr-lr>0.00001){
      double m=(rr+lr)/2;
      if(check(B, m))lr=m;
      else rr=m;
    }
    cout<<lr<<endl;
  }
  
  
  return 0;
}
