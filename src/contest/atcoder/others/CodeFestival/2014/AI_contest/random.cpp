#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<cstdio>
using namespace std;

int T_all,P_all,N;
vector<int> A;
#define rep(i,j) for(i=0;i<j;i++)
int main()
{
  srand(time(NULL));
  cout<<"READY"<<endl;
  int i,j,k;
  cin>>T_all>>P_all>>N;
  A.resize(N,0);
  rep(i,N)
    cin>>A[i];

  int T_now;
  char D;
  vector< vector<int> > B;//B[i][j]:言語iに対するプレーヤーjの信者数（平日分のみ）
  vector<int> R,P;//R[i]:言語iの信者数、P[i]:言語iが前休日に布教された回数
  vector<int> temp;
  temp.resize(P_all,0);
  B.resize(N,temp);
  R.resize(N,0);
  P.resize(N,0);
  rep(i,T_all)
    {
      //入力
      {
	cin>>T_now>>D;
	rep(j,N)rep(k,P_all)
	  cin>>B[j][k];
	rep(j,N)
	  cin>>R[j];
	if(D=='W')
	  rep(j,N)
	    scanf("%d",&P[j]);
      }
      if(D=='W')
	{
	  cout<<rand()%N;
	  rep(j,4)cout<<" "<<rand()%N;
	  cout<<endl;
	}
      else
	{
	  cout<<rand()%N;
	  rep(j,1)cout<<" "<<rand()%N;
	  cout<<endl;
	}
    }
  return 0;
}
