#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
//#include<>
using namespace std;

#define rep(i,j) for(i=0;i<j;(i)++)

int main()
c{
  string a;
  long long b;
  cin>>a;
  cin>>b;
  b=b%a.size();
  if(b==0)cout<<a[a.size()-1];
  else cout<<a[b-1];
  cout<<endl;


  return 0;
}
