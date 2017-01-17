#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
//#include<>
using namespace std;

typedef long long ll;
#define rep(i,j) for(i=0;i<j;i++)
#define rev_rep(i,j) for(i=j;i>=0;i—-)

int main()
{
  string s1,s2,s3;
  cin>>s1>>s2>>s3;
  int i,num=s1.size(),s2c1=0,s2c3=0;
  rep(i,s1.size())
    {
      ll pt=s3.find(s1[i]);
      if(pt==string::npos)//3にない
	s1.erase(i--,1);
      else//3にある
	s3.erase(pt,1);
      //      cout<<s1<<endl;
    }
  if(s1.size()>=num/2)
    {
      rep(i,s2.size())
	{
	  ll pt=s3.find(s2[i]);
	  if(pt==string::npos)//s3にない
	    {
	      pt=s1.find(s2[i]);
	      if(pt!=string::npos)//s1にある
		{
		  s1.erase(pt,1);
		  s2c1++;
		}
	    }
	  else{//s3にある
	    s3.erase(pt,1);
	    s2c3++;
	  }
	  //	  cout<<s2c<<s3<<endl;
	  if(s2c1+s2c3>=num/2 && s3.size()==0)break;
	}
      //  cout<<"a"<<s1.size()<<" b"<<s2c<<" c"<<s3.size()<<endl;
      int asd=0;
      if(s2c1+s2c3>num/2 && s2c3<=num/2)asd=s2c1+s2c3-num/2;
      if(s1.size()+asd>=num/2 && s2c3+s2c1>=num/2 && s3.size()==0)
	cout<<"YES"<<endl;
      else
	cout<<"NO"<<endl;
    }
  else
    cout<<"NO"<<endl;
  return 0;

}
