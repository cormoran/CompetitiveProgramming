/*atoiを使わないバーション
  高速 23ms memory 932KB
*/
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
  
  int ls[4]={},i;
  for(i=0;i<n;i++)
    {
      ls[ln[i]-'1']++;
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
