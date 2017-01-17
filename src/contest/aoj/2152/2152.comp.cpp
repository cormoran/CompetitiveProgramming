#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<list>
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

struct Packet {
    int id, pos, len;
};

bool solve() {
    int N; cin >> N;
    if(N == 0) return false;
    list<Packet> memory;
    rep(i, N) {
        char c; cin >> c;
        if(c == 'W') {
            int len, id; cin >> id >> len;
            int pos = 0;
            for(auto itr = memory.begin(); itr != memory.end(); itr++) {
                if(itr->pos > pos) {
                    int blank = itr->pos - pos;
                    Packet p = {id, pos, min(blank, len)};
                    memory.insert(itr, p);
                    len -= p.len;
                    if(len == 0) break;
                }
                pos = itr->pos + itr->len;
            }
            if(len > 0) {
                Packet p = {id, pos, len};
                memory.push_back(p);
            }
        } else if(c == 'D') {
            int id; cin >> id;
            for(auto itr = memory.begin(); itr != memory.end();) {
                if(itr->id == id) itr = memory.erase(itr);
                else itr++;
            }
        } else if(c == 'R') {
            int num; cin >> num;
            for(auto itr = memory.begin(); itr != memory.end(); itr++) {
                if(itr->pos <= num and num < itr->pos + itr->len){
                    cout << itr->id << endl;
                    goto END_R;
                }
            }
            cout << -1 << endl;
      END_R:;
        }
    }
    cout << endl;
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
