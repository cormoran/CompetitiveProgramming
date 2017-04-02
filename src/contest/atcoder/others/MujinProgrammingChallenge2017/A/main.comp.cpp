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
    
    bool check(vector<int> &line, const vector<int> &perm) {
        int N = line.size();
        deque<int> arrange;
        map<int, int> pos;
        rep(i, N) {
            arrange.push_back(i);
            pos[i] = line[i];
        }

        function<bool(int)> move_front = [&](int robot) {
            int idx = find(all(arrange), robot) - begin(arrange);   
            int mypos = pos[arrange[idx]];

            if(idx == 0) {
                if(mypos == 1) return false;
                pos[robot]--;
                return true;
            }
            int front = pos[arrange[idx - 1]];
            if(idx == 1) {
                bool touch = mypos - front == 1;
                if(touch and front == 1) return false;
                pos[robot] = touch ? front - 1 : mypos - 1;
                if(touch) swap(arrange[idx], arrange[idx - 1]);
                return true;
            }
            int frontfront = pos[arrange[idx - 2]];
            if(frontfront + 1 == front and front + 1 == mypos) {
                if(move_front(arrange[idx - 2]) || move_front(arrange[idx - 1])) {
                    return move_front(robot);
                }
                return false;
            }
            else if(front + 1 == mypos) {
                bool touch = mypos - front == 1;
                assert(touch);
                pos[robot] = !touch ? mypos - 1 : front - 1;
                if(touch) swap(arrange[idx], arrange[idx - 1]);
                return true;
            }
            else {
                pos[robot]--;
            }
        };

        for(int robot : perm) {            
            while(true) {
                int idx = find(all(arrange), robot) - begin(arrange);
                if(idx == 0) break;
                if(idx == 1) {
                    swap(arrange[0], arrange[1]);
                    break;
                }
                int mypos = pos[arrange[idx]];
                int front = pos[arrange[idx - 1]];                
                if(mypos == front + 1) {
                    if(not move_front(robot)) return false;
                } else {
                    pos[robot] = front + 1;
                }
            }
            arrange.pop_front();
        }
        return true;
    }
    
    bool solve() {
        int N; cin >> N;
        vector<int> line(N); cin >> line;
        assert(N <= 8);
        
        vector<int> perm;
        rep(i, N) perm.push_back(i);
        int ans = 0;
        do {
            bool ok = check(line, perm);
            ans += ok;
        } while(next_permutation(all(perm)));
        cout << ans << endl;
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
