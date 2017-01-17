#include<iostream>
#include<cstdlib>
using namespace std;

int main ()
{
  int a,b,cnt=0;
  cin>>a>>b;
  a=abs(a-b);
  while(a)
    {
      a=min(abs(a-1),min(abs(a-5),abs(a-10)));
      cnt++;
    }
  cout<<cnt<<endl;
}
