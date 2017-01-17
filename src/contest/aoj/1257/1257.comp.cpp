/*
  file : /1257.comp.cpp
  date : 2015-10-19
  summary :
  {
  2<=n<=10^4 なるnを連続する素数の和で表す時、その表し方は何通りある？
  }
  status :
  {
  
  }
  memo :
  {
  
  }
 */

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cassert>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

#define N_MAX 10000
vector<int> sum_prime;

void init(){
    vector<bool> is_prime(N_MAX+1,true);
    is_prime[0]=is_prime[1]=false;
    repeat(i, 2, is_prime.size()){
        if(is_prime[i]){
            for(int j=i*2;j<(int)is_prime.size();j+=i)is_prime[j]=false;
        }
    }
    int prime_num=0;
    int sum =0;
    sum_prime.reserve(N_MAX);
    sum_prime.push_back(0);
    rep(i,is_prime.size()){
        if(is_prime[i]){
            prime_num++;
            sum += i;
            sum_prime.push_back(sum);
        }
    }
}

bool solve(){
    int n;cin>>n;
    if(n==0)return false;
    int ans =0;
    for(int sum : sum_prime){
        int need = sum + n;
        auto itr =lower_bound(all(sum_prime),need);
        if(itr != sum_prime.end() && *itr == need) ans++;
    }
    cout <<ans <<endl;
    
    return true;
}

int main()
{
    init();
    while(solve());
    return 0;
}
