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
//#include<>
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
  while(true){
    string s;
    cin>>s;
    if(s==".")break;

    string tmp="";
    int cntr=0;
    for(auto ch : s){
      if(ch=='['||ch==']')tmp+=ch;
      else if(ch=='+')cntr++;
      else if(ch=='-')cntr--;
      else if(ch=='?'){
	cntr=0;
	tmp+='A';
      }
      else{
	int chi=ch-'A';
	while(cntr<0)cntr+=26;
	chi=(chi+cntr )% 26;
	tmp+=chi+'A';
	cntr=0;
      }
    }
    
    stack<int> stk;
    // [ ] 対応
    rep(i,tmp.size()){
      if(tmp[i]=='[')stk.push(i);
      else if(tmp[i]==']'){
	int beg=stk.top();stk.pop();
	reverse(&tmp[beg]+1,&tmp[i]);
      }
    }

    string ans="";
    for(auto ch : tmp){
      if(ch=='['||ch==']')continue;
      ans+=ch;
    }
    
    cout<<ans<<endl;
  }

  return 0;
}
