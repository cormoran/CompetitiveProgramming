#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<set>
using namespace std;

typedef long long int64;
typedef int int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define all(v) v.begin(),v.end()
typedef unsigned long long ull;
const ull HashBase = 100000007;

/*
  s := s1 s2 ... sn
  
  hash[1_to_i] := s1*b^(i-1) + s2*b^(i-2) + ... + si*b^0
  
  hash[1_to_j] := s1*b^(j-1) + s2*b^(j-2) + ... + si*b^(j-i) + ... + sj*b^0
  
  
  hash[(i+1)_to_j] = hash[1_to_j] - hash[1_to_i]*b^(j-i)
  
                   = s(i+1)*b^(j-i-1) + ... + sj*b^0
*/


int main()
{
  int n,m;string s;
  cin>>n>>m>>s;
  
  vector<ull> hash(n+1);
  vector<ull> pow_base(n+1);

  hash[0]=0;pow_base[0]=1;
  rep(i,n){
    hash[i+1] = hash[i]*HashBase + s[i];
    pow_base[i+1]=pow_base[i]*HashBase;
  }
  
  int r=1,l=1;
  vector<ull> subhash;
  rep(i,m){
    string query;
    cin>>query;

    if(query=="L++")l++;
    else if(query=="L--")l--;
    else if(query=="R++")r++;
    else if(query=="R--")r--;

    subhash.push_back(hash[r]-hash[l-1]*pow_base[r-l+1]);
  }
  sort(all(subhash));

  cout<<unique(all(subhash))-subhash.begin()<<endl;
  
  return 0;
}
