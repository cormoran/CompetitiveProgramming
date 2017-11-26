#pragma once
#include "./type.hpp"
#include "./point.hpp"
// 整備が不十分
bool P_compX(const Point &a,const Point &b){return a.X()!=b.X() ? a.X()<b.X() : a.Y()<b.Y();}
bool P_compY(const Point &a,const Point &b){return a.Y()!=b.Y() ? a.Y()<b.Y() : a.X()<b.X();}

vector<Point> convex_hull(vector<Point> ps){
  int n=ps.size(),k=0;
  vector<Point> ret(2*n);
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
