#include<iostream>

#include<algorithm>
using namespace std;

#define inf 100000000

int N,M;
int disL[200][200];//隣接行列の重みバージョン陸
int disS[200][200];//海
int r ;
int z[1000];
int disP[1000][200]={};

/*町番号は0からN-1とする（入力は1からN）*/

/*町Z(num)からZr（終点）への最短時間（船が町shipにある状況で）を返す
z  宅配順列の何番目か0->(r-1)
ship 船のある町番号0->N-1
*/
int recur(int num,int ship){
  int land,sea=inf,i;
  if(disP[num][ship]!=0)return disP[num][ship];
  if(num>=r-1)return 0;//ゴール
  land=disL[z[num]][z[num+1]]+recur(num+1,ship);
  
  for(i=0;i<N;i++){
    sea=min(sea,disL[ z[num] ][ship] + disS[ship][i] + disL[i][ z[num+1] ] + recur(num+1,i));
  }

  disP[num][ship]=min(land,sea);
  return disP[num][ship];
}


int main(){
  int i,j,k,x,y,t;
  char ch;
  while(true){

    for(i=0;i<1000;i++)
      for(j=0;j<200;j++)
	disP[i][j]=0;

    
    cin >>N>>M;
    if(N==0 && M==0)break;

    for(i=0;i<200;i++){
      for(j=0;j<200;j++){
	if(i!=j){
	  disL[i][j]=inf;
	  disS[i][j]=inf;
	}
	else {
	  disL[i][i]=0;
	  disS[i][i]=0;
	}
      }
    }
    

    /*陸路海路それぞれの最小値をセット*/
    for(i=0;i<M;i++){
      cin >>x>>y>>t>>ch;
      if(ch=='L'){
	disL[x-1][y-1]=min(disL[x-1][y-1],t);
	disL[y-1][x-1]=min(disL[y-1][x-1],t);
      }
      else if(ch=='S'){
	disS[x-1][y-1]=min(disS[x-1][y-1],t);
	disS[y-1][x-1]=min(disS[y-1][x-1],t);
      }
    }

    /*陸、海それぞれで各町同士の最短経路を出す*/  
    for(i=0;i<N;i++){
      for(j=0;j<N;j++){
	for(k=0;k<N;k++){
	  disL[j][k]=min(disL[j][k],disL[j][i]+disL[i][k]);
	  disS[j][k]=min(disS[j][k],disS[j][i]+disS[i][k]);
	}
      }
    }
    cin >> r;
    for(i=0;i<r;i++){
      cin >> j;
      z[i]=j-1;//町番号は0からN-1にする
    }
    cout << recur(0,z[0]) <<endl;
    
  }
}
