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

int main()
{
  i32 T;cin>>T;
  rep(i,T){
    string n_str;cin>>n_str;
    i32 nsize=n_str.size();
    vector<i32> n_srt(nsize),n(nsize);
    rep(j,nsize)n[j]=n_srt[j]=n_str[j]-'0';

    string minans=n_str;
    {
      sort(all(n_srt));
      i32 chpos=0,offset=0,chpos2=0;
      while(offset<nsize && n_srt[offset]==0)++offset;
      while(chpos+offset<nsize && n[chpos]==n_srt[chpos+offset])chpos++;
      
      if(chpos+offset<nsize){
	//swap n[chpos] & n_srt[chpos+offset]
	chpos2=find(n.begin()+chpos,n.end(),n_srt[chpos+offset])-n.begin();
	
	char c=minans[chpos];
	minans[chpos]=minans[chpos2];
	minans[chpos2]=c;
	//	printf("chpos %d ,offset %d, chpos2 %d\n",chpos,offset,chpos2);
      }
      printf("Case #%d: ",i+1);
      cout<<minans<<" ";
    }

    string maxans=n_str;
    {
      sort(all(n_srt),greater<i32>());
      i32 chpos=0,chpos2=0;
      while(chpos<nsize && n[chpos]==n_srt[chpos])chpos++;
      
      if(chpos<nsize){
	//swap n[chpos] & n_srt[chpos]
	chpos2=distance(n.begin(),find(n.begin()+chpos,n.end(),n_srt[chpos]));
      
	char c=maxans[chpos];
	maxans[chpos]=maxans[chpos2];
	maxans[chpos2]=c;
      }
      cout<<maxans<<endl;
    }


    

  }
  return 0;
}

















