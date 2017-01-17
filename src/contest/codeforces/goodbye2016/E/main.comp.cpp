#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <algorithm>

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
    bool solve() {
        int N, Q; cin >> N >> Q;
        string S; cin >> S;

        vector<int> acc_of_6(N + 1), acc_of_7(N + 1);
        vector<int> first_end_of_201(N);
        int pos = 0;

        int top_pos2 = -1, tail_pos2 = -1;
        
        rep(i, N) {
            acc_of_6[i + 1] = acc_of_6[i] + (S[i] == '6');
            acc_of_7[i + 1] = acc_of_7[i] + (S[i] == '7');

            if(S[i] == '2') {
                top_pos2 = i;
            }
            else if(S[i] == '0') {
                if(top_pos2 >= 0) tail_pos2 = top_pos2;
            }
            else if(S[i] == '1') {
                if(tail_pos2 >= 0) {
                    while(pos <= tail_pos2) {
                        first_end_of_201[pos++] = i;
                    }
                }
            }
        }
        while(pos < N) {
            first_end_of_201[pos++] = INF;
        }
        
        debug(first_end_of_201);
        rep(q, Q) {
            int a, b; cin >> a >> b;
            a--; b--;
            bool include_201 = first_end_of_201[a] <= b;
            if(include_201) {
                int include_7 = acc_of_7[b + 1] - acc_of_7[first_end_of_201[a]];
                if(include_7) {
                    int num_of_6 = acc_of_6[b + 1] - acc_of_6[first_end_of_201[a]];
                    cout << num_of_6 << endl;
                    continue;
                }                
            }
            cout << -1 << endl;
        }
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
