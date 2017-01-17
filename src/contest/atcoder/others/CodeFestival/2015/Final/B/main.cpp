#include<iostream>
using namespace std;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)

bool solve(){
    ll n;cin>>n;
    int ans=-1;
    if(n==1)ans=1;
    if(n>=2)ans = 7;
    for(int i=2;i<n;i++){
        ans += (i%2 ? 4 : 3);
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
