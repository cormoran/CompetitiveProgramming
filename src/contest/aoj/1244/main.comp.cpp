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

const int INF = 1 << 28;
const ll INFL = 1LL << 50;


class Solver {
  public:
    map<string, int> mapping;
    ll get_int(string &s, int &i) {
        //debug(s.substr(i));
        assert(isdigit(s[i]));
        ll res = 0;
        while(isdigit(s[i])) {
            res *= 10;
            res += s[i++] - '0';            
        }
        return res;
    }
    ll get_atom(string &s, int &i) {
        //debug(s.substr(i));
        assert('A' <= s[i] and s[i] <= 'Z');
        string atom;
        atom.push_back(s[i++]);
        while('a' <= s[i] and s[i] <= 'z') {
            atom.push_back(s[i++]);
        }
        return mapping.count(atom) ? mapping[atom] : -INFL;
    }
    ll calc(string &s, int &i) {
        //debug(s.substr(i));
        assert(s[i] == '(');
        i++;
        ll res = 0;
        while(s[i] != ')') {
            if(s[i] == '(') {
                ll sum = calc(s, i);
                if(sum < 0) return -INFL;
                ll num = get_int(s, i);
                res += sum * num;
            } else {
                ll sum = get_atom(s, i);
                if(sum < 0) return -INFL;
                ll num = 1;
                if(isdigit(s[i])) num = get_int(s, i);
                res += sum * num;
            }
        }
        i++;
        return res;
    }
    bool solve() {        
        while(true) {
            string s; cin >> s;
            if(s == "END_OF_FIRST_PART") break;
            ll w; cin >> w;
            assert(mapping.count(s) == 0);
            mapping[s] = w;
        }
        // for(auto p : mapping) {
        //     //debug(p);
        // }
        while(true) {
            string q; cin >> q;
            if(q == "0") break;
            int i = 0;
            q = "(" + q + ")";
            ll ans = calc(q, i);
            if(ans < 0) cout << "UNKNOWN" << endl;
            else cout << ans << endl;
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
