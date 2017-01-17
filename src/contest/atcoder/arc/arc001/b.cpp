#include<iostream>
#include<cstdlib>
using namespace std;

int main ()
{
  int a,b,cnt=0;
  cin>>a>>b;
  while(abs(b-a)>7)
    {
      if(b>a)a+=10;
      else a-=10;
      cnt++;
    }
  while(abs(b-a)>3)
    {
      if(b>a)a+=5;
      else a-=5;
      cnt++;
    }
  while(a!=b)
    {
      if(b>a)a++;
      else a--;
      cnt++;
    }
  cout <<cnt<<endl;
  return 0;
}
