#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
//#include<>
using namespace std;

typedef long long int64;
typedef int int32;
typedef char int8;
typedef int32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j),i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j),i<=(k);i++)
#define rev_rep(i,j,k) for(int__ i=(j)-1;i>=k;i--)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

int main()
{
  string team_name[2];cin>>team_name[0]>>team_name[1];
  int n;cin>>n;
  int cards[2][100]={};
  rep(i,n){
    int minute,number,team_n;
    char team,flg;
    cin>>minute>>team>>number>>flg;
    team_n=(team=='h'?0:1);//home:0
    if((flg=='r' && cards[team_n][number]<2) || cards[team_n][number]==1){
      printf("%s %d %d\n",team_name[team_n].c_str(),number,minute);
      cards[team_n][number]=2;
    }
    else if(cards[team_n][number]==0){//flg=yello && cards=0
      cards[team_n][number]=1;
    }
  }
  return 0;
}

















