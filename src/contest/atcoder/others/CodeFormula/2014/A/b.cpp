#include<iostream>

using namespace std;
#define rep(i,j) for(i=0;i<j;i++)
int main()
{
  int a,b;
  cin>>a>>b;
  int p[a],q[b];
  int i;
  int pin[10]={};
  rep(i,a)
    {
      cin>>p[i];
      pin[p[i]]=1;
    }
  rep(i,b)
    {
      cin>>q[i];
      pin[q[i]]=2;
    }
  i=7;
  do
    {
      if(pin[i]==1)cout<<".";
      else if(pin[i]==2)cout<<"o";
      else cout<<"x";
      switch (i)
	{
	case 7:
	case 8:
	case 9:
	case 4:
	case 5:
	case 2:
	  cout<<" ";
	  break;
	case 0:
	  cout<<endl<<" ";
	  break;
	case 6:
	  cout<<endl<<"  ";
	  break;
	case 3:
	  cout<<endl<<"   ";
	  break;
	}
   
      
      if(i==9)i=0;
      else if(i==0)i=4;
      else if(i==6)i=2;
      else if(i==3)i=1;
      else if(i==1)i=10;
      else i++;
      
    }while (i<10);
  
  cout <<endl;
  return 0;
}
