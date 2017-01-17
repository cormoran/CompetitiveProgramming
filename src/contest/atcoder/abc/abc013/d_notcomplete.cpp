#include<iostream>
#include<algorithm>
typedef long long ll;
#define rep(i,j) for(i=1;i<=j;i++)
using namespace std;
int main()
{
  long long n,m,d;
  cin >>n>>m>>d;
  
  long long a[m+1],i,j;
  rep(i,m)cin>>a[i];//a[1] to a[m]にはいる
  
  long long now[n+1],val;
  rep(i,n)now[i]=i;//now[1] to now[n]にはいる
  rep(j,m){//ターンを1からmまで進めるそのターンにa[j]とa[j]+1にいるやつをスワップ
    val=now[a[j]+1]; 
    now[a[j]+1]=now[a[j]];
    now[a[j]]=val;
  }

  ll ans[n+1];
  rep(i,n)ans[i]=now[i];//ansにコピー
  rep(i,d-1)//上で一回したことになるのでd-1回繰り返す
    {
      rep(j,n)
	{
	  ans[j]=now[ans[j]];//繰り返しはnowを関数として使う！
	}
    }
  rep(i,n)
    cout <<find(ans+1,ans+n,i)-ans<<endl;
  
  return 0;
}




