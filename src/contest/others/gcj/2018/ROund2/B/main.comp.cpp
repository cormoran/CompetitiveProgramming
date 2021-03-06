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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    rep(t, T) {
        cout << "Case #" << t + 1 << ": ";
        int R, B; cin >> R >> B;
        int sum = 0;
        for(int c = 1; R + B >= c; c++) {
            queue<pii> que;
            if(R > B) swap(R, B);
            rep(r, c + 1) {
                int b = c - r;
                if(r <= R and b <= B) {
                    sum++;
                    R -= r;
                    B -= b;
                    // cerr << r << " : " << b << endl;
                    que.push(pii(r, b));
                } else if(que.size()) {
                    pii a = que.front();
                    if(r <= a.first + R and b <= a.second + B) {
                        que.pop();
                        R += a.first;
                        B += a.second;
                        R -= r;
                        B -= b;
                        //cerr << r << " : " << b << endl;
                        que.push(pii(r, b));
                    }
                }
            }
        }
        cout << sum << endl;
    }

    return 0;
}
