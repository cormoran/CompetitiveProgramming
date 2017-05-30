#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

int main() {
    string S; cin >> S;
    int win = 0, g = 0;
    for(char c : S) {
        if(g > 0) {
            g--;
            win += c == 'g';
        } else {
            g++;
            win -= c == 'p';
        }
    }
    cout << win << endl;
    return 0;
}
