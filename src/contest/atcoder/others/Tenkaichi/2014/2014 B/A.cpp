#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iterator>
using namespace std;

int main()
{
  string s;

  getline(cin,s);
      //HAGIYA HAGIXILE
  s.insert(s.find("HAGIYA")+6,"aa");
  s.replace(s.find("HAGIYA")+4,4,"XILE");
  cout<<s<<endl;
  
  return 0;
}
