#include<iostream>
using namespace std;
int main(){
  int a;cin>>a;
  if(a<=59)cout << "Bad" << endl;
  else if(a<=89)cout << "Good" << endl;
  else if(a<=99)cout << "Great" << endl;
  else cout << "Perfect" << endl;
  return 0;
}
