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
  int n;
  cin>>n;
  vector<int> s(n);
  rep(i,n)cin>>s[i];
  vector<int> s_r(n);
  
  sort(all(s),greater<int>());
  s_r=s;
  reverse(all(s_r));
  int q;
  cin>>q;

  //  rep(i,n)cout<<s[i]<<" ";

  rep(i,q){
    int k;
    cin>>k;
    k--;

    if(s.front()==0){cout<<0<<endl;continue;}
    if(k<0){cout<<s.front()+1<<endl;continue;}
    if(s[k]==0 or k==s.size()-1){cout<<0<<endl;continue;}
    if(k<s.size()-1 and s[k+1]==0){cout<<0<<endl;continue;}
    if(k<s.size()-1 and s[k+1]!=s[k]){cout<<s[k+1]+1<<endl;continue;}
    else cout<<s[k]+1<<endl; 
  }
  
  
  
  
  return 0;
}










