#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>
using namespace std;

typedef long int64;
typedef int int32;
typedef char int8;
typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

#define MAX_OUT 10000000
#define MAX_IN 10000001

vector<int64> Prime;

void PrimeGenarate(){
  vector<bool> num(MAX_IN,true);
  num[0]=false;num[1]=false;
  for(int64 i=2;i*i<=MAX_IN;i++){
    if(!num[i])continue;
    for(int64 j=i+1;j*j<MAX_IN;j++)
      if(j%i==0)num[j]=false;
  }
  rep(i,MAX_IN)
    if(num[i])Prime.push_back(i);
}

inline void PrimeAdd(int64 n,vector<int64> &psum){
  rep(i,Prime.size()){
    while(n>1&&n%Prime[i]==0){
      psum[Prime[i]]++;
      n/=Prime[i];
    }
    if(n<=1&&n<Prime[i]*Prime[i])return;
  }
}

//出力最大を超えないように入れる
inline void make_ans(vector<int64> &vec,int64 num,int64 exp){
  rep(i,exp){
    int64 val=vec[vec.size()-1]*num;
    if(val>MAX_OUT)vec.push_back(num);
    else vec[vec.size()-1]=val;
  }
}

int main()
{
  iostream::sync_with_stdio(false);
  int64 n,m;cin>>n>>m;
  vector<int64> a_prime(MAX_IN+1,0),b_prime(MAX_IN+1,0);
  PrimeGenarate();
  int64 max_in=0;
  rep(i,n){
    int64 a;cin>>a;
    PrimeAdd(a, a_prime);
    max_in=max(max_in,a);
  }
  rep(i,m){
    int64 b;cin>>b;
    PrimeAdd(b, b_prime);
    max_in=max(max_in,b);
  }
  
  vector<int64> a_out,b_out;
  a_out.push_back(1);
  b_out.push_back(1);
  
  rep(i,max_in+1){
    if(a_prime[i]||b_prime[i]){
      int64 diff=a_prime[i]-b_prime[i];
      if(diff>0)
	make_ans(a_out,i,diff);
      else if(diff<0)
	make_ans(b_out,i,-diff);
    }
  }

  cout<<a_out.size()<<" "<<b_out.size()<<endl;
  rep(i,a_out.size()-1)cout<<a_out[i]<<" ";
  cout<<a_out[a_out.size()-1]<<endl;
  
  rep(i,b_out.size()-1)cout<<b_out[i]<<" ";
  cout<<b_out[b_out.size()-1]<<endl;

  return 0;
}
