#include<iostream>
using namespace std;
#define rep(i,j) for(int i=0;i<j;i++)

int main()
{
  int N,S,T,W;
  cin>>N>>S>>T>>W;

  int A=W;
  int cnt=0;
  if(S<=A and A<=T)cnt++;
  rep(i,N-1){
    int Ai;cin>>Ai;
    A+=Ai;
    if(S<=A and A<=T)cnt++;
  }

  cout<<cnt<<endl;
  return 0;
}
