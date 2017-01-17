//  atcoder - arc024 - A  / 2016-03-15
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

bool solve(){
    int ln, rn; cin >> ln >> rn;
    vector<int> L(ln), R(rn); cin >> L >> R;
    vector<int> l(41), r(41);
    rep(i, ln) l[L[i]]++;
    rep(i, rn) r[R[i]]++;
    int ans = 0;
    rep(i, 41){
        ans += min(l[i], r[i]);
    }
    cout << ans << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
