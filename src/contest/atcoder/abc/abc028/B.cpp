#include<iostream>
using namespace std;
int main(){
  char S[105];cin>>S;
  char *pt=S;
  int ans[6]={};
  while(*pt){
    ans[(*pt)-'A']++;
    ++pt;
  }
  for(int i=0;i<5;i++)cout<<ans[i]<<" ";
  cout << ans[5] << endl;
  return 0;
}
