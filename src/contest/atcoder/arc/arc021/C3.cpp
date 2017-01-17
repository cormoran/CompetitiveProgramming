#include<iostream>
#include<vector>
#include<queue>
//#include<

using namespace std;
typedef long long ll;
#define rep(i,j) for(int i=0;i<(j);i++)

int K,N;
vector<int> A;
vector<int> D;


int main(){
  cin>>K>>N;
  A.resize(N);
  D.resize(N);
  
  rep(i,N){
    cin>>A[i]>>D[i];
  }

  vector<int> ans(N);

  rep(i,N){
    for(int j=i+1;j<N;j++){
      
    }
  }
  

  
  
  return 0;
}
