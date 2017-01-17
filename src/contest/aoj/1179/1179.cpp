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


int main()
{

  int n;
  cin>>n;
  rep(i,n){
    int Y,M,D;
    cin>>Y>>M>>D;

    int left_y=999-Y;
    int left_m=10-M;
    int left_d=(Y%3==0||M%2==1 ? 20 : 19)-D;

  }
  
  return 0;
}
