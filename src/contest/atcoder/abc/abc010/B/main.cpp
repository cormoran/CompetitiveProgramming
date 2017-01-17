#include<iostream>
#define rep(i,j) for(i=0;i<j;i++)
using namespace std;

int main()
{
  int n;
  cin>>n;
  int a,i,cnt=0;
  rep(i,n)
    {
      cin>>a;
      if(a%3==0 && a%2==0)
	cnt+=3;
      else
	{
	  if(a%3==2)
	    {
	      cnt++;
	      a--;
	    }
	  if(a%2==0)
	    cnt++;
	}
    }
  cout<<cnt<<endl;
  return 0;
}
