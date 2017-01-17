#include<iostream>
using namespace std;
int main()
{
  long a;
  cin >>a;
  long i=0,val;
  do
    {
      i++;
      val=i*i*i;
      if(a==val)
	{
	  cout<<"YES"<<endl;
	  return 0;
	}
      
    }while(val<a);
  cout<<"NO"<<endl;return 0;
  
}
