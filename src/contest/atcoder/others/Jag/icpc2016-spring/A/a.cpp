#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)

int main(){
    int n; cin >> n;
    int a = 0, b = 0;
    bool flg = true;
    rep(i, n) {
        string s; cin >> s;
        if(s == "A") a++;
        else if(s == "Un") b++;
        if(a < b) flg = false;
    }
    cout << (flg and a == b ? "YES" : "NO") << endl;
    
    return 0;
}
