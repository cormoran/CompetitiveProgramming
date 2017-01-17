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

const ll INFL = 1LL << 60;


class Solver {
  public:    

    void fail() {
        cout << "No" << endl;
        exit(0);
    }
    // I'm at A[now]. I can go to { B[e.first] | e in AE[now] }
    // => (min A[i], min B[j])
    tuple<ll, ll> visit(int now, ll val, vector<ll> &A, vector<ll> &B, vector<vector<pii>> &AE, vector<vector<pii>> &BE) {
        if(A[now] == -INFL) A[now] = val;
        else if(A[now] != val) fail();
        else return make_tuple(A[now], INFL);
        ll min_a = A[now], min_b = INFL;
        for(pii &e : AE[now]) {
            ll rb, ra;
            tie(rb, ra) = visit(e.first, e.second - A[now], B, A, BE, AE);
            set_min(min_a, ra);
            set_min(min_b, rb);
        }
        cerr << now << " " << min_a << " " << min_b << endl;
        return make_tuple(min_a, min_b);
    }
    
    bool solve() {
        int R, C; cin >> R >> C;
        int N; cin >> N;
        vector<vector<pii>> Ey(R), Ex(C);
        rep(i, N) {
            int y, x, a; cin >> y >> x >> a;
            y--; x--;
            Ey[y].push_back(make_pair(x, a));
            Ex[x].push_back(make_pair(y, a));
        }
        vector<ll> x(C, -INFL), y(R, -INFL);

        rep(i, C) {
            if(x[i] != -INFL) continue;
            ll ra, rb;
            tie(ra, rb) = visit(i, 0, x, y, Ex, Ey);
            if(ra + rb < 0) fail();            
        }
        rep(i, R) {
            if(y[i] != -INFL) continue;
            ll ra, rb;
            tie(ra, rb) = visit(i, 0, y, x, Ey, Ex);
            if(ra + rb < 0) fail();            
        }       
        cout << "Yes" << endl;
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Solver s;
    s.solve();
    return 0;
}
