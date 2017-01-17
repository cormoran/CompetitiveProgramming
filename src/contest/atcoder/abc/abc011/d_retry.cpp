#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstdlib>
using namespace std;
int main(){
  int N;
  long long D,x,y;
  cin>>N>>D>>x>>y;
  if(x%D || y%D || (N-abs(x/D)-abs(y/D))%2)
    {
      printf("%f\n",0);return 0;
    }
  x=abs(x/D);
  y=abs(y/D);


  
  vector< vector<double> > nCk_prob;//nCk/2^n
  vector<double> temp;
  temp.resize(N+1,0);
  nCk_prob.resize(N+1,temp);
  int i,j;

  //nCkに確率を加える
  //まず左右or上下で分ける nCk(1/2)^k
  //次にそれぞれを左or右、上or下で分ける
  // ->oCo(1/2)^oを３つかければOK
  nCk_prob[0][0]=1;
  for(i=1;i<=N;i++){
    nCk_prob[i][0]=nCk_prob[i-1][0]/2;
    for(j=1;j<=i;j++)
      nCk_prob[i][j]=(nCk_prob[i-1][j]+nCk_prob[i-1][j-1])/2;
  }
  double ans=0;
  int var=(N-x-y)/2;
  for(i=0;i<=var;i++)
    ans+=nCk_prob[N][x+2*i]*nCk_prob[x+2*i][i]*nCk_prob[N-x-2*i][var-i];
  printf("%.10f\n",ans);
  return 0;
}
