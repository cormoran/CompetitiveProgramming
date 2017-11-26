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


class Solver {
  public:
    int N;
    vector<vector<int>> E, rE;
    int mex(int start, int n, vector<int> &assignment) {
        set<int> conn;
        for(int to : E[n]) conn.insert(assignment[to]);
        int mex = start;
        for(int c : conn) if(mex == c) mex++;
        return mex;
    }
    bool check(const vector<int> &assignment) {
        rep(i, N) {
            set<int> connected;
            for(int to : E[i]) {
                if(assignment[to] < assignment[i]) connected.insert(assignment[to]);
                if(assignment[to] == assignment[i]) return false;
            }
            if(connected.size() < assignment[i]) return false;
        }
        return true;
    }
    int go(vector<int> &assignment, queue<int> &candidate) {
        int p = 0;
        while(candidate.size()) {
            p = candidate.front(); candidate.pop();
            if(assignment[p] >= 0) continue;
            if(mex(-1, p, assignment) > -1) continue;
            assignment[p] = mex(0, p, assignment);
            for(int to : rE[p]) candidate.push(to);
        }
        return p;
    }
    bool solve() {
        cin >> N;
        E.resize(N);
        rE.resize(N);
        rep(i, N) {
            int p; cin >> p; p--;
            E[p].push_back(i);
            rE[i].push_back(p);
        }
        vector<int> assignment(N, -1);
        queue<int> candidate;        
        rep(i, N) if(E[i].size() == 0) {
            candidate.push(i);
        }
        int last = go(assignment, candidate);
        if(*min_element(all(assignment)) == -1) {
            array<int, 2> mexes;
            mexes[0] = mex(0, last, assignment);
            mexes[1] = mex(mexes[0] + 1, last, assignment);            
            for(int c : mexes) {
                auto a = assignment;
                a[last] = c;
                queue<int> f;
                for(int to : rE[last]) f.push(to);
                go(a, f);
                if(check(a)) {
                    assignment = a;
                    break;
                }
            }
        }
        cout << (check(assignment) ? "POSSIBLE" : "IMPOSSIBLE") << endl;        
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
