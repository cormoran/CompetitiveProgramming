#include<iostream>
#define rep(i,j) for(i=0;i<j;i++)
using namespace std;

int main(){
  int correct=0,i,j;

  rep(i,9){
    rep(j,9){
      correct+=(i+1)*(j+1);
    }
  }

  int n,diff;
  cin >>n;
  diff=correct-n;
  rep(i,9){
    if(diff%(i+1)==0 && diff/(i+1)<=9) cout << i+1 <<" x "<< diff/(i+1) << endl;
  }
  return 0;
}
