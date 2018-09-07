#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//同じ長さの文字列に対していくつ違う文字があるかを返す
//つまり aを並べ替えてbにしようとした時足りない文字の数
int diff(string a,string b)
{
  int i;
  for(i=0;i<a.size();i++)
    {
      int index=b.find(a[i]);
      if(index != string::npos)
	{
	  b.erase(index,1);
	}
    }
  return b.size();
}

int diff_s(string a,string b)
{
  int i,ans=0;
  for(i=0;i<a.size();i++)
    if(a[i]!=b[i])ans++;
  return ans;
}

int main(){
  int n,k;
  string s,sorted,ans;
  cin>>n>>k;
  cin>>s;
  sorted=s;
  sort(sorted.begin(),sorted.end());
  int i,j;
  for(i=0;i<n;i++)
    {
      //ans[i]を確定させる
      //ans[i]を一番小さいalphaにしてみて
      //diff(ans,s[0toi])+diff(sorted[i+1ton],s[i+1ton])<=kならOK
      //ダメならans[i]を次にして...
      for(j=0;j<sorted.size();j++){
	ans+=sorted[j];
	sorted.erase(j,1);
	if(diff_s(ans,s.substr(0,i+1))+diff(sorted,s.substr(i+1,n-i-1))<=k)
	  break;
	sorted.insert(j,&ans[i]);
	ans.erase(i,1);
      }
    }
  cout<<ans<<endl;
  return 0;
}
