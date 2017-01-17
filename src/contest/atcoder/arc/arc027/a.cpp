#include<iostream>
using namespace std;

int main(){

  int h,m;
  cin >>h>>m;
  int ans=(17-h)*60 + 60-m;
  cout <<ans<<endl;
  
  return 0;
}
