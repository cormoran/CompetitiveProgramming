#include<bits/stdc++.h>

using namespace std;

typedef long long int64;typedef int int32;
typedef long long ll;

typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)


int main()
{
  int n;
  cin>>n;
  list<int> lst1,lst2;
  list<int> lst1_org,lst2_org;
  int n1;cin>>n1;
  rep(i,n1){
    int a;cin>>a;
    lst1.push_back(a);
  }
  int n2;cin>>n2;
  rep(i,n2){
    int a;cin>>a;
    lst2.push_back(a);
  }
  lst1_org=lst1;
  lst2_org=lst2;
  int fst1=lst1.front();
  int fst2=lst2.front();
  int cnt=0;
  int ii=0;
  while(lst1.size()!=0 and lst2.size()!=0 and ii<200){
    int a=lst1.front();lst1.pop_front();
    int b=lst2.front();lst2.pop_front();
    
    if(a>b){
      lst1.push_back(b);
      lst1.push_back(a);
    }
    else{
      lst2.push_back(a);
      lst2.push_back(b);
    }
    cnt++;
    ii++;
  }
  if(ii>=200){
    cout<<-1<<endl;
    return 0;
  }
  if(lst1.empty()){
    cout<<cnt<<" "<<2<<endl;
  }
  else{
    cout<<cnt<<" "<<1<<endl;
  }
  
  return 0;
}
