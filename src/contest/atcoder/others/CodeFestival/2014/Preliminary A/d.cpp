#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
//#include<>
using namespace std;

#define rep(i,j) for(i=0;i<j;(i)++)

int main()
{
  string a;
  int k;
  cin>>a>>k;
  long long i;
  char num[k];
  char ketei=0;
  long long ans=1000000000000000,a_n=(long long)stol(a);
  if(k>9){
    cout<<0<<endl;
    return 0;
  }
  char numb[16]={};
  for(i=0;i<a.size();i++)
    numb[i]='0';


  bool flg[10]={};

  for(i=0;i<k;i++){
    int j;
    long long v;
    for(j=i;j<a.size();j++)
      numb[j]=a[i];
    v=abs((long long)atol(numb)-a_n);
    if(ans>v){
      ans=v;
      ketei=a[i];
    }

    if(a[i]!='9'){
      for(j=i;j<a.size();j++)
	numb[j]=a[i]+1;  
      v=abs((long long)atol(numb)-a_n);
      if(ans>v){
	ans=v;
	ketei=a[i]+1; 
      }
    }
    if(a[i]!='0'){
      for(j=i;j<a.size();j++)
	numb[j]=a[i]-1;  
      v=abs((long long)atol(numb)-a_n);
      if(ans>v){
	ans=v;
	ketei=a[i]-1;
      }
    }
    
    if(flg[atoi(&ketei)])
      k++;
    flg[atoi(&ketei)]=true; 
    numb[i]=ketei;

  }





  //‚±‚±‚Åk‚±‚Ì”š‚ÍŒˆ’èAkŒ…‚ß‚Ü‚ÅŒˆ’è
  int j;
  for(i=k;i<a.size();i++)
    numb[i]=ketei;
  //k+1‚©‚ç‚ÍkŒ…‚ß‚ª“ü‚é

  //  cout<<abs((long long)atol(numb))<<" a ";
  
  bool flgg=false;
  for(i=0;i<k;i++)
    if(a[i]!=numb[i])flgg=true;

  if(!flgg){
    for(i=k;i<a.size();i++)
      if(flg[atoi(&a[i])]){
	k++;
	numb[i]=a[i];
      }
      else break;
  }

  if(atol(numb)<a_n)
    {
      for( j=9;j>=0;j--)
	if(flg[j])break;
      for(i=k;i<a.size();i++)
	numb[i]='0'+ j;
    }
  else if(atol(numb)>a_n)
    {
      for( j=0;j<=9;j++)
	if(flg[j])break;
      for(i=k;i<a.size();i++)
	numb[i]='0'+j;
    }
    ans=abs((long long)atol(numb)-a_n);
  //  ans=min(ans,abs((long long)atol(numb)-a_n));
    cout<< ans<<endl;

  

  return 0;
}
