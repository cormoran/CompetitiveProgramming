#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i,j) for(int i=0;i<(j);i++)
using namespace std;
int main(){
  int N;cin>>N;
  vector<int> A(N);
  int sum=0;
  rep(i,N){
    cin>>A[i];
    sum+=A[i];
  }
  int one = sum/N;

  int ans=0;
  int left=0;
  rep(i,N){
    if(left !=0){
      ans++;
      left+=A[i]-one;
      A[i]=one;
    }
    else if(A[i]!=one){
      left+=A[i]-one;
      A[i]=one;
    }
  }
  if(left!=0)ans=-1;
  cout<<ans<<endl;
  
  return 0;
}
