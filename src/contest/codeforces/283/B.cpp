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
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

//n文字numのnum[index]を先頭に持ってきてそこが0になるように。
string rotate_min(int n,string num,int index){
  char t=num[index];
  //各桁t引く
  rep(i,n){
    if(num[i]-t>=0)
      num[i]=num[i]-t+'0';
    else
      num[i]=num[i]-t+10+'0';
  }
    string ans=num;
    //ローテート
    rep(i,n)ans[i]=num[(index+i)%n];
  return ans;
}

int main()
{
  int n;cin>>n;
  string num;
  cin>>num;

  int maxlen=0,t_len=0,t_startid=0;
  vector<int> startid;
  rep(i,n-1){
    if(num[i]>num[i+1]){
      if(maxlen<t_len){
	maxlen=t_len;
	t_len=0;
	startid.clear();
	startid.push_back(t_startid);
	t_startid=i+1;
      }
    }
    t_len++;
  }
  
  int k=0;
  rep(i,n){
    string temp=rotate_min(n,num,i);
    int j=0;
    while(temp[i]=='0')j++;
    if(j<k)
    rep(g,k)
      if(ans[g+k]>temp[j+k])ans=temp;
    }
  }
  cout<<ans<<endl;
  return 0;
}










