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
#include<map>
  using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)

vector<bool> is_prime;

void make_primes(int n){
  is_prime.resize(n+1,true);
  is_prime[0]=is_prime[1]=false;
  for(int i=2;i<=n;i++){
    if(!is_prime[i])continue;
    for(int j=2;j*i<=n;j++){
      is_prime[i*j]=false;;
    }
  }
}

int main()
{
  make_primes(1000000);
  while(true){
    int a,d,n;
    cin>>a>>d>>n;
    if(a==0 and d==0 and n==0)break;
    int cnt=0;
    for(int i=a;;i+=d){
      if(is_prime[i]){
        cnt++;
        if(cnt==n){
          cout<<i<<endl;
          break;
        }
      }
    }
  }
  
  return 0;
}
