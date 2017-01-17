#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>

using namespace std;
#define rep(i,j) for(i=0;i<j;i++)

int T_all,P,N;
vector<int> A;
int turn()
{
  int T_now;
  char D;
  vector< vector<int> > B;//B[i][j]:言語iに対するプレーヤーjの信者数（平日分のみ）
  vector<int> R,P;//R[i]:言語iの信者数、P[i]:言語iが前休日に布教された回数

  //入力
  {
    vector<int> temp;
    temp.resize(P,0);
    B.resize(N,temp);
    scanf("%d%c",&T_now,&D);
    int i,j;
    rep(i,N)rep(j,P)
      scanf("%d",&B[i][j]);
    rep(i,N)
      scanf("%d",&R[i]);
    rep(i,N)
    scanf("%d",&P[i]);
  }

  //解析


  //出力
  


}


int main()
{
  
  



}
