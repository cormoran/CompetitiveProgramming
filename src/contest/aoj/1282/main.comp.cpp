#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    vector<string> S;
    map<char, map<ll, ll>> val;
    map<char, ll> len;
    bool out_of_range(char name, ll index) {
        return index >= len.at(name);
    }
    bool undefined(char name, ll index) {
        return not val[name].count(index);
    }
    ll get_number(int &i, string &s) {
        assert(isdigit(s[i]));
        ll res = 0;
        while(isdigit(s[i])) {
            res *= 10;
            res += (s[i++] - '0');
        }
        return res;
    }
    char get_name(int &i, string &s) {
        char name = s[i++];
        assert(('a' <= name and name <= 'z') or ('A' <= name and name <= 'Z'));
        return name;
    }
    tuple<ll, bool> get_expression(int &i, string &s) {
        auto fail = make_tuple(0, false);
        auto success = [](ll v) { return make_tuple(v, true); };
        bool ok;
        
        if(isdigit(s[i])) return success(get_number(i, s));
        char name = get_name(i, s);
        ll index; tie(index, ok) = get_bexpression(i, s);
        if(not ok) return fail;
        if(out_of_range(name, index) or undefined(name, index)) return fail;
        
        return success(val.at(name).at(index));
    }
    tuple<ll, bool> get_bexpression(int &i, string &s) {
        assert(s[i++] == '[');
        auto ret = get_expression(i, s);
        assert(s[i++] == ']');
        return ret;
    }
    
    void declaration(int &i, string &s) {
        char name = get_name(i, s);        
        assert(s[i++] == '[');
        ll num = get_number(i, s);
        assert(s[i++] == ']');
        assert(not len.count(name)); // only once
        len[name] = num;
    }

    bool assignment(int &i, string &s) {
        bool ok;
        
        char name = get_name(i, s);
        ll index; tie(index, ok) = get_bexpression(i, s);
        if(not ok) return false;        
        assert(s[i++] == '=');        
        ll right; tie(right, ok) = get_expression(i, s);
        if(not ok) return false;        

        // check
        if(out_of_range(name, index)) return false;
        val[name][index] = right;
        return true;
    }
    
    bool solve() {
        while(true) {
            string s; cin >> s;
            if(s == ".") break;
            S.push_back(s);
        }
        
        if(S.size() == 0) return false;
        rep(i, S.size()) {
            int pos = 0;
            if(S[i].find("=") == string::npos) declaration(pos, S[i]);
            else {
                bool ok = assignment(pos, S[i]);
                if(not ok) {
                    cout << i + 1 << endl;
                    return true;
                }
            }
            assert(pos == S[i].size());
        }
        cout << 0 << endl;
        return true;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(Solver().solve());
    return 0;
}
