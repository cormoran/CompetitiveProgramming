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
//#include<cstdint>
using namespace std;

typedef long long i64;typedef int i32;


typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

class InfiniteString{
public:
  long long gcd(long long a,long long b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
  }
  
  string equal(string s,string t){
    i64 lcm=s.size()*t.size()/gcd(s.size(), t.size());
    string ss="",tt="";
    rep(i,lcm/s.size()){
      ss+=s;
    }
    rep(i,lcm/t.size()){
      tt+=t;
    }


    if(ss==tt)return "Equal";
    else return "Not equal";

    
    
  }
  
};
