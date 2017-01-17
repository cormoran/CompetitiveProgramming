#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>


using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,j) for(ll i=0;i<(j);i++)

struct Student{
  int i,j;
  int g;
};

bool comp_G(const Student &l,const Student &r){
  return l.g!=r.g ? l.g<r.g : (l.i!=r.i ? l.i<r.i:l.j<r.j);
}

bool comp_j(const Student &l,const Student &r){
  return  l.j!=r.j ? l.j<r.j :l.i<r.i;
}

int main(){
  ll N,M;
  cin>>N>>M;
  ll x0,a,p;
  cin>>x0>>a>>p;

  vector< Student > S(N*M);
  
  rep(i,N*M){
    S[i].g=((ll)x0+(ll)a*i)%p;
    S[i].i=i/M;
    S[i].j=i%M;
  }
  S[0].g=x0;

  sort(S.begin(),S.end(),comp_G);

  ll ans=0;
  rep(i,N){
    sort(&S[i*M],&S[i*M+M],comp_j);
    rep(j,M){
      ll dx=abs(S[i*M+j].i-i);
      ll dy=abs(S[i*M+j].j-j);
      ans+=dx+dy;
    }
  }
  cout<<ans<<endl;
  return 0;
}
