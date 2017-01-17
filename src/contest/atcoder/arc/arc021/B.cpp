#include<iostream>
#include<vector>
//#include<

using namespace std;

#define rep(i,j) for(int i=0;i<(j);i++)

int main(){
  int L;
  cin>>L;
  vector<unsigned int> B(L+1);
  rep(i,L)cin>>B[i];
  B[L]=B[0];
  unsigned int t=0;
  vector<unsigned int> ans(L+1);
  ans[0]=0;
  rep(i,L){
    t^=B[i];
    ans[i+1]=B[i]^ans[i];
  }
  if(t!=0){
    cout<<-1<<endl;
    return 0;
  }
  rep(i,L)
  {
    cout<<ans[i]<<endl;
  }
  
  return 0;
}
