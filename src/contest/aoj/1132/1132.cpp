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
#include<cstdint>
#include<map>
using namespace std;

typedef int64_t i64;typedef int32_t i32;
typedef int16_t i16;typedef int8_t i8;
typedef uint64_t ui64;typedef uint32_t ui32;
typedef uint16_t ui16;typedef uint8_t ui8;

typedef pair<double,double> pdd;
typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//10E10

double getDistance2(double x1,double y1,double x2,double y2){
  return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}


//それぞれの点を中心とする半径１の円の交点
pair<pdd,pdd> getInterSection(double x1,double y1,double x2,double y2,double dist){
  double sin_a = (y1-y2)/dist;//中心間直線傾斜
  double cos_a = (x1-x2)/dist;

  double h=sqrt(1*1-dist/2*dist/2);

  double sin_b= h/1;//交点間直線傾斜
  double cos_b= dist/2 /1;

  pdd is1,is2;
  is1.second = sin_a*cos_b+cos_a*sin_b +y2; //sin(a+b)
  is1.first= cos_a*cos_b-sin_a*sin_b +x2;

  is2.second = sin_a*cos_b+cos_a*sin_b + y2; //sin(a-b)
  is2.first= cos_a*cos_b+sin_a*sin_b +x2;

  return make_pair(is1,is2);
}

int main()
{

  while(1){
    int a,b,c,d;cin>>a>>b>>c>>d;
    pair<pdd,pdd> an=getInterSection(a,b,c,d,sqrt(getDistance2(a,b,c,d)));
    printf("%f %f : %f %f\n",an.first.first,an.first.second,an.second.first,an.second.second);
    
  }
  
  
  while(true){
    int N;
    cin>>N;
    if(N==0)break;
    vector<double> Px(N),Py(N);
    rep(i,N)cin>>Px[i]>>Py[i];


    int ans=0;
    vector<pdd> interSections;
    //各点を中心とする円の交点全列挙
    rep(i,N)repeat(j,i+1,N){
      double dist2=getDistance2(Px[i],Py[i],Px[j],Py[j]);
      if(dist2<=4){
	pair<pdd,pdd> tmp=getInterSection(Px[i],Py[i],Px[j],Py[j],sqrt(dist2));
	interSections.push_back(tmp.first);
	interSections.push_back(tmp.second);
      } 
    }
    
    int ans_t=0;
    rep(i,interSections.size()){
      rep(j,N){
	if(getDistance2(interSections[i].first,interSections[i].second,Px[j],Py[j])>=1)
	  ans_t++;
      }
      ans=max(ans,ans_t);
    }
    
    cout<<ans<<endl;
  }

  
  return 0;
}










