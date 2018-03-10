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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<pii> X(N);
    rep(i, N) {
        cin >> X[i].first;
        X[i].second = i + 1;
    }
    sort(all(X));
    
    vector<int> arr(N * N, -1);
    rep(i, N) arr[X[i].first - 1] = X[i].second;    
    
    int itr = 0;
    auto insert = [&] (int x, int dir, int pos) {
        while(arr[itr] >= 0 and 0 <= itr and itr < arr.size()) itr += dir;
        if(dir > 0 and itr > pos) return false;
        if(dir < 0 and itr < pos) return false;
        if(0 <= itr and itr < arr.size()) {            
            arr[itr] = x;
            return true;
        }
        return false;
    };
    auto fail = [] () {
        cout << "No" << endl;
        exit(0);
    };

    for(auto p : X) {
        rep(tmp, p.second - 1) if(not insert(p.second, 1, p.first - 1)) fail();
    }

    reverse(all(X));
    itr = arr.size() - 1;
    
    for(auto p : X) {
        rep(tmp, N - p.second) if(not insert(p.second, -1, p.first - 1)) fail();
    }

    cout << "Yes" << endl;
    rep(i, arr.size()) cout << arr[i] << (i + 1 < arr.size() ? " " : "\n");

    return 0;
}
