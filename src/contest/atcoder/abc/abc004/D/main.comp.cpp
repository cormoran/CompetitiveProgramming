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

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

int main()
{
  int sum[1005];
  sum[0]=0;
  rep(i,1000)sum[i+1]=sum[i]+(i+1);

  int R,B,G;
  cin >> R >> G >> B;

  int ans=0;
  int ans_val=0;


  
  return 0;
}
