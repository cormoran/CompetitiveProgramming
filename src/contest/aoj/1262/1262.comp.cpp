/*
  file : /1262.comp.cpp
  date : 2015-10-19
  summary :
  {
  入力
  n         0< . <=100   チェックポイント数
  a1 ... an 0< . <=10^4  startからチェックポイントの距離
  b         0< . < 100.0 補給時間
  r v e f   0< . , v-e*(an-1-r)>=0.01 , v-f*r >=0.01 速度パラメータ

  各チェックポイントで何回でも補給可能、
  x=0 から x=an までにかかる時間の最短を求める
  }
  status :
  {
  AC
  }
  memo :
  {
  
  }
 */

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)

bool solve(){
    int n;cin>>n;
    if(n==0)return false;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    double b;
    int r;
    double v,e,f;
    cin>>b>>r>>v>>e>>f;

    vector<double> interval_time(a[n-1]+1);
    interval_time[0]=0;
    rep(x,interval_time.size()-1){
        interval_time[x+1] = interval_time[x];
        if(x>=r)interval_time[x+1] += 1.0/(v - e * (double)(x-r));
        else interval_time[x+1] += 1.0/(v - f * (double)(r-x));
    }
    
    vector<double> DP(n);
    rep(i,n){
        DP[i]=interval_time[a[i]];
        rep(j,i){
            DP[i] = min(DP[i] , DP[j] + interval_time[a[i]-a[j]] + b);
        }
    }
    printf("%.10f\n",DP.back());
    
    return true;
}

int main()
{
    while(solve());
    return 0;
}
