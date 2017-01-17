#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cmath>
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

const int INF = 1 << 30;

int check(vector<int> &v) {
    return (v[0] == v[1]) + (v[1] == v[2]) + (v[0] == v[2]);
}

int d;

int dec(int in, int times) {
    return max(0, in - times * d);
}

int maxi(vector<int> H) {
    int ans = 0;
    for(int i : {0, 2}) {
        int dd = ceil(double(H[i] - H[1]) / d);
        if(dd < 0) continue;
        H[i] = dec(H[i], dd);
        ans += dd;
        if(H[i] == H[1]) {
            H[i] = dec(H[i], 1);
            ans += 1;
        }
        if(H[i] == H[1]) return INF;
    }
    if(H[0] == H[2]) {
        H[0] = dec(H[0], 1);
        ans += 1;
    }
    if(H[0] == H[2]) return INF;
    return ans;
}

int mini(vector<int> H) {
    int ans = 0;
    if(H[0] == H[2]) {
        H[0] = dec(H[0], 1);
        ans += 1;
    }
    if(H[0] == H[2]) return INF;

    // H[0] != H[1] is true
    
    for(int i : {0, 2}) {
        if(H[i] <= H[1]) {
            int dd = ceil((double)(H[1] - H[i]) / d);
            H[1] = dec(H[1], dd);
            ans += dd;
            if(H[1] == H[i]) {
                H[1] = dec(H[1], 1);
                ans += 1;
            }
            if(H[1] == H[i]) return INF;            
        }
    }
    return ans;
}

bool solve() {
    cin >> d;
    vector<int> H(3); cin >> H;
    if(d == 0) {
        cout <<
                (!check(H) and
                 (*min_element(all(H)) == H[1]
                  or *max_element(all(H)) == H[1]) ? 0 : -1)
             << endl;
        
    } else {
        int ans = min(mini(H), maxi(H));
        cout << (ans == INF ? -1 : ans) << endl;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
