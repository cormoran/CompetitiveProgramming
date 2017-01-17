#include<iostream>
#include<string>
using namespace std;
int main()
{
  string a,b,c,d;
  cin>>a>>b;
  
  int i;
  for(i=0;i<a.size();i++)
    {
      if(a.at(i)!=b.at(i))
	{
	  c.insert(c.size(),a.at(i));
	  d.insert(d.size(),b.at(i));
	}
    }
  int j,k,l;
  
  if(c.size()<=6)
    {
      i=0;
      while(i<c.size()-3)
	{
	  for(j=i+1;j<d.size();j++)
	    {
	      if(c.at(i)==d.at(j))
		{
		  char val=c.at(i);
		  c.at(i)=d.at(i);
		  d.at(i)=val;
		  for(k=j+1;k<d.size();k++)
		    {
		      if(c.at(i)==d.at(
		    }
		}
	    }
	  i++;
	}
      

    }
  

  return 0;
  
}
