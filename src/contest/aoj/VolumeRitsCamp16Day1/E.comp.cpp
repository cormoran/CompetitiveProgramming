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

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()
const int INF = 1 << 30;
template<typename T>
ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : ""); return os;
}

template<typename T>
istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

bool is_good_number(ll n){
    while(n){
        if(n % 10 != 2 and n %10 != 8) return false;
        n /= 10;
    }
    return true;
}

pair<int,ll> div2(ll n){
    int cnt = 0;
    while(n % 2 == 0) n /= 2, cnt++;
    return make_pair(cnt, n);
}

vector<pair<int,ll>> calc_good_number(ll upper){
    vector<pair<int,ll>> res;
    set<ll> memo;
    queue<ll> que;
    que.push(2);
    que.push(8);
    while(que.size()){
        ll n = que.front(); que.pop();
        auto p = div2(n);
        if(not memo.count(p.second)){
            res.push_back(div2(n));
            memo.insert(p.second);
        }
        
        if(n < upper){
            que.push(n * 10 + 2);
            que.push(n * 10 + 8);
        }
    }
    return res;
}

map<pair<int,ll>, int> dp;
int dfs(const vector<pair<int,ll>> &good_number, int now, int left2, ll left){
    if(left == 1) return left2;
    if(dp.count(make_pair(left2, left))) return dp[make_pair(left2, left)];
    int ans = -INF;
    while(now < (int)good_number.size()){
        if(left % good_number[now].second == 0 and left2 >= good_number[now].first){
            ans = max(ans, dfs(good_number, now, left2 - good_number[now].first, left / good_number[now].second));
        }
        now++;
    }
    return dp[make_pair(left2, left)] = ans + 1;
}


bool solve(){
    ll n; cin >> n;
    if(n == 1){
        cout << -1 << endl;
        return 0;
    }
    vector<pair<int,ll>> good_number = calc_good_number(sqrt(n) + 1);
    //rep(i, good_number.size()) cerr << good_number[i].second << endl;
    bool flg = false;
    if(is_good_number(n)) flg = true;
    int left2 = 0;
    while(n % 2 == 0) n /= 2, left2++;
    int res = dfs(good_number, 0, left2, n);
    if(flg) res = max(1, res);
    cout << (res < 0 ? -1 : res) << endl;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
