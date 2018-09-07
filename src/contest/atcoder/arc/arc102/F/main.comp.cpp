#include<bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)

template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

class Solver {
  public:
    bool solve() {
        auto fail = [] () { cout << "No" << endl; exit(0); };

        int N; cin >> N;
        vector<int> P(N); cin >> P;
        rep(i, N) P[i]--;

        {
            int i = 0;
            for(; i < N; i++) {
                if(P[i] != i) {
                    int start = i;
                    if(i + 1 >= N or P[i + 1] != i + 1) fail();
                    vector<int> left, right;
                    while(i < N) {
                        (P[i] < i ? left : right).push_back(P[i]);
                        if(i + 1 >= N or P[i + 1] != i + 1) break;
                        i += 2;
                    }
                    bool ok = true;
                    rep(j, left.size() - 1) ok &= left[j] < left[j + 1];
                    rep(j, right.size() - 1) ok &= right[j] < right[j + 1];
                    if(not ok) fail();
                    int end = min(N, i + 1);
                    if(*min_element(begin(P) + start, begin(P) + end) < start) fail();
                    if(*max_element(begin(P) + start, begin(P) + end) >= end) fail();
                }
            }
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
