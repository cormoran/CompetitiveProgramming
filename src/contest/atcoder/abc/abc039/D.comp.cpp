#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
// vector
template<class T> ostream& operator << (ostream &os , const vector<T> &v) {
    for(const T &t : v) os << "\t" << t; return os << endl;
}
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}


const int dx[] = {0,  1, 1, 1, 0, -1, -1, -1};
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool solve() {
    int H, W; cin >> H >> W;
    vector<string> S(H); cin >> S;

    rep(y, H) rep(x, W) {
        if(S[y][x] != '#') continue;
        bool flg = true;
        rep(i, 8) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 or W <= nx or ny < 0 or H <= ny) continue;
            flg &= S[ny][nx] == '#' or S[ny][nx] == '!';
        }
        if(flg) S[y][x] = '!';
    }

    rep(y, H) rep(x, W) {
        if(S[y][x] != '!') continue;
        S[y][x] = '@';
        rep(i, 8) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 or W <= nx or ny < 0 or H <= ny) continue;
            if(S[ny][nx] != '!' && S[ny][nx] != '@') S[ny][nx] = '.';
        }
    }
    rep(y, H) rep(x, W) if(S[y][x] == '#') {
        cout << "impossible" << endl;
        exit(0);
    }
    cout << "possible" << endl;
    rep(y, H) {
        rep(x, W) cout << (S[y][x] == '@' ? "#" : ".");
        cout << endl;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
