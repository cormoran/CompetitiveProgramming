#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

typedef long long i64;typedef int i32;
typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

int main()
{
  int N;
  cin>>N;
  set<int> st;
  int ans=0;
  rep(i,N){
    int A;
    cin>>A;
    if(st.find(A)!=st.end())ans++;
    st.insert(A);
  }
  cout<<ans<<endl;
  return 0;
}
