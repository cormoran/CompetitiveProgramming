#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<cstdint>
//#include<>
using namespace std;

typedef int64_t i64;typedef int32_t i32;
typedef int16_t i16;typedef int8_t i8;
typedef uint64_t ui64;typedef uint32_t ui32;
typedef uint16_t ui16;typedef uint8_t ui8;

typedef i32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//=10E10

int main()
{
  i32 n,k;
  cin>>n>>k;
  vector< pair<i32,i32> > a(n);
  rep(i,n){
   cin>>a[i].first;
   a[i].second=i+1;
  }
  sort(all(a));

  i32 sum=0;

  rep(i,n){
    sum+=a[i].first;
    if(sum>k){
      cout<<i<<endl;
      if(i>0){
	rep(j,i-1)cout<<a[j].second<<" ";
	cout<<a[i-1].second<<endl;
      }
      return 0;
    }
  }
  cout<<n<<endl;
  rep(j,n-1)cout<<a[j].second<<" ";
  cout<<a[n-1].second<<endl;
  return 0;
}
