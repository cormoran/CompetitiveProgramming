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

const string S = "WBWBWWBWBWBW";
const vector<string> ANS = {
    "Do", "Do", "Re", "Re", "Mi", "Fa", "Fa", "So", "So", "La", "La", "Si"
};
bool solve() {
    string s; cin >> s;
    string ss = S + S + S;

    for(int i = 0; ; i++) {
       if(ss.substr(i, s.size()) == s) {
          cout << ANS[i % ANS.size()] << endl;
    break;
       }
    }
    
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
