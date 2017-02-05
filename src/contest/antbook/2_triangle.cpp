#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int k[n];
  priority_queue<int> edges;
  for(int i=0;i<n;i++){
    scanf("%d",&k[i]);
    edges.push(k[i]);
  }
  int f,s,t;
  f=edges.top();
  edges.pop();
  s=edges.top();
  edges.pop();
  t=edges.top();
  edges.pop();
    while(f>=s+t)
    {
      if(edges.size()>0){
	f=s;s=t;
	t=edges.top();
	edges.pop();
      }
      else break;
    }
  if(f<s+t)cout <<f+s+t<<endl;
  else cout<<0;

  return 0;
}
