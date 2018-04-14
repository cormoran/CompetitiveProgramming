#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream&
operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream&
operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream&
operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> A(3); cin >> A;
    sort(all(A));
    int cnt = 0;
    int c =  (A[2] - A[0]) / 2;
    cnt += c;
    A[0] += c * 2;
    c = (A[2] - A[1]) / 2;
    cnt += c;
    A[1] += c * 2;
    sort(all(A));
    if(A[0] == A[1] and A[1] == A[2]) ;
    else if(A[0] == A[1]) cnt++;
    else cnt += 2;
    cout << cnt << endl;
    
    return 0;
}