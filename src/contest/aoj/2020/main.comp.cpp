#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

struct Mola {
    char sym;
    string str;
};
ostream &operator << (ostream &os, const Mola &m) { return os << m.sym << "(" << m.str << ")"; }

const char BOIN = 'B', SIBO = 'S', SOKU = 'O', HATU = 'H', TYO = 'T';

set<char> bo = {'a', 'i', 'u', 'e', 'o'};

vector<Mola> decompose(string s) {    
    s += string(10, ' ');
    rep(i, s.size() - 10) if(!bo.count(s[i]) and s[i] != '\'' and s[i + 1] == 'y') {
        s[i] = toupper(s[i]);
        s.erase(i + 1, 1);
        i--;
    }
    int N = s.size() - 10;
    vector<Mola> res;
    set<char> aiu = {'a', 'i', 'u'};
    rep(i, N) {
        if(s[i] == 'n' and s[i + 1] == '\'') {
            res.push_back(Mola{HATU, s.substr(i, 2)});
            i++;
        }
        else if(!bo.count(s[i]) and bo.count(s[i + 1])) {
            res.push_back(Mola{SIBO, s.substr(i, 2)});
            i++;
        }        
        else if(s[i] == 'n' and s[i + 1] != 'y' and !bo.count(s[i + 1]) ) {
            res.push_back(Mola{HATU, s.substr(i, 1)});
        }
        else if(!bo.count(s[i]) and !bo.count(s[i + 1])) {
            assert(s[i + 2] != 'n' and s[i + 2] != 'y' and s[i + 2] != 'w');
            res.push_back(Mola{SOKU, s.substr(i, 1)});
        }
        else if(i > 0 and aiu.count(s[i - 1]) and aiu.count(s[i])) {  
            res.push_back(Mola{TYO, s.substr(i, 1)});
        }
        else if(bo.count(s[i])) {
            res.push_back(Mola{BOIN, s.substr(i, 1)});
        }
        else {
            cerr << i << s.substr(0, i) << " " << s.substr(i) << endl;            
            assert(0);
        }
    }
    // rep(i, res.size()) cerr << res[i] << " ";
    // cerr << endl;
    return res;
}

int main() {
    
    
    while(true) {
        string s; cin >> s;
        if(s == "#") break;
        auto m = decompose(s);
        int N = m.size();
        m.push_back(Mola{'x', " "});
        m.push_back(Mola{'x', " "});
        m.push_back(Mola{'x', " "});
        m.push_back(Mola{'x', " "});
        m.push_back(Mola{'x', " "});

        set<char> mu = {'k', 's', 't', 'h', 'p'};
        auto is_mu =[&] (char c) {
            return mu.count(tolower(c));
        };
        set<char> iu = {'i', 'u'};
        set<char> ao = {'a', 'o'};
        string ans;
        bool removable = true;
        rep(i, N) {
            if(m[i].sym == SIBO and
               is_mu(m[i].str[0]) and iu.count(m[i].str[1]) and (i == N - 1 or is_mu(m[i + 1].str[0]))) {
                ans += m[i].str.substr(0, 1);
                ans += removable ? "(" + m[i].str.substr(1, 1) + ")" : m[i].str.substr(1, 1);
                removable = !removable;
            }
            else if(m[i].sym == SIBO and m[i + 1].sym == SIBO
                    and is_mu(m[i].str[0]) and is_mu(m[i + 1].str[0])
                    and ao.count(m[i].str[1]) and ao.count(m[i + 1].str[1])
                    and m[i].str[1] == m[i + 1].str[1]) {
                ans += m[i].str.substr(0, 1);
                ans += removable ? "(" + m[i].str.substr(1, 1) + ")" : m[i].str.substr(1, 1);
                removable = !removable;
            }
            else {
                if(m[i].sym == BOIN or m[i].sym == SIBO or m[i].sym == TYO) removable = true;
                ans += m[i].str;
            }
        }
        string ans2;
        for(auto c : ans) {
            if(isupper(c)) {
                ans2.push_back(tolower(c));
                ans2.push_back('y');
            } else ans2.push_back(c);
        }
        cout << ans2 << endl;
    }
    return 0;
}
