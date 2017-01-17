//  atcoder-Jag-icpc2015-asia-A  / 2015-11-22
#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)

bool solve(){
    string s,t; cin >> s >> t;
    bool flg = false;
    for(int i=0,ti=0;i<s.size();i+=2){
        while(s[i] != t[ti]){
            ti++;
            if(ti>=t.size())goto E1;
        }
        ti++;
    }
    flg = true;
E1:
    for(int i=1,ti=0;i<s.size();i+=2){
        while(s[i] != t[ti]){
            ti++;
            if(ti>=t.size())goto E2;
        }
        ti++;
    }
    flg = true;
E2:
    cout << ( flg ? "Yes" : "No") << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
