#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
template<class T> istream&
operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;

    rep(t, T) {
        int N; cin >> N;
        vector<int> V(N); cin >> V;
        vector<int> V1, V2;
        rep(i, N) (i % 2 == 0 ? V1 : V2).push_back(V[i]);
        sort(all(V1));
        sort(all(V2));
        sort(all(V));
        int fail = -1;
        rep(i, N) {
            int v = i % 2 == 0 ? V1[i / 2] : V2[i / 2];
            if(V[i] != v) {
                fail = i;
                break;
            }
        }
        cout << "Case #" << t + 1 << ": ";
        if(fail < 0) cout << "OK" << endl;
        else cout << fail << endl;
    }
    
    return 0;
}
