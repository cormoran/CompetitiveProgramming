#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
int main() {
    int K, T; cin >> K >> T;
    vector<int> A(T); cin >> A;
    sort(all(A));
    reverse(all(A));

    list<int> l;
    rep(i, A[0]) l.push_back(0);
    auto pos = l.begin();
    repeat(i, 1, T) {
        rep(j, A[i]) {
            pos++;
            l.insert(pos, i);
            if(pos == l.end()) pos = l.begin();
        }
    }

    int ans = 0;
    int pre = -1;
    for(auto i : l) {
        ans += pre == i;
        pre = i;
    }    
    cout << ans << endl;
    return 0;
}
