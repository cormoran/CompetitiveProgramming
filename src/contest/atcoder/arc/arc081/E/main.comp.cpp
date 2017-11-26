#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;


class Solver {
  public:
    bool solve() {
        const int NA = 'z' - 'a' + 1;
        string A; cin >> A;
        int N = A.size();
        rep(i, A.size()) A[i] -= 'a';
        int rec = 0;
        int cnt = 0;
        vector<int> contain(NA);
        vector<int> split;
       
        split.push_back(N - 1);
        for(int i = N - 1; i >= 0; i--) {
            char a = A[i];
            if(not contain[a]) {
                contain[a]++;
                cnt++;
                if(cnt == NA) {
                    fill(all(contain), 0);
                    rec++;
                    cnt = 0;
                    if(i > 0) split.push_back(i - 1);
                }
            }
        }
        string ans;
        if(cnt > 0) split.pop_back();       
        rep(i, NA) {
            if(not contain[i]) {
                ans.push_back('a' + i);
                break;
            }
        }        
        reverse(all(split));        
        rep(i, rec) {
            vector<int> c(NA), c_backup;
            int cnt = 0;
            int j;
            for(j = split[i]; cnt < NA; j--) {
                cnt += c[A[j]] == 0;                
                if(A[j] + 'a' == ans.back()) c_backup = c;
                c[A[j]] = 1;
            }
            c = c_backup;
            // if(cnt < NA - 1) c[A[j]] = 1;
            rep(k, NA) {
                if(not c[k]) {
                    ans.push_back(k + 'a');
                    break;
                }
            }            
        }
        cout << ans << endl;
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
