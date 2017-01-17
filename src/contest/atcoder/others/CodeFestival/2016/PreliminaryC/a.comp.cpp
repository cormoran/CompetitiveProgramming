#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    int a = 0;
    for(char c : s) {
        if(a == 0 and c == 'C') a++;
        if(a == 1 and c == 'F') a++;
    }
    cout << ( a == 2 ? "Yes" : "No") << endl;
    return 0;
}
