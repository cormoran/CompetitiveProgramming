#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,j) for(int (i)=0;(i)<(j);(i)++)
#define rall(x) x.rbegin(),x.rend()
#define P(x) (x+501)
typedef pair<int,int> pii;
int main()
{
  string s;cin>>s;
  vector<int> pt;
  pt.reserve(s.size());
  int sum=0;
  for(int i=s.size()-1;i>=0;i--){
    if(s[i]=='+')sum++;
    else if(s[i]=='-')sum--;
    else if(s[i]=='M')pt.push_back(sum);
  }
  sort(rall(pt));
  int ans=0;
  rep(i,pt.size()){
    if(i<pt.size()/2)ans+=pt[i];
    else ans-=pt[i];
  }
  cout<<ans<<endl;
  return 0;
}
