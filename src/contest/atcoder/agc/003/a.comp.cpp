#include<iostream>
#include<string>
#include<set>

using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

int main() {
    string S; cin >> S;
    set<char> s;
    rep(i, S.size()) s.insert(S[i]);
    if(s.count('N') == s.count('S') and
       s.count('W') == s.count('E')) cout << "Yes" << endl;
    else cout << "No" << endl;                
    return 0;
}
