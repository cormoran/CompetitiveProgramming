#include<iostream>
using namespace std;

int main()
{
  int t,i;
  cin>>t;
  for(i=0;i<t;i++)
    {
      int n,ans1=0,ans2=0;
      cin>>n;
      while(n!=1)
	{
	  if(n%2){
	    n=n*3+1;
	    ans2++;
	  }
	  else
	    {
	      n/=2;
	      ans1++;
	    }
	}
      cout<<ans1<<endl<<ans2<<endl;
    }

  return 0;
}
