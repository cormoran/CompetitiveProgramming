#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int push(vector<int> &n) {
    for(int i : n) cout << i;
    cout << endl;
    cout.flush();
    int x;
    string s;
    cin >> x >> s;
    return x;
}

int main() {
    vector<int> n(10);
    
    for(int i = 0; i < 10; i++) {
        int mx = 0, ok;
        for(int j = 0; j < 10; j++) {
            n[i] = j;
            int ret = push(n);
            if(ret == 10) return 0;
            if(ret >= mx) mx = ret, ok = j;            
        }
        n[i] = ok;
    }
    push(n);
    return 0;
}
