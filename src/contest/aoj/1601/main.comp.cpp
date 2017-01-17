#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}

bool solve() {
    int n; cin >> n;
    if(n == 0) return 0;
    vector<string> s(n); cin >> s;

    rep(i, n) {
        vector<int> haiku = {5, 7, 5, 7, 7};
        reverse(all(haiku));
        repeat(j, i, n) {
            haiku.back() -= s[j].size();
            if(haiku.back() < 0) break;
            else if(haiku.back() == 0) {
                haiku.pop_back();
                if(haiku.size() == 0) {
                    cout << i + 1 << endl;
                    return 1;
                }
            }
        }
    }
    assert(0);
    return 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
