---
title        : codeforces-184div2-A
date         : 2015-11-19
contests     : codeforces
problemtypes :

---

# Strange Addition

<!--more-->

　よくやる any の意味間違い & ifで頑張ってバグらせで苦しんだ...

## 解法

  はじめに0か、ゼロでない桁が１つだけの数字を集める

  次に残りを調べて空いているところにうまく入れば入れる　


~~~
//  codeforces-184div2  / 2015-11-19
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)

int pop_count(int n){
    int cnt =0;
    while(n){
        if(n%10!=0)cnt++;
        n/=10;
    }
    return cnt;
}


bool comp(int n,int m){
    while( n > 0 and m > 0 ){
        if( n%10 and m%10 )return false;
        n /= 10;
        m /= 10;
    }
    return true;
}


int popup(int n,int used){
    int pow10 = 1;
    while( n ){
        if( n % 10 )used += pow10;
        n /= 10;
        pow10 *= 10;
    }
    return used;
}


bool solve(){
    int n; cin >> n;
    vector<int> v(n),ans;
    int used = 0;
    //非ゼロ 0 or 1つ
    rep(i,n){
        cin >> v[i];
        if( pop_count(v[i]) <= 1 and comp( used , v[i] ) ){
            ans.push_back( v[i] );
            used = popup(v[i], used);
            v[i] = -1;
        } 
    }
    //その他
    rep(i,n){
        if( v[i] >= 0 and comp( used, v[i] ) ){
            ans.push_back(v[i]);
            used = popup(v[i],used);
            v[i] = -1;
        } 
    }

    
    cout <<ans.size()<<endl;
    rep(i,ans.size()){
        cout << ans[i] << ( i==(int)ans.size()-1 ? "\n" : " ");
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~