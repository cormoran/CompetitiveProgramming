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
#include<cassert>
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

string str;
int pos;

int rec(){
  vector<int> vote;

  if(str[pos]=='['){
    pos++;
    while(str[pos]!=']'){
      vote.push_back(rec());
    };
  }
  else if(isdigit(str[pos])==true){
    int pos_p=pos;
    while(isdigit(str[pos]))++pos;// ']'まで進める
    int vote_1=atoi(str.substr(pos_p,pos-pos_p).c_str());
    return vote_1/2+1;
  }

  int ans=0;
  sort(all(vote));

  rep(i, (int)vote.size()/2 + 1 ){
    ans+=vote[i];
  }
  pos++;
  return ans;
}

int main()
{
  int n;cin>>n;
  rep(i,n){
    cin>>str;
    pos=0;
    cout<<rec()<<endl;
  }
  return 0;
}
