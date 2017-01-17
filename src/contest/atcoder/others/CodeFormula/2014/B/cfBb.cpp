#include<iostream>
#include<cmath>
#include<string>
using namespace std;

 
int main()
{
  
  string num;
  
  cin >>num;
  
  unsigned long long i,j;
  
  unsigned long long odd=0,even=0;
  
  j=0;
  
  for(i=num.size();i>0;i--)
    {
      j++;
      if(j%2==0)
        {
	  
          even+=stoi(num.substr(i-1,1));
	  
        }
      
      else
        {
	  
          odd+=stoi(num.substr(i-1,1));
	  
        }
      
 
    }
  
  cout<<even <<" "<<odd<<endl;
  
 
  return 0;
  
 
}
