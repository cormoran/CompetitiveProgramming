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
    int N, K; cin >> N >> K;
    string s; cin >> s;
    int num_a = count(all(s), 'a');
    int num_b = count(all(s), 'b');
    int ans = 0;
    auto f = [&](char bb){
        int head = -1, tail = 0;
        int in_b = 0;
        while(head < N) {
            while(head < N and in_b <= K) {
                head += 1;
                in_b += s[head] == bb;
            }
            int len = head - tail;
            ans = max(ans, len);
            while(in_b > K) {
                in_b -= s[tail] == bb;
                tail++;
            }
        }
    };
    f('a');
    f('b');
    cout << ans << endl;
    
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
