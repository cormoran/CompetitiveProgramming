/*
  file : /B.comp.cpp
  date : 2015-10-22
  status :
  {
  
  }
  memo :
  {
  
  }
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
    string s;
    cin>>s;
    stack<char> stk;
    rep(i,s.size()){
        if(!stk.empty() && s[i]==stk.top()){
            stk.pop();
        } else {
            stk.push(s[i]);
        }
    }

    cout << (stk.empty() ? "Yes" :"No") <<endl;
    
    return false;
}

int main()
{
    while(solve());
    return 0;
}
