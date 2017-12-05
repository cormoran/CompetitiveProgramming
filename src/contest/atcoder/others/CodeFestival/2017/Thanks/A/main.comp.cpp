#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
template<class T> istream&
operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

int main() {
    vector<int> T(8); cin >> T;
    cout << *max_element(all(T)) << endl;
    return 0;
}
