#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int main()
{
  int n;
  string ln;
  cin>>n;
  cin>>ln;
  //  cout<<"!"<<ln<<endl;
  
  int ls[4]={},i;
  for(i=0;i<n;i++)
    {
      char val=ln[i];
      ls[atoi(&val)-1]++;
    }
  int mx=0,mn=n;
  for(i=0;i<4;i++)
    {
      mx=max(mx,ls[i]);
      mn=min(mn,ls[i]);
    }
  cout<<mx<<" "<<mn<<endl;
  return 0;
  
}
