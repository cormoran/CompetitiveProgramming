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

int n;
string s;

int main()
{
  cin >>n;
  cin >>s;
  int a=0,b=n-1;
  
  while(a<=b){
    bool left=false;
    for(int i=0;i+a<=b;i++){
      if(s[a]<s[b-i]){
	left=true;
	break;
      }
      else if(s[a]>s[b-i]){
	break;
      }
    }
    if(left)putchar(s[a++]);
    else putchar(s[b--]);
  }
  putchar('\n');

  return 0;
}
