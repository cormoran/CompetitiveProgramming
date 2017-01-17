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
    int N; cin >> N;
    auto comp = [](string &a, string &b) {
        rep(i, min(a.size(), b.size())) {
            if(a[i] != b[i]) return a[i] > b[i];
        }
        return a.size() < b.size();
    };
    
    priority_queue<string, vector<string>, decltype(comp)> que(comp);

    rep(i, N) {
        string s; cin >> s;
        que.emplace(s);
    }
    
    string ans = "";
    while(!que.empty()) {
        string s = que.top(); que.pop();
        ans.push_back(s.front());
        if(s.size() > 1) {
            que.push(s.substr(1));
        }
    }
    cout << ans << endl;
    
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
