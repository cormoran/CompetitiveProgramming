#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
  queue<int> box;
  unsigned int n,i,cnt=0,ans=0;
  cin >> n;
  unsigned int a[n];
  bool flgs[100001]={};
  for(i=0;i<n;i++)cin >> a[i];
  for(i=0;i<n;i++){
    if(flgs[a[i]]==false){
	box.push(a[i]);
	flgs[a[i]]=true;
      }
      else{
	ans=max(ans,(unsigned int)box.size());
	while(box.front()!=a[i]){
	  flgs[box.front()]=false;
	  box.pop();
	}
	box.pop();
	box.push(a[i]);
      }
  }
  ans=max(ans,(unsigned int)box.size());
  cout << ans<<endl;
    return 0;
}
