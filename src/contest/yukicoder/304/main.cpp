#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
int main() {
    int n = 0;
    cout.fill('0');
    while(true) {
        cout << setw(3) << n++ << endl;
        cout.flush();
        string s; cin >> s;
        if(s == "unlocked") break;
    }
    return 0;
}
