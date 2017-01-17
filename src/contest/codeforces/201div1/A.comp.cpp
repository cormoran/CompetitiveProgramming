/*
  --- 
  title : -A.comp.cpp
  date : 2015-10-29
  status : NULL
  ---
  
  # Memo

  
 */

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cassert>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>
T gcd(T a,T b){
    T c=a,d=b,r;
    do{r=c%d;c=d;d=r;}while(r);
    return c;
}



bool solve(){
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<int> A(n);
    int max_a=0;
    rep(i,n){
        cin>>A[i];
        max_a = max(max_a,A[i]);
    }
    
    for(int i = n-1;i>=0;i--){
        rep(j,i){
            A[j] = gcd(A[j],A[j+1]);
            //cout <<A[j]<<" ";
        }
        //cout<<endl;
    }

    
    int set_count = max_a /  A[0] - n;

    cout << (set_count %2 == 1 ? "Alice" : "Bob")<<endl;
    
    return false;
}

int main()
{
    while(solve());
    return 0;
}
