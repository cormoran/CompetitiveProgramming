/*
  --- 
  title : -B.comp.cpp
  date : 2015-10-23
  status : NULL
  ---
  
  # Memo

  
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


bool solve(){
    int N,A,B;cin>>N>>A>>B;
    string s;
    int d;
    int pos =0;
    rep(i,N){
        cin>>s>>d;
        if(d<A)d=A;
        else if(d>B)d=B;
        pos += (s=="East"?d:-d);
    }

    if(pos==0){
        cout <<0 <<endl;
    }else{
        cout << (pos>0 ? "East " :"West ") << abs(pos)<<endl;
    }

    return false;
}

int main()
{
    while(solve());
    return 0;
}
