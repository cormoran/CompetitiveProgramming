#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solver {
  public:
    int correct = -1;
    int query(int v) {
        cout << "? " << v << endl;
        cout.flush();
        if(correct < 0) {
            int a; cin >> a;
            return a;
        } else {
            int res = v == correct ? 0 : correct > v ? 1 : -1;
            correct--;
            return res;
        }
    }    
    
    bool solve() {        
        int l = 9, r = 1e9 + 1;

        if(query(100) < 0) {
            r = 100;
        }
        
        for(int i = 1; i <= 100; i++) {
            int m = (l + r) / 2;
            int res = query(m - i);
            
            if(res > 0) l = m;
            if(res < 0) {
                r = m;                
            }
            if(res == 0) {                
                cout << "! " << m << endl;
                exit(0);
            }
        }
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a;
    a = -1;
    // cin >> a;
    Solver s;
    s.correct = a;
    s.solve();
    return 0;
}
