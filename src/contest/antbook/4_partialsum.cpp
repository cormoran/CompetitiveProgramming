#include<cstdio>
#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;

int main()
{
  stack<int> dfs;
  int n,a[20],k;
  cin>>n;
  for(int i=0;i<n;i++)cin >>a[i];
  cin>>k;
  bool flg=false;
  for(int i=0;i<n;i++){
    int v=dfs.top();
    if(v==k ||v+a[i]==k){flg=true;break;}
    dfs.push(v+a[i]);
  }
  if(flg)cout <<"Yes"<<endl;
  else cout <<"No"<<endl;


  return 0;
}
