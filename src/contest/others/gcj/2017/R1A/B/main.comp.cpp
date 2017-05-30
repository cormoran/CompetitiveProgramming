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

struct A {
    int index;
    int g;
    bool operator < (const A &a) const {
        return g == a.g ? index < a.index : g < a.g;
    }
};
struct B {
    int index;
    int g;
    bool operator < (const B &a) const {
        return g == a.g ? index < a.index : g > a.g;
    }
};

class Solver {
  public:
    bool solve(int T) {
        int N, P; cin >> N >> P;

        vector<int> NEED(N); cin >> NEED;
        vector<vector<int>> Q(N, vector<int>(P)); cin >> Q;

        map<int, vector<set<A>>> usable1;
        map<int, vector<set<B>>> usable2;
        
        rep(i, N) {
            rep(p, P) {
                int num = (double) Q[i][p] / NEED[i] - 1;
                while(1) {
                    if(num > 0) {                        
                        // double per = (double)Q[i][p] / NEED[i] / num * 100;
                        if((ll)Q[i][p] * 100 < (ll)90 * NEED[i] * num) break;
                        else if((ll)Q[i][p] * 100 <= (ll)110 * NEED[i] * num) {
                            if(not usable1.count(num)) usable1[num].resize(N);
                            usable1[num][i].insert((A){p, Q[i][p]});
                            if(not usable2.count(num)) usable2[num].resize(N);
                            usable2[num][i].insert((B){p, Q[i][p]});
                        }
                    }
                    num++;
                }
            }
        }
        /*
        for(auto &pr : usable) {
            cerr << "num : " << pr.first << endl;
            rep(i, N) {
                cerr << "\t" << i << " : ";
                for(A a : pr.second[i]) {
                    cerr << a.index << " ";
                }
                cerr << endl;
            }

        }
        */

        int ans = 0;
        {
            vector<vector<int>> used(N, vector<int>(P));
        for(auto &pr : usable1) {
            int num = pr.first;
            vector<set<A>> &vs = pr.second;
            int cnt = INF;
            rep(i, N) {
                int c = 0;
                vector<A> erase;
                for(auto s : vs[i]) {
                    if(used[i][s.index]) erase.push_back(s);
                    else c++;
                }
                set_min(cnt, c);
                for(A a: erase) vs[i].erase(a);
            }
            rep(i, N) {
                auto itr = vs[i].begin();
                rep(c, cnt) {
                    used[i][itr->index] = true;
                    itr++;
                }
            }
            ans += cnt;
        }
        }
        int ans2 = 0;
        {
            vector<vector<int>> used(N, vector<int>(P));
        for(auto ptr = rbegin(usable2); ptr != rend(usable2); ptr++) {
            int num = ptr->first;
            vector<set<B>> &vs = ptr->second;
            int cnt = INF;
            rep(i, N) {
                int c = 0;
                vector<B> erase;
                for(auto s : vs[i]) {
                    if(used[i][s.index]) erase.push_back(s);
                    else c++;
                }
                set_min(cnt, c);
                for(B a: erase) vs[i].erase(a);
            }
            rep(i, N) {
                auto itr = vs[i].begin();
                rep(c, cnt) {
                    used[i][itr->index] = true;
                    itr++;
                }
            }
            ans2 += cnt;
        }
        }
        set_max(ans, ans2);
        cout << "Case #" << T <<  ": " << ans << endl;
        
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    int t = 0;
    while(t++ < T) {
        Solver s;
        s.solve(t);
    }

    return 0;
}
