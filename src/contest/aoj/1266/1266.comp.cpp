/*
  --- 
  title : -1266.comp.cpp
  date : 2015-10-30
  status : NULL
  ---
  
 */

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cassert>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()


double dist(double x,double y,double z){
    return sqrt(x*x+ y*y + z*z);
}

double my_cos(double a,double b,double c){
    return (b*b+c*c-a*a)/(2*b*c);
}

bool solve(){
    int n;
    cin>>n;
    if(n==0)return false;
    vector<double> sx(n),sy(n),sz(n);
    rep(i,n){
        cin>>sx[i]>>sy[i]>>sz[i];
    }
    int m;
    cin>>m;
    vector<double> tx(m),ty(m),tz(m),phi(m);
    rep(i,m){
        cin>>tx[i]>>ty[i]>>tz[i]>>phi[i];
    }

    vector<bool> flg(n,false);
    
    rep(t_i,m){
        double dt = dist(tx[t_i],ty[t_i],tz[t_i]);
        rep(s_i,n){
            double ds = dist(sx[s_i],sy[s_i],sz[s_i]);
            double dts = dist(sx[s_i]-tx[t_i],sy[s_i]-ty[t_i],sz[s_i]-tz[t_i]);
            double cos_theta = my_cos(dts, ds, dt);
            double cos_phi = cos(phi[t_i]);
            //double sin_phi = sin(phi[t_i]);
            
            if(cos_theta > abs(cos_phi)){
                flg[s_i]=true;
                //cout << "tele "<<t_i<<" s "<<s_i<<endl;
            }
            
        }
    }
    
    int ans =0;
    rep(i,n){
        if(flg[i])ans++;
    }
    cout <<ans<<endl;
    
    return true;
}

int main()
{
    while(solve());
    return 0;
}
