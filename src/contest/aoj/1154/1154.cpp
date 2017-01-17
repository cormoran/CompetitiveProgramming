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
//#include<>
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

vector<i32> MSnum;
vector<char> MSprime;

void factorize_MS(){
  //月曜土曜数列挙
  {
    int temp=0;
    MSnum.resize(300000/7*2+2);
    MSprime.resize(300001,1);//月曜素数でないやつも１になる
    for(i32 i=0;i+1<MSnum.size();i+=2){
      MSnum[i]=temp+1;
      MSnum[i+1]=temp+6;
      temp+=7;
    }
  }

  //月曜土曜素数のエラストテネス
  {
    MSprime[1]=0;
    repeat(idx,1,MSnum.size()){
      if(MSprime[MSnum[idx]]==0)continue;
      for(i32 i=2;;i++){
	i64 temp=MSnum[idx]*i;
	if(temp>=MSprime.size())break;
	MSprime[temp]=0;
      }
    }
  }
}


int main()
{
  factorize_MS();

  while(true){
    i32 n;cin>>n;
    if(n==1)break;

    printf("%d:",n);
    bool flg=false;
    for(i32 i=0;MSnum[i]<=n;i++){
      if(MSprime[MSnum[i]]==0)continue;
      if(n%MSnum[i]==0){
	printf(" %d",MSnum[i]);
	flg=true;
      }
    }
    cout<<endl;
  }
  return 0;
}




