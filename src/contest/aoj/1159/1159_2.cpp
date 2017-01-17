#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) begin(v),end(v)


int main()
{
  while(true){
    int n,p;
    cin>>n>>p;
    if(n==0)break;
    vector<int> v(n,0);
    int pp=p;
    while(true){
      rep(i,n){
        if(p>0){
          p--;
          v[i]++;
          if(v[i]==pp){
            cout<<i<<endl;
            goto END;
          }
        }
        else {
          p=v[i];
          v[i]=0;
        }
      }
    }
 END:;
    
  }
  return 0;
}
