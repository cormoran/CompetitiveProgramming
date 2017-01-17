#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}

bool solve() {
    int N; cin >> N;
    vector<string> S(N * 3); cin >> S;
    map<string, int> grundy = {
        {".#.", 0},
        {".##", 1},
        {"#.#", 0},
        {"##.", 1},
        {"###", 2}
    };
    set<string> fail = {"...", "..#", "#.."};
    
    int g = 0, turn = 0;
    string s = "...";
    rep(i, N) {
        if(i % 2 == 0) {
            rep(j, 3) s[j] = S[i * 3][j];
        } else {
            rep(j, 3) s[j] = S[i * 3 + j][0];
        }
        if(fail.count(s)) {
            g = 0;
            break;
        }
        rep(j, 3) turn += s[j] == '.';
        g ^= grundy[s];
    }
    if(turn % 2) g = !g;
    cout << (g == 0 ? "Sothe" : "Snuke") << endl;
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
