#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<complex>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)

#define X real()
#define Y imag()
typedef complex<double> P;
const double EPS=1e-9;

bool P_compX(const P &a,const P &b){
  return a.X!=b.X ? a.X<b.X : a.Y<b.Y;
}

bool P_compY(const P &a,const P &b){
  return a.Y!=b.Y ? a.Y<b.Y : a.X<b.X;
}

//外積
double cross(P a,P b){
  return (a* conj(b)).imag();
}

//内積
double dot(P a,P b){
  return (a* conj(b)).real();
}

int ccw(P a,P b,P c){
  P ab = b-a;
  P ac = c-a;
  if(cross(ab,ac)>0)   return 1;  //反時計回り
  if(cross(ab,ac)<0)   return -1; //時計回り
  //直線上
  if(dot(ab,ac)<0)     return 2;  //c-a-b
  if(norm(ab)<norm(ac))return -2; //a-b-c
  return 0;                       //a-c-b or b==c
}

vector<P> ConvexHull(vector<P> ps){
  int n=ps.size(),k=0;
  vector<P> ret(2*n);
  sort(all(ps),P_compX);

  //上凸包
  for(int i=0;i<n;ret[k++]=ps[i++]){
    while(k>=2 && ccw(ret[k-2],ret[k-1],ps[i]) ==-1) k--; 
  }
  //下凸包
  for(int i=n-2,t=k+1;i>=0;ret[k++]=ps[i--]){
    while(k>=t && ccw(ret[k-2],ret[k-1],ps[i]) ==-1) k--;
  }
  ret.resize(k-1);
  return ret;
}

int main()
{
  int n;
  cin>>n;
  vector<P> ps(n);
  rep(i,n){
    double x,y;
    cin>>x>>y;
    ps[i]=P(x,y);
  }
  vector<P> ans=ConvexHull(ps);
  cout<<ans.size()<<endl;

  reverse(all(ans));
  
  int st_i=0;
  rep(i,ans.size()){
    if(P_compY(ans[i],ans[st_i]))st_i=i;
  }
  
  rep(i,ans.size()){
    cout<<ans[(st_i+i)%ans.size()].X<<" "<<ans[(st_i+i)%ans.size()].Y<<endl;
  }
  return 0;
}
