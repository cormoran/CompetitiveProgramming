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

vector<pair<int, int>> D, A;

bool solve() {
    int N; cin >> N;

    rep(i, N){
        int a, b; cin >> a >> b;
        (a - b > 0 ? A : D).push_back(make_pair(a, b));        
    }
    ll d_max, a_max, d_res = 0;
    {
        auto f = [&](pii &a, pii &b) {
            return a.first != b.first ? a.first < b.first : a.second > b.second;
        };
        sort(all(D), f);
        d_max = 0;
        for(auto &p : D) {
            d_res += p.first;
            d_max = max(d_max, d_res);
            d_res -= p.second;
        }
    }
    {
        auto f = [&](pii &a, pii &b) {
            return a.first != b.first ? a.first > b.first : a.second > b.second;
        };
        sort(all(A), f);
        a_max = 0;
        ll a_res = 0;
        for(auto &p : A) {
            ll pb_max = a_res + p.first;
            ll insert_max = a_max + p.first - p.second;
            if(a_max < p.first or pb_max <= insert_max) {
                a_res += p.first;
                a_max = max(a_max, a_res);
                a_res -= p.second;
            } else {
                a_res += p.first - p.second;
                a_max += p.first - p.second;
            }
        }   
    }
    cout << max(d_max, a_max + d_res) << endl;
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
