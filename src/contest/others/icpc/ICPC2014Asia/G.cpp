#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<cmath>
//#include<>
using namespace std;

typedef long long ll;
#define rep(i,j) for(int i=0;i<j;i++)
#define rep_a_to(a,i,j) for(int i=a;i<=j;i++)
#define rev_rep(i,j) for(int i=j;i>=0;i--)

const int INF=1<<30;
//sumに区間部分加算総和、dataに区間全体各加算和を入れる
class Segment_Tree
{
public:
  int n;
  vector<int> data,sum;//data:区間の総和最小//sum:その対応区間全てに追加した和


  Segment_Tree(int n_)
  {
    n=1;
    while(n<n_)n*=2;
    data.resize(2*n-1,0);
    sum.resize(2*n-1,0);
  }

  //[a,b]にxを加算
  void add(int a,int b,int x)
  {
    add_getmin(a,b,x,0,0,n);
  }

  int get_min(int a,int b)
  {
    return get_min(a,b,0,0,n);
  }

private:
  //区間に追加してその区間の最小値を返す
  int add_getmin(int a,int b,int x,int k,int l,int r)
  {
    //目的範囲から完全に外れたら
    if(r<=a||b<=l)return data[k];
    //加算希望区間に収まっていたら
    if(a<=l && r<=b)
      {
	data[k]+=x;//区間全体に+xなので最小値はその区間最小値+x
	sum[k]+=x;
	return data[k];
      }
    //加算希望区間を含むなら
    else if(l<b && a<r)
      {
	//区間最小値は下の最小値にすでに足されていた値を足したもの
	return  data[k]=min(add_getmin(a,b,x,k*2+1,l,(l+r)/2),add_getmin(a,b,x,k*2+2,(l+r)/2,r))+sum[k];
      }
    assert(false);
  }
  //[a,b)の最小値,kは今の場所,[l,r)はkの守備範囲
  int get_min(int a,int b,int k,int l,int r)
  {
    //目的範囲から完全に外れたら
    if(r<=a||b<=l)return INF;
    //目的範囲より狭くなったら
    if(a<=l&&r<=b)return data[k];
    else {
      //左の子側の範囲
      int vl=get_min(a,b,k*2+1,l,(l+r)/2);
      //右の子側の範囲
      int vr=get_min(a,b,k*2+2,(l+r)/2,r);
      return min(vl,vr)+sum[k];
    }
  }

};

void debug_show(string str,Segment_Tree *ST,int n)
{

  cout<<str<<endl;
  cout<<"Sum ";
  rep(j,n)
    cout<<ST->get_min(j,j+1)<<" ";
  cout<<endl;
  cout<<"Min " ;
  rep(j,n)
    cout<<ST->get_min(j,n)<<" ";
  cout<<endl;
}

int  main()
{
  int n,q;cin>>n>>q;

  //入力
  string str;cin>>str;

  Segment_Tree ST(n);
  
  rep(i,(int)str.size())
    {
      if(str[i]=='('){
	ST.add(i,n,1);
      }
      else
	ST.add(i,n,-1);
    }

  rep(i,q)
    {
      int flip;cin>>flip;
      flip--;
      if(str[flip]=='(')
	{
	  str[flip]=')';
	  int ans=str.find(')',0);
	  cout<<ans+1<<endl;
	  str[ans]='(';
	  ST.add(flip,n,-2);
	  ST.add(ans,n,+2);
	}
      else
	{
	  str[flip]='(';
	  ST.add(flip,n,+2);
	  /* 
	  int p=-1;
	  if(flip==n-1)p=flip;
	  else
	    do{p=str.find('(',p+1);}
	    while(ST.get_min(p,n)<2);
	  
	  */
	  //cout<<"bf "<<flip+1<<"changed"<<endl;
	  //debug_show(str,&ST,n);
	  
	  int p=0,e=n;
	  if(flip==n-1)p=flip;
	  else{
	    while(e>p+1){
	      if(ST.get_min((p+e)/2,n)<2)p=(p+e)/2;
	      else e=(p+e)/2;
	    }
	    p=str.find('(',p+1);
	  }
	  cout<<p+1<<endl;
	  str[p]=')';
	  ST.add(p,n,-2);
	  //puts("af");
	  //debug_show(str,&ST,n);

	}
    }


  return 0;
}
