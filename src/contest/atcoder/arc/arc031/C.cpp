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
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

template<typename BIT_T>
class BIT
{
  public:
  vector<BIT_T> bit;
  BIT(int n,int init)
  {
    bit.resize(n+1,init);   
  }
  //index 0 to i の和を返す
  BIT_T sum(int i)
  {
    BIT_T s=0;
    while(i>0){
      s+=bit[i];
      i-=i& (-i);//i& -i はiの最小1bit  <- 2^kを引く
    }
    return s;   
  }
  //index i to j の和
  BIT_T sum(int i,int j)
  {
    return sum(j)-sum(i-1);   
  }
  //index i に x をたす
  void add(int i,BIT_T x){
    while(i<=(int)bit.size()){
      bit[i]+=x;
      i+=i& (-i);
    }
  }
  BIT_T get_val(int i){
    return bit[i];
  }
};

int main()
{
  int n;cin>>n;
  vector<int> B;B.resize(n);
  vector<int> index;index.resize(n);
  int64 ans=0;
  BIT<int> bit(n,1);

  rep(i,n){
    cin>>B[i];
    B[i]--;
    index[B[i]]=i;
  }
  rep(i,n){
    ans+=min()
  }

  cout<<ans<<endl;
  return 0;
}










