/*
  --- 
  title : -C.comp.cpp
  date : 2015-10-25
  status : AC
  ---
  
  # Memo
  貪欲
  
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


bool solve(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<int > A(n),B(m);
    rep(i,n)cin>>A[i];
    rep(i,m)cin>>B[i];
    sort(all(A));
    sort(all(B));
    int pos =0;
    rep(i,m){
        while(pos <(int)A.size() && B[i]>A[pos])pos++;
        if(pos >=(int)A.size()){
            cout<<"NO"<<endl;
            return 0;
        }
        pos++;
    }
    cout << "YES" <<endl;
    return false;
}

int main()
{
    while(solve());
    return 0;
}
