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
  int A[5];rep(i,5)cin>>A[i];
  vector<int> sum;
  sum.resize(10);
  rep(i,5){
    rep(j,5){
      if(j==i)continue;
      rep(k,5){
        if(k==i||k==j)continue;
        sum.push_back(A[i]+A[j]+A[k]);
      }
    }
  }
  sort(all(sum));
  sum.erase( unique(all(sum)), sum.end() );
  reverse(all(sum));
  cout<<sum[2]<<endl;
  return 0;
}
