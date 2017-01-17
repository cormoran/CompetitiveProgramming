//  codeforces - 332 - A  / 2016-01-07
#include<iostream>
#include<string>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)

bool solve(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    rep(i,s.size()){
        if(i >= 3 and  i % n == 0){
            if(s[i-1] == s[i-2] and s[i-2] == s[i-3]){
                ans++;
            }
        }
    }
    cout << ans <<endl;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
