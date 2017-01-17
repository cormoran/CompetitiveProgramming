//途中　意味不明な状態
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
#define rep(i,j) for(i=0;i<j;i++)
#define rep1(i,j) for(i=1;i<j;i++)

struct tria {
  int l,r,c;
  bool  operator<(const tria& right)const{
    return l==right.l ? c<right.c :l<right.l;
  }
};

/*始まりの早いのからとってきてそいつと　後のいくつか（そいつの終を超えるまで）
のコストと和を比べて・・・*/

/*num: 配列のnumから後を探す
  gl 超えてほしい座標*/
int calcos(tria* trip,int num,int gl){
  int cos;
  if(trip.r < trip
}

int main(){
   int n,l;
   cin>>n>>l;
   tria tri[n];
   int i,j;
   rep(i,n){
     cin>>tri[i].l>>tri[i].r>>tri[i].c;
   }
   sort(tri,tri+n);

   stack<tira> box;
   int alcos=0,concos=0;
   bool flg;
   box.push(tri[0]);
   rep(i,n){
   	/*入れる必要性の検証　そいつを入れないと連続性がなくなるなら入れる
   			　　　そうでなければ代わりを探してコスト比較*/
     if(tri[i+1].l>box.top().r){box.push(tri[i]); alcos+=tri[i].c;}
     else {
       flg=1;
       j=0;
       concos=0;
       while(flg){
	 concos+=tri[i+ ++j].c
	 if(tri[i + j].r>=tri[i])


     }
   }

   return 0;
}
