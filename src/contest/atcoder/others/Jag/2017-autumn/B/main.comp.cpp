#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

char parse(string::iterator &itr, map<char, int> &cnt) {
    if(isalpha(*itr)) return *(itr++);
    assert(*(itr++) == '[');
    char a = parse(itr, cnt);
    assert(*(itr++) == '-');
    char b = parse(itr, cnt);
    assert(*(itr++) == ']');
    char win = cnt[a] > 0 ? a : b;
    cnt[win]--;
    return win;
}

int main() {
    string S; cin >> S;
    map<char, int> cnt;
    for(char c : S) cnt[c] = 0;
    rep(i, cnt.size()) {
        char c;
        int n;
        cin >> c >> n;
        assert(cnt.count(c));
        cnt[c] = n;
    }
    auto itr = begin(S);
    parse(itr, cnt);
    bool ok = true;
    for(auto p : cnt) ok &= p.second == 0;
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
