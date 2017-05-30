#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

int get_int(const string &S, int &pos) {
    int beg = pos;
    for(; isdigit(S[pos]); pos++);    
    return stoi(S.substr(beg, pos - beg + 1));
}

class Solver {
  public:
    string S, buf;
    int pos, N;
    
    void solve2() {
        bool paren = S[pos] == '(';
        if(paren) pos++;
        do {
            if(isdigit(S[pos])) {
                int rec = get_int(S, pos);
                if(S[pos] == '(') {
                    int now = pos;
                    rep(i, rec) {
                        pos = now;
                        solve2();                        
                        if(buf.size() > N) return;
                    }
                } else {
                    rep(i, rec) {
                        buf.push_back(S[pos]);
                        if(buf.size() > N) return;
                    }
                    pos++;
                }
            } else if(isalpha(S[pos])) {
                do {
                    buf.push_back(S[pos++]);
                } while(paren and isalpha(S[pos]) and buf.size() <= N);
            } else assert(0);
        } while(paren and S[pos] != ')' and buf.size() <= N);
        if(paren) pos++;
    }
    
    bool solve() {
        cin >> S >> N;
        if(S == "0" and N == 0) return false;
        
        while(buf.size() <= N and pos < S.size()) solve2();
        
        cout << (buf.size() <= N ? "0" : buf.substr(N, 1)) << endl;        
        return true;
    }
    
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int i = 0;
    while(true) {
        Solver s;
        if(not s.solve()) break;
    }
    return 0;
}
