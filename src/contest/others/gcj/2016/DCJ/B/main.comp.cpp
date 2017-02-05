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

#include <message.h>
#include "rps.h"
//#include "rps-3.h"

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

#define ROOT 9

bool win(char a, char b) {
    if(a == b) return 1;
    if(a == 'S' && b == 'R') return 0;
    if(a == 'S' && b == 'P') return 1;
    if(a == 'R' && b == 'P') return 0;
    return not win(b, a);
}

void solve(vector<pair<ll , char>> &A, bool master = false){
    int size = A.size();
    while(size > 1) {
        for(int i = 0; i + 1 < size; i += 2) {
            A[i / 2] = win(A[i].second, A[i+1].second) ? A[i] : A[i+1];
            //cerr << A[i / 2].first << " " << A[i / 2].second << endl;
        }
        if(size % 2 != 0) break;
        size /= 2;
    }
    if(master) {
        cout << A[0].first << endl;
    } else {
        PutLL(ROOT, A[0].first);
        PutChar(ROOT, A[0].second);
        Send(ROOT);
    }
}

void slave() {
    ll nodes = NumberOfNodes();
    ll N = GetN();
    nodes = min<ll>(8, pow(2, N - 1));
    ll id = MyNodeId();
    if(id >= nodes) return;
    ll num = pow(2,N - (nodes == 8 ? 3 : (N - 1)));
    ll s = num * id;
    ll e = num * (id + 1);
    vector<pair<ll, char>> A(e - s);
    ll ids = s;
    rep(i, A.size()) {
        A[i].first = ids + i;
        A[i].second = GetFavoriteMove(ids + i);
    }
    solve(A);
}

void master() {
    ll N = GetN();
    ll nodes = NumberOfNodes();
    nodes = min<ll>(8, pow(2, N - 1));
    ll id = MyNodeId();
    vector<pair<ll, char>> A;
    rep(i, nodes) {
        Receive(i);
        ll id = GetLL(i);
        char c = GetChar(i);
        A.push_back(make_pair(id, c));
    }
    solve(A, true);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll id = MyNodeId();
    slave();
    if(id == ROOT) master();
    return 0;
}
