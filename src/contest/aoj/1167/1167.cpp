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
#define all(v) v.begin(),v.end()

vector<int> tetrahedron_sum;


void create_sum(){
  tetrahedron_sum.resize(1000 * 1000);

  rep(i,tetrahedron_sum.size()){
    tetrahedron_sum[i]=i*(i+1)*(i+2)/6;
  }
  
}


int solve1(int n,int k,int sec){
  if(sec>=5)return 100;
  
  int succ = n-tetrahedron_sum[k];

  if(succ==0)return sec;
  else if(succ<0)return 100;
  
  return min(solve1(succ, k+1, sec++),
             solve1(n, k+1, sec)
             );
}

int solve2(int n,int k,int sec){
  if(sec>=5)return 100;
  
  int succ = n-tetrahedron_sum[k];

  if(succ==0)return sec;
  else if(succ<0)return 100;
  
  return min(solve2(succ, k+2, sec++),
             solve2(n, k+2, sec)
             );
}

int main()
{
  create_sum();

  while(true){
    int n;
    cin>>n;
    if(n==0)break;
    
    cout<<solve1(n, 1, 0)<<" ";
    cout<<solve2(n, 2, 0)<<endl;
    
  }
  
  return 0;
}
