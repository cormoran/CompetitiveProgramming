#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
//#define debug(x) cerr << #x << " : " << x << endl
#define debug(...)

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
    int N;
    vector<string> S;
    bool contain(const string &s, const string &word) {
        rep(i, s.size()) {
            bool ok = true;
            rep(j, word.size()) {
                if(i + j >= s.size() or s[i + j] != word[j]) {
                    ok = false; break;
                }
            }
            if(ok) return true;
        }
        return false;
    }
    vector<string> merge(const string &s, const string &word) {
        vector<string> res;
        repeat(i, s.size() - word.size(), s.size())  {
            if(i < 0) continue;
            bool ok = true;
            rep(j, word.size()) if(i + j < s.size() and s[i + j] != word[j]) ok = false;
            if(ok) {
                int same = s.size() - i;
                res.emplace_back(s + word.substr(same));
            }
        }
        res.emplace_back(s + word);
        return res;
    }
    string calc(const string &s, int flg) {
        debug(s);
        string res;
        rep(i, N) if(not (flg & (1 << i))) {
            auto t = merge(s, S[i]);
            for(string &tt : t) {                
                string res2 = calc(tt, flg | (1 << i));
                if(res.size() == 0 or res2.size() < res.size()) res = res2;
                else if(res2.size() == res.size()) set_min(res, res2);
            }
        }
        if(res.size() > 0) return res;
        return s;
    }
            
    bool solve() {
        cin >> N;
        if(N == 0) return false;        
        S.resize(N); cin >> S;
        vector<string> T;
        rep(i, N) {
            bool ok =true;
            rep(j, N) if(i != j) {
                if(S[i] == S[j]) {
                    if(i > j) {
                        ok = false;
                        break;
                    }
                }
                else if(contain(S[j], S[i])) {
                    ok = false;
                    break;
                }                    
            }
            if(ok) T.push_back(S[i]);
        }
        debug(N); debug(S); debug(T);
        swap(S, T);
        N = S.size();
        cout << calc("", 0) << endl;
        return true;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(Solver().solve());
    return 0;
}
