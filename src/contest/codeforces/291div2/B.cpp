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

long long get_G(long long a,long long b){
  //Eucledean algorithm
  if(a%b==0)return b;
  else return get_G(b,a%b); 
}

int main()
{
  int n,x,y;cin>>n>>x>>y;
  typedef pair<int,int> pii;
  vector<pii> slope;
  bool Tate=false,Yoko=false;
  bool orig=false;
  rep(i,n){
    int a,b;
    cin>>a>>b;
    a-=x;b-=y;
    if(a==0 and b==0){
      orig=true;continue;
    }
    if(a==0){
      Tate=true;continue;
    }
    if(b==0){
      Yoko=true;continue;
    }
    int gcd=get_G(abs(b),abs(a));
    //printf("a %d b %d gcd %d\n",a,b,gcd);
    a/=gcd;
    b/=gcd;
    if(a<0){
      a*=-1;
      b*=-1;
    }
    slope.push_back(make_pair(a,b));
  }
  /*
  rep(i,slope.size()){
    cout<<slope[i].first<<" "<<slope[i].second<<endl;
  }
  */
  sort(all(slope));
  slope.erase(unique(all(slope)),slope.end());



  
  int modif=0;
  if(Tate)modif+=1;
  if(Yoko)modif+=1;
  if(slope.size()+modif==0 && orig)modif+=1;
  
  cout<<slope.size()+modif<<endl;
  
  return 0;
}










