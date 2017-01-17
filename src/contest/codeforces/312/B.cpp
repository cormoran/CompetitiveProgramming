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
#include<map>
  using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)
typedef pair<int,int> pii;

int main()
{
  int n;cin>>n;
  map<int,int> backet;
  vector<pii> numbers(n);
  rep(i,n){
    int a;cin>>a;
    numbers[i]=make_pair(a, i);
    backet[a]++;
  }
  int max_cnt=0;
  vector<int> max_nums;
  for(auto p : backet){
    if(p.second>max_cnt){
      max_nums.clear();
      max_nums.push_back(p.first);
      max_cnt=p.second;
    }
    else if(p.second == max_cnt){
      max_nums.push_back(p.first);
    }
  }

  sort(all(numbers));

  int l=1,r=n;
  rep(i,max_nums.size()){
    auto head = lower_bound(all(numbers), make_pair(max_nums[i],0));
    int l2=n,r2=0;
    while(head!=end(numbers) and head->first==max_nums[i]){
      l2=min(l2,head->second+1);
      r2=max(r2,head->second+1);
      head++;
    }
    if(r2-l2+1 < r-l+1){
      l=l2;r=r2;
    }
  }
  printf("%d %d\n",l,r);
  
  return 0;
}
