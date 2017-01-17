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
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

template<typename T>
struct Point{
  T x;
  T y;
  bool operator<(const Point<T> &l)const{return x!=l.x ?  x<l.x : y<l.y;}  
};

// p2->p1とp2->p3ベクトルの外積
template<typename T>
inline T Cross_Product(Point<T> p1,Point<T> p2,Point<T> p3){
  return (p1.x-p2.x)*(p3.y-p2.y)-(p1.y-p2.y)*(p3.x-p2.x); 
}

bool is_intersected(int64 a,int64 b,int64 c,Point<double> A,Point<double> B){
  Point<double> P,Q;
  if(b!=0){
      P.x=0;P.y=-(double)c/b;
      Q.x=b;Q.y=-a-(double)c/b;
      return (Cross_Product(A,P,Q)*Cross_Product(B,P,Q)<0 ? true : false );
  }
  else
    return ((-(double)c/a-A.x)*(-(double)c/a-B.x)<0 ? true : false);
}

int main()
{
  Point<double> home,univ;
  cin>>home.x>>home.y;
  cin>>univ.x>>univ.y;
  int n;cin>>n;
  int ans=0;
  rep(i,n){
    int64 a,b,c;cin>>a>>b>>c;
    if(is_intersected(a,b,c,home,univ)==true)ans++;
  }
  cout<<ans<<endl;
  return 0;
}
