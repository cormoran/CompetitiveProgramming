#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;
typedef long long i64;typedef int i32;
typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

struct pair_hash {
  inline size_t operator()(const std::pair<i64,i64> & v) const {
    return v.first*1000000+v.second;      
  }
};

int main()
{
  int R,C,K,N;
  cin>>R>>C>>K>>N;

  vector< pair<int,int> > Rv(R,make_pair(0,0));
  vector< pair<int,int> > Cv(C,make_pair(0,0));
  unordered_set<pair<i64,i64>,pair_hash > st;
  
  rep(i,R)Rv[i].second=i;
  rep(i,C)Cv[i].second=i;
  rep(i,N){
    int r,c;
    scanf("%d%d",&r,&c);
    r--;c--;
    Rv[r].first++;
    Cv[c].first++;
    st.insert(make_pair(r, c));
  }
  //sort(all(Rv));
  sort(all(Cv));
  
  i64 ans=0;
  rep(i,R){
    if(Rv[i].first>K)continue;
    auto s=lower_bound(all(Cv),make_pair(K-Rv[i].first,0));
    for(auto itr=s;itr!=Cv.end()and itr->first<K-Rv[i].first+2;itr++){
      if(st.find(make_pair(i,(i64)itr->second))!=st.end()){
        if(itr->first==K-Rv[i].first+1)ans++;
      }
      else{
        if(itr->first==K-Rv[i].first)ans++;
      }
    }
  }
  
  cout<<ans<<endl;
  
  return 0;
}
