#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,j) for(int i = 0; i < (int)(j); i++)
#define repeat(i,k,j) for(int i = k; i < (int)(j); i++)

int main(){
  int N;
  cin >> N;
  vector<int> S(N);
  rep(i, N) cin >> S[i];
  int ans = 1;
  repeat(t, 1, N+1){
    if(N % t != 0) continue;
    bool flg = true;
    rep(i, N){
      if(S[i] != S[i%t]){
	flg = false;
	break;
      }
    }
    if(flg){
      ans = max(ans, N / t);
    }
  }
  cout << ans << endl;
}
