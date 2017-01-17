//#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<string>
#include<cmath>
#include<cassert>
using namespace std;

typedef long long i64;typedef int i32;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)


vector<int> C;
int N;


const int INF=INT_MAX;
class Segment_Tree
{
public:
  int n;
  vector<int> data;
  Segment_Tree(int n_){
    n=1;
    while(n<n_)n*=2;
    data.resize(2*n-1,INF);
  }

  //index k(=0,1,2...)の値をaにする。
  void update(int k,int a){
    k+=n-1;
    data[k]=a;
    while(k>0){
      k=(k-1)/2;
      data[k]=min(data[k*2+1],data[k*2+2]);
    }
  }

  int minquery(int a,int b){
    return search(a,b+1,0,0,n);
  }
private:
  //[a,b)の最小値,kは今の場所,[l,r)はkの守備範囲
  int search(int a,int b,int k,int l,int r){
    if(r<=a||b<=l)return INF;
    if(a<=l&&r<=b)return data[k];
    else {
      int vl=search(a,b,k*2+1,l,(l+r)/2);
      int vr=search(a,b,k*2+2,(l+r)/2,r);
      return min(vl,vr);
    }
  }

};

int main()
{
  cin>>N;
  C.resize(N);
  vector<int> A(N);
  A[0]=C[0]=0;
  repeat(i,1,N)cin>>C[i]>>A[i];

  Segment_Tree ST(N);
  
  vector<int> grundy(N);
  grundy[0]=0;
  ST.update(0, 0);
  repeat(n,1,N){
    if(ST.query(n-C[n], n-1)!=0)grundy[n]=0;
    else grundy[n]=1;
  }

  int flg=0;
  rep(i,N)if(A[i]>0 and A[i]%2)flg^=grundy[i];


  cout<<(flg!=0 ? "First" : "Second")<<endl;
  
  return 0;
}
