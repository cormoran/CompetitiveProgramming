#include<iostream>
#include<string>
#include<map>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)

bool solve(){
    ll n;cin>>n;
    map<ll,ll> a[2];a[0][0]=1;
    ll i=0;
    rep(k,n){
        for(auto item : a[i%2]){
            ll nxt = (i+1)%2;
            rep(j,6){
                a[nxt][item.first+j+1]+=item.second;
            }
        }
        a[i%2].clear();
        i++;
    }
    ll ans=-1,cnt=-1;
    for(auto item : a[i%2]){
        if(cnt < item.second){
            ans = item.first;
            cnt = item.second;
        }
    }
    cout <<ans<<endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
