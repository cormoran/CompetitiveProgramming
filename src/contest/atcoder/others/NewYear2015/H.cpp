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

class kdTree{

  struct Point{int x,y;};
  struct node{Point val;node *lch,*rch;};

  bool comp_a_min_b(Point &a,Point &b,int depth){
    if(depth%2==1)return a.y<b.y;
    else return a.x<b.x;
  }
  
  node *insert(node *p,Point x,int depth){
    if(p==NULL){
      node *q=new node;
      q->val=x;
      q->lch=NULL;
      q->rch=NULL;
      return q;
    }
    else{
      if(comp_a_min_b(x,p->val,depth))p->lch=insert(p->lch,x,depth+1);
      else p->rch=insert(p->rch,x,depth+1);
      return p;
    }
  }
  
};

int main()
{
  
  return 0;
}
