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
template<class T> istream&
operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream&
operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream&
operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

bool solve(int t, const vector<int> &D) {
    vector<int> arr(24);
    arr[12] = 1;
    auto can_place = [&] (int p) {
        rep(i, t) {
            if(arr[(p + i) % 24] > 0) return false;
            if(arr[(p - i + 24) % 24] > 0) return false;
        }
        return true;
    };
    function<bool(int)> dfs = [&] (int i) {
        if(i >= D.size()) return true;
        for(int d : {(12 + D[i]) % 24, (12 - D[i] + 24) % 24}) {
            if(can_place(d)) {
                arr[d]++;
                bool ok = dfs(i + 1);
                arr[d]--;
                if(ok) return ok;
            }
        }
        return false;
    };
    return dfs(0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<int> D(N); cin >> D;
    for(int t = 12; t >= 1; t--) {
        if(solve(t, D)) {
            cout << t << endl;
            exit(0);
        }
    }
    cout << 0 << endl;
    return 0;
}
