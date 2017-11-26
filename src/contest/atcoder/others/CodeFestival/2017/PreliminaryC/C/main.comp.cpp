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
        string S; cin >> S;
        bool ok = true;
        int l = 0, r = S.size() - 1;
        while(l < r) {
            while(l < r and S[l] == 'x') l++;
            while(l < r and S[r] == 'x') r--;
            if(l < r and (S[l] != S[r])) {
                ok = false;
                break;
            }
            while(l < r and S[l] == S[r]) {
                l++; r--;
            }            
        }
        // debug(l); debug(r);
        if(not ok) {
            cout << -1 << endl;
        } else {
            if(l == r) {
                int ans = 0;
                int i = 0;
                int j = S.size() - 1;
                while(i < j) {
                    while(S[i] != S[j]) {
                        if(S[i] == 'x') {
                            ans++;
                            i++;
                        }
                        else if(S[j] == 'x') {
                            ans++;
                            j--;
                        }
                    }
                    i++; j--;
                }
                cout << ans << endl;
            } else {
                int len = max<int>(l, S.size() - r - 1);
                                int ans = 0;
                int i = 0;
                int j = S.size() - 1;
                while(i + 1 < j) {
                    while(S[i] != S[j]) {
                        if(S[i] == 'x') {
                            ans++;
                            i++;
                        }
                        else if(S[j] == 'x') {
                            ans++;
                            j--;
                        }
                    }
                    i++; j--;
                }
                cout << ans << endl;
            }            
        }
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
