#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
typedef long long ll;
#define rep(i,j) for(ll i=0;i<(j);i++)

ll K,N;
vector<int> A;
vector<int> D;

bool check(ll X){
  ll cnt=0;
  rep(i,N){
    if(X>=A[i]){
      cnt+=(X-A[i])/D[i]+1;
      if(cnt>=K)return true;
    }
  }
  return false;
}

ll get_cost(ll X){
  ll cost=0;
  ll allcnt=0;
  vector<ll> lst;
  rep(i,N){
    ll add=(X-A[i])/D[i]+1;
    if(add>0){
      allcnt+=add;
      cost+=A[i]*add+add*(add-1)/2*D[i];
      lst.push_back(A[i]+D[i]*(add-1));
    }
    //printf("bulding%d : %lldcnt\n",i,add);
  }
  sort(begin(lst),end(lst),greater<ll>());
  rep(i,allcnt-K){
    cost-=lst[i];
  }
  return cost;
}

int main(){
  cin>>K>>N;
  A.resize(N);
  D.resize(N);
  rep(i,N){
    cin>>A[i]>>D[i];
  }
  //建物がX円超えないような条件でK回以上できる？
  ll l=0,r=1LL<<62;
  //(l,r]
  while(l+1<r){
    ll m=(r+l)/2;
    if(check(m))r=m;
    else l=m;
  }
  cout<<get_cost(r)<<endl;
  
  return 0;
}
