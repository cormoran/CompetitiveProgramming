#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<climits>
//#include<>
using namespace std;

typedef long long ll;
#define rep(i,j) for(i=0;i<j;i++)
#define rep_a_to(a,i,j) for(i=a;i<=j;i++)
#define rev_rep(i,j) for(i=j;i>=0;i--)

/*

    0        1
  1   2    2   3
 3 4 5 6  4 5 6 7

k段目(k=1,2,3...)の左端は配列2^k番目(=data[2^k -1])
データ数n_とすると木の構築には2^(n_+1)個の配列が必要
nをn_<=2^kとなる最小の2^kとすると
全ノード数2n-1
一番下以外はn-1
ゆえにl(=0,1,2...)番目のデータはdata[l+n-1]にある
 */
const int INF=INT_MAX;
class Segment_Tree
{
public:

  int n;
  vector<int> data;

  Segment_Tree(int n_)
  {
    n=1;
    while(n<n_)n*=2;
    data.resize(2*n-1,INF);
  }

  //index k(=0,1,2...)の値をaにする。
  void update(int k,int a)
  {
    k+=n-1;
    data[k]=a;
    while(k>0){
      //親は1-index では k/2なので 0-indexでは (k+1)/2 - 1 = (k-1)/2
      k=(k-1)/2;
      data[k]=min(data[k*2+1],data[k*2+2]);
    }
  }

  int query(int a,int b)
  {
    return search(a,b+1,0,0,n);
  }
private:
  //[a,b)の最小値,kは今の場所,[l,r)はkの守備範囲
  int search(int a,int b,int k,int l,int r)
  {
    //目的範囲からずれた無効
    if(r<=a||b<=l)return INF;
    //目的範囲より狭くなったら終了
    if(a<=l&&r<=b)return data[k];
    else {
      //左の子側の範囲
      int vl=search(a,b,k*2+1,l,(l+r)/2);
      //右の子側の範囲
      int vr=search(a,b,k*2+2,(l+r)/2,r);
      return min(vl,vr);
    }
  }

};


int main()
{
  string cline;
  int n,q,i;
  cin>>n>>q;
  Segment_Tree ST(n);
  rep(i,q)
    {
      int com,x,y;
      cin>>com>>x>>y;
      if(com)
	cout<<ST.query(x,y)<<endl;
      else
	ST.update(x,y);
    }
  return 0;
}
