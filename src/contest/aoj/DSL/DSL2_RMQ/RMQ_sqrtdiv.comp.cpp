#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

//ll型のn個配列をあらかじめ別に作っておく
template<typename T = int>
class RangeMinimumQuery{
  public:
    const int INF = (1LL<<31)-1;
    vector<T> v,sqrt_v;
    int block_size;
    RangeMinimumQuery(const vector<T> &v):v(v){ build();}
    RangeMinimumQuery(size_t n){ v=vector<T>(n,INF); build();}
    
    void build(){
        sqrt_v.clear();
        block_size = sqrt(v.size()) + 1 ;
        sqrt_v.resize( ceil(v.size() / block_size ) );
        
        rep(i,sqrt_v.size()){
            T mini = INF;
            rep(j,block_size){
                if(mini>v[i*block_size + j]){
                    mini = v[i*block_size + j];
                }
            }
            sqrt_v[i] = mini;
        }
    }

    void update(int idx,T value){
        v[idx] = value;
        int pos = idx / block_size;
        sqrt_v[pos] = min(sqrt_v[pos],value);
    }
    //from [l,r]
    T query(int l, int r){
        l = ceil( l / block_size );
        r = ceil( r / block_size );
        T ret = INF;
        for(;l<=r;l++){
            ret = min( ret , sqrt_v[l] );
        }
        return ret;
    }
    
};

int main(){
  int n,q; cin>>n>>q;
  RangeMinimumQuery<int> rmq(n);
  rep(i,q){
      bool query;
      int x,y; cin>>query>>x>>y;
      if(query) cout<<rmq.query(x,y)<<endl;
      else rmq.update(x,y);
  }
  rep(i,n-1) cout<<rmq.v[i]<<" ";
  cout << rmq.v.back() <<endl;
  return 0;
}
