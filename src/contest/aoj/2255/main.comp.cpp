#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
//#define debug(x) cerr << #x << " : " << x << endl
#define debug(...)

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << " ! " << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

struct Expr {
    vector<char> op;
    vector<string> expr;
};


class Solver {
  public:
    string S;
    int N;
    vector<int> apply(vector<int> &A, vector<int> &B, char op) {
        debug(A); debug(B); debug(op);
        vector<int> res;
        for(int a : A) for(int b : B) {
                if(op == '+') res.push_back(a + b);
                else if(op == '-') res.push_back(a - b);
                else if(op == '*') res.push_back(a * b);
                else if(op == '/') {
                    if(b != 0) res.push_back(a / b);
                }
                else assert(0);
            }
        sort(all(res));
        res.erase(unique(all(res)), res.end());
        return res;
    }
    vector<int> calc3(vector<vector<int>> nums, const vector<char> &ops, const vector<int> &perm) {
        map<int, int> ref;
        for(int i : perm) {
            int ii = i;
            int j = i + 1;
            while(ref.count(i)) i = ref[i];
            while(ref.count(j)) j = ref[j];
            nums[i] = apply(nums[i], nums[j], ops[ii]);
            ref[j] = i;
        }
        assert(ref.size() == nums.size() - 1);
        return nums[0];
    }
    vector<int> calc2(vector<vector<int>> &nums, vector<char> ops) {
        assert(nums.size() == ops.size() + 1);
        vector<int> perm; rep(i, ops.size()) perm.push_back(i);
        vector<int> res;
        do {
            debug(perm);
            auto tmp = calc3(nums, ops, perm);
            for(int i : tmp) res.push_back(i);
        } while(next_permutation(all(perm)));
        sort(all(res));
        res.erase(unique(all(res)), res.end());
        return res;
    }
    vector<int> calc(int &i) {
        debug(i); debug(S[i]);
        int s = i;
        if(isdigit(S[s])) {
            while(i < N and isdigit(S[i])) i++;
            return { stoi(S.substr(s, i - s)) };
        }
        assert(S[s] == '(');
        i++;
        vector<vector<int>> nums;
        vector<char> ops;
        bool started = false;
        while(S[i] != ')') {
            if(started) {
                ops.push_back(S[i++]);
            }
            nums.push_back(calc(i));
            started = true;
        }
        i++;
        debug(nums);
        debug(ops);
        auto res = calc2(nums, ops);
        // cerr << "@ " << s << " " << res;
        return res;
    }

    
    bool solve() {
        cin >> S;
        if(S == "#") return 0;
        S = "(" + S + ")";
        N = S.size();
        debug(S);
        int i = 0;
        auto res = calc(i);
        debug(res);
        cout << res.size() << endl;
        return 1;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(Solver().solve());
    return 0;
}
