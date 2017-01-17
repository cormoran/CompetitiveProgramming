#include<iostream>
#include<ctype.h>

using namespace std;
int main(){
  int i;
  char s[12]={};
  cin >> s;
  s[0]=toupper(s[0]);
  for(i=1;i<12;i++)  s[i]=tolower(s[i]);
  cout << s << "\n";
  return 0;
}


