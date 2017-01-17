/*
座標から面積
a=(x1,y1) b=(x2,y2)　とすると
S= a*b*sin∆AOB = a*b*√(1-cos^2 ∆AOB) = √( (ab)^2 - (a,b)^2 ) =...= √((x1*y2-x2*y1)^2)
*/
#include<iostream>
#include<iomanip>
#include<cmath>
#define rep(i,j) for(i=0;i<j;i++)
using namespace std;

int main(){
  int n,i,cnt=1;
  while(true){
    cin >> n;
    if(!n)break;
    int vertices_x[n];
    int vertices_y[n];
    double area=0;
    rep(i,n){
      cin >> vertices_x[i] >> vertices_y[i];
    }
    rep(i,n-1){
      area+=vertices_x[i]*vertices_y[i+1]-vertices_x[i+1]*vertices_y[i];
    }
    area+=vertices_x[n-1]*vertices_y[0]-vertices_x[0]*vertices_y[n-1];
    cout << cnt++<<" "<<fixed<<setprecision(1)<<abs(area/2)<<endl;
  }

  return 0;
}
