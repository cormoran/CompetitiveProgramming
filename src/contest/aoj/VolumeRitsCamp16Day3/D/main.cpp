#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
#define rep(i,j) for(int i = 0; i < (int)(j); i++)
#define repeat(i,k,j) for(int i = k; i < (int)(j); i++)
typedef long long ll;
class BIT{
public:
  vector<int> data;
  BIT(int n){
    data.resize(n+1);
  }
  int sum(int idx){
    if(idx < 0) return 0;
    int s = 0;
    while(idx){
      s += data[idx];
      idx -= idx & (-idx);
    }
    return s;
  }
  // sum[k[l,r]
  int sum(int l, int r){
    return sum(r) - sum(l-1);
  }
  void add(int i, int x){
    while(i <= data.size()){
      data[i] += x;
      i += i & (-i);
    }
  }
  int binary_search(int x, int N){
    int r = N+1, l = 1;

    //rep(now,N+1){
    //cout << sum(now, N) << (now == N ? "\n" : " ") ;
    //}
    while(r - l > 1){
      int now = (r + l) / 2;
      if(sum(now, N) >= x) l = now;
      else r = now;
    }
    return l;
  }
};

ll query(int l, int r){
  printf("? %d %d\n", l, r);
  fflush(stdout);
  ll a; cin >> a;
  return a;
}

int main(){
  int N;
  cin >> N;
  vector<int> P(N);
  BIT bit(N);
  ll now = query(1, N);
  ll next;
  for(int i = 1; i <= N; i++) bit.add(i,1);
  
  for(int i = N-1; i >= 0; i--){
    if(i == 0) next = 0;
    else next = query(1, i);

    ll d = now - next;
    P[i] = bit.binary_search(d+1, N);
    
    bit.add(P[i], -1);
    now = next;

  }
  cout << "! "; 
  rep(i, N){
    cout << P[i] << (i != N-1 ? " " : "\n");
  }
  return 0;
}
