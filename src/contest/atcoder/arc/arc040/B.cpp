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


int main()
{
  int N,R;
  cin>>N>>R;
  string s;
  cin>>s;
  int sh=0;
  int lst=0;
  for(int i=s.size()-1;i>=0;i--){
    if(s[i]=='.'){
      sh++;
      i-=R-1;
      if(lst==0)lst=max(i,0);
    }
  }

  cout<<lst+sh<<endl;
  return 0;
}
