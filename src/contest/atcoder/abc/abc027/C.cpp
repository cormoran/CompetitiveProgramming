#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i,j) for(int i=0;i<(j);i++)
using namespace std;
int main(){
  typedef long long ll;
  ll N;cin>>N;
  if(N==1){
    cout<<"Aoki"<<endl;
    return 0;
  }

  ll pows=1;
  ll sum=1;
  while(1){
    pows*=4;
    sum+=pows;
    if(sum>=N){
      cout<<"Takahashi"<<endl;
      break;
    }
    sum+=pows;
    if(sum>=N){
      cout<<"Aoki"<<endl;
      break;
    }
    
  }
}
