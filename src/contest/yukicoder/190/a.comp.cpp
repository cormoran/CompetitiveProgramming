#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    bool solve() {
        int N; cin >> N;
        vector<int> A(2 * N); cin >> A;
        vector<int> p, m;
        int zero = 0;
        for(int a : A) {
            zero += a == 0;
            if(a > 0) p.push_back(a);
            if(a < 0) m.push_back(a);
        }
        sort(all(p), greater<int>());        
        sort(all(m));

        auto f = [](const vector<int> &p, const vector<int> &m, int zero, int sign) {            
            int ret = 0;
            if(p.size() > 0) {
                int pi = 0;
                for(int mv : m) {
                    if((sign == 0 and mv + p[pi] == 0) or
                       (mv + p[pi]) * sign > 0) {
                        ret++;
                        pi++;
                    }                    
                    if(pi >= p.size()) break;
                }
                if(sign != 0) {
                    int a = min<int>(p.size() - pi, zero);
                    ret += a;
                    pi += a;
                    ret += (p.size() - pi) / 2;
                }
            }
            if(sign == 0) ret += zero / 2;
            return ret;
        };

        int z = 0;
        map<int, int> a;
        for(int i : p) a[i]++;
        for(int i : m) if(a[abs(i)] > 0) {
                z++;
                a[abs(i)]--;
            }
        z += zero / 2;
        
        cout << f(m, p, zero, -1) << " " << f(p, m, zero, 1) << " " << z << endl;;
        
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Solver s;
    s.solve();
    return 0;
}
