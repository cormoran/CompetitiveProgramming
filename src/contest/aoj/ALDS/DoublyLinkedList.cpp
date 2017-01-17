#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<cstdint>
#include<list>
using namespace std;

typedef int64_t i64;typedef int32_t i32;
typedef int16_t i16;typedef int8_t i8;
typedef uint64_t ui64;typedef uint32_t ui32;
typedef uint16_t ui16;typedef uint8_t ui8;

typedef i32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//=10E10

int main()
{
  list<int> lst;
  int n;cin>>n;
  rep(i,n){
    string cmd;cin>>cmd;
    if(cmd=="insert"){
      int x;cin>>x;
      lst.push_front(x);
    }
    else if(cmd=="delete"){
      int x;cin>>x;
      auto ep=find(all(lst),x);
      if(ep!=end(lst))
	lst.erase(ep);
    }
    else if(cmd=="deleteFirst"){
      lst.pop_front();
    }
    else if(cmd=="deleteLast"){
      lst.pop_back();
    }
  }
  for(auto itr=begin(lst);itr!=--end(lst);itr++){
    cout<<*itr<<" ";
  }
  cout<<lst.back()<<endl;
  return 0;
}
