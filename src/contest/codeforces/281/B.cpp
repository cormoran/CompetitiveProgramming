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

typedef long long int64;
typedef int int32;
typedef char int8;
typedef int32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j),i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j),i<=(k);i++)
#define rev_rep(i,j,k) for(int__ i=(j)-1;i>=k;i--)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

int main()
{
  int n;cin>>n;
  int64 sum[2]={};
  string seq[2]={},seqtemp[2]={};
  rep(i,n){
    int64 a;cin>>a;
    bool id;id=(a>0?0:1);//0:first
    
    seq[!id]=max(seq[!id],seqtemp[!id]);
    seqtemp[!id]="";
    char str[11];sprintf(str,"%d",abs(a));
    seqtemp[id].append(str);
    sum[id]+=abs(a);
  }
  rep(i,2)
    seq[i]=max(seq[i],seqtemp[i]);
  
  if(sum[0]>sum[1])
    cout<<"first"<<endl;
  else if(sum[0]<sum[1])
    cout<<"second"<<endl;
  else{
      if(seq[0]>seq[1])
	cout<<"first"<<endl;
      else if(seq[0]<seq[1])
	cout<<"second"<<endl;
      else
	cout<<(seqtemp[0]=="" ? "second":"first")<<endl;
  }
  //  cout<<seq[0]<<endl<<seq[1];
  return 0;
}

















