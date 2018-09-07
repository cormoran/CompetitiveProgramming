#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main()
{
  int a,b;
  cin >>a>>b;
  int an1,an2;
  an1=abs(a-b);
  an2=abs(an1-10);
  cout<<min(an1,an2)<<endl;
  
  return 0;
}
