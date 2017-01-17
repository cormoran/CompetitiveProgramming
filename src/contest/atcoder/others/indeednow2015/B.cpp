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

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//10E10

int main()
{
  string ind = "indeednow";

  int n;cin>>n;

  rep(i,n){
    string s;
    bool ans=true;
    cin>>s;
    if(s.size()!=ind.size()){
      ans=false;
    }
    else{
      for(auto c : ind){
	int index=s.find(c);
	if(index==string::npos){ans=false;break;}
	else s[index]=' ';
      }
    }
    cout<< (ans ? "YES" : "NO")<<endl;
  }
  
  return 0;
}
