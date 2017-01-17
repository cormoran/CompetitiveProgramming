/* Longest Increasing Subsequence 最長増加部分列*/
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vector<int> v;
  v.reserve(n);
  rep(i,n){
    int a;
    cin>>a;
    auto itr=lower_bound(all(v), a);
    if(itr==v.end())v.push_back(a);
    else *itr=a;
  }
  cout<<v.size()<<endl;
  return 0;
}
