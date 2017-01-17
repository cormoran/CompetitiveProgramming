#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
  long long A;
  int k;
  cin>>A>>k;
  long long i;
  long long ans=A;

  for(i=A;;i--)
    {
      set<long long> button;
      long long temp=i;
      while(temp){
	button.insert(temp%10);
	temp/=10;
      }
      if(button.size()<=k)
	{
	  ans=abs(A-i);
	  break;
	}
    }
  for(i=A;abs(A-i)<ans;i++)
    {
      set<long long> button;
      long long temp=i;
      while(temp){
	button.insert(temp%10);
	temp/=10;
      }
      if(button.size()<=k)
	{
	  ans=min(ans,abs(A-i));
	  break;
	}
    }

  cout<<ans<<endl;
  return 0;
}
