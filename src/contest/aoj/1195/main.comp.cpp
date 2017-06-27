#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()

class Solver {
  public:
    bool solve() {
        string T; cin >> T;
        if(T == "#") return false;
        priority_queue<string> firsts;
        priority_queue<string, vector<string>, greater<string>> lasts;
        int cnt = 0;
        for(int flg = 0; flg < (1 << T.size()); flg++) {
            string s = T;
            vector<int> swaped('z' - 'a' + 1);
            vector<int> need_swap('z' - 'a' + 1);
            for(int i = s.size() - 1; i >= 0; i--) {
                if(flg & (1 << i)) {
                    if(s[i] == 'z') goto FAIL;
                    s[i]++;
                    if(swaped[s[i] - 'a']) goto FAIL;
                    swaped[s[i] - 'a'] = true;                    
                } else {
                    if(swaped[s[i] - 'a']) goto FAIL;
                    if(s[i] != 'a') need_swap[s[i] - 'a'] = true;
                }
            }
            rep(i, 'z'- 'a' + 1) {
                if(need_swap[i] and not swaped[i]) goto FAIL;
            }
            firsts.push(s);
            lasts.push(s);
            cnt++;
            if(firsts.size() > 10) firsts.pop();           
            if(lasts.size() > 10) lasts.pop();

      FAIL:;
        }
        cout << cnt << endl;
        vector<string> res;
        if(cnt <= 10) {            
            while(firsts.size()) {
                res.push_back(firsts.top());
                firsts.pop();
            }
            reverse(all(res));
        } else {
            while(firsts.size() > 5) firsts.pop();           
            while(lasts.size() > 5) lasts.pop();
            while(firsts.size()) {
                res.push_back(firsts.top());
                firsts.pop();
            }
            reverse(all(res));
            while(lasts.size()) {                
                res.push_back(lasts.top());
                lasts.pop();
            }
        }
        for(auto s : res) cout << s << endl;
        return true;
    }
};

int main() {    
    while(Solver().solve());
    return 0;
}
