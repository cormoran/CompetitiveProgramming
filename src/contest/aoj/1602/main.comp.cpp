#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<functional>
#include<ctype.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}

int calc_depth(string &s) {
    rep(i, s.size()) if(s[i] != '.') return i;
    assert(0);
}

int calc(vector<string> &line, int &now, int depth) {
    char c = line[now].back();
    if(isdigit(c)) {
        now++;
        return c - '0';
    } else {
        function<int(int, int)> f;
        int ret;
        if(c == '+') {
            f = [](int a, int b) { return a + b; };
            ret = 0;
        } else if(c == '*') {
            f = [](int a, int b) { return a * b; };
            ret = 1;
        } else assert(0);
        now++;
        
        while(now < line.size() and calc_depth(line[now]) > depth) {
            ret = f(ret, calc(line, now, depth + 1));
        }
        return ret;
    }
}


bool solve() {
    int n; cin >> n;
    if(n == 0) return 0;
    vector<string> line(n); cin >> line;
    int i = 0;
    cout << calc(line, i, 0) << endl;
    return 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
