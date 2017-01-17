#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<tuple>
#include<numeric>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl
// vector
template<class T> ostream& operator << (ostream &os , const vector<T> &v) {
    for(const T &t : v) os << "\t" << t; return os << endl;
}
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) {
    return os << "<" << v.first << " " << v.second << ">";
}



bool solve() {
    string s; cin >> s;
    string ans = "";
    int exp = -1;
    rep(i, s.size()) if(s[i] == 'e') {
        exp =  stoi(s.substr(i + 1));
        ans = s.substr(0, i);
    }
    assert(exp >= 0);
    int i = 0;
    while(exp > 0) {
        if(ans[i] == '.') {
            if(ans.size() == i + 1) ans.push_back('0');
            swap(ans[i], ans[i+1]);
            exp--;
        }
        i++;
    }
    while(ans.back() == '0') ans.pop_back();
    if(ans.back() == '.') ans.pop_back();
    cout << ans << endl;
    
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
