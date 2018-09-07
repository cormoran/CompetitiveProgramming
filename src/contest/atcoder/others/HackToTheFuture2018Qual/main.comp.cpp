#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
using Mat = vector<vector<int>>;
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

random_device rnd;
mt19937 mt(rnd());

struct Parameter {
    double accept_rate = 0.1;
    double dist_mean = 0.0;
    double dist_s = 1.0;
};

using LogT = tuple<int, int, int>;

struct Solver {
    Mat A_;
    int M_;
    Parameter param_;
    lognormal_distribution<> lognormal;
    uniform_real_distribution<> uniform;

    Solver(const Mat &aA, int M) {
        A_ = aA;
        M_ = M;
    }
    
    int find_max_h(const vector<vector<int>> &A, int y, int x) {    
        int N = A.size();
        int max_h = INF;
        rep(dy, max(y + 1, N - y)) rep(dx, max(x + 1, N - x)) {
            for(int sx : {1, -1}) for(int sy : {1, -1}) {
                    int ny = y + dy * sy, nx = x + dx * sx;
                    if(not(0 <= ny and ny < N)) continue;
                    if(not(0 <= nx and nx < N)) continue;
                    set_min(max_h, A[ny][nx] + dy + dx);
                }
        }
        return max_h;
    }
    
    void sub(Mat &A, int y, int x, int h) {
        int N = A.size();
        repeat(dy, max(-N, -h) + 1, min(h, N)) repeat(dx, max(-N, -h) + 1, min(h, N)) {
            if(abs(dy) + abs(dx) > h) continue;
            int ny = y + dy, nx = x + dx;
            if(not(0 <= ny and ny < N)) continue;
            if(not(0 <= nx and nx < N)) continue;
            A[ny][nx] -= (h - abs(dy) - abs(dx));            
        }
    }
    tuple<Mat, vector<LogT>> solve(Parameter param) {
        param_ = param;
        lognormal = lognormal_distribution<>(param_.dist_mean, param_.dist_s);
        uniform = uniform_real_distribution<>(0, 1);
        
        Mat A = A_;
        int M = M_;
        int N = A.size();
        vector<tuple<int, int, int>> log;
        int cnt = 0;
        while(M > 0 and cnt++ < 20) {
            cerr << "a ";
            priority_queue<tuple<int, int, int>> que;
            rep(y, N) rep(x, N) que.emplace(A[y][x], y, x);
            int add = 0;
            while(M > 0 and que.size()) {
                int v, y, x;
                tie(v, y, x) = que.top(); que.pop();
                if(uniform(mt) > param_.accept_rate) continue;
                int d = find_max_h(A, y, x);
                if(d <= 0) continue;
                set_min(d, N);
                //debug(d);
                sub(A, y, x, d);
                // add(B, y, x, d);
                log.emplace_back(x, y, d);
                add++;
                // debug(A);
            }
            if(add == 0) break;
        }
        return make_tuple(A, log);
    }
};


int calc_point(const Mat &A, const Mat &B, int num) {
    ll point = 200000000;
    ll diff = 0;
    rep(i, A.size()) rep(j, A[i].size()) diff += abs(A[i][j] - B[i][j]);
    point -= diff;
    if(diff == 0) point += 1000 - num;
    return point;
}
    
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N = 100;
    vector<vector<int>> A(N, vector<int>(N)); cin >> A;    

    Solver solver(A, 1000);
    Parameter param;
    int best_point = 0;
    vector<LogT> log;
    for(double rate : {1.0, 0.9, 0.8, 0.7}) {
        param.accept_rate = rate;
        rep(j, 1) {
            Mat tmp_a;
            vector<LogT> tmp_log;
            tie(tmp_a, tmp_log) = solver.solve(param);
            if(set_max(best_point, calc_point(A, tmp_a, tmp_log.size()))) {
                cerr << "UPDATE: " << best_point << endl;
                log = tmp_log;
            }
        }
    }

    cout << log.size() << endl;
    for(auto l : log) {
        cout << get<0>(l) << " " << get<1>(l) << " " << get<2>(l) << endl;
    }   
    
    return 0;
}
