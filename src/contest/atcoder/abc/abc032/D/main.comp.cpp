//  atcoder - abc032 - D  / 2016-03-30
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<functional>
#include<cassert>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,k,j) for(int__ i=(k);i<(int__)(j);i++)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

template<typename T>istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}


ll knapsack_n_w(int N, int W,vector<int> v, vector<int> w){
    cerr << __func__ << endl;
    int max_w = min(W, accumulate(all(w), 0));
    vector<vector<ll>> dp(N+1, vector<ll>(max_w+1));
    rep(i, N){
        rep(j, dp[i].size()){
            dp[i+1][j] = dp[i][j];
            if(j - w[i] < 0) continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j-w[i]] + v[i]);
        }
    }
    return *max_element(all(dp[N]));
}

ll knapsack_n_v(int N, int W,vector<int> v, vector<int> w){
    cerr << __func__ << endl;
    const ll INF = 1LL << 55;
    int max_v = accumulate(all(v), 0);
    vector<vector<ll>> dp(N+1, vector<ll>(max_v+1, INF));
    dp[0][0] = 0;
    rep(i, N){
        rep(j, dp[i].size()){
            dp[i+1][j] = dp[i][j];
            if(j - v[i] < 0) continue;
            dp[i+1][j] = min(dp[i+1][j], min(INF, dp[i][j-v[i]] + w[i]));
        }
    }
    for(int i = (int)dp[N].size() -1; i >= 0; i--){
        if(dp[N][i] <= W) return i;
    }
    return 0;
}

ll knapsack_n(int N, int W,vector<int> v, vector<int> w){
    cerr << __func__ << endl;
    auto calc = [&](vector<tuple<ll,ll>> &box, int s, int e) {
        box.reserve(pow(2, e - s + 5));
        box.push_back(make_tuple(0, 0));
        repeat(i, s, e){
            int n = box.size();
            rep(j, n){
                ll nw = get<0>(box[j]) + w[i];
                ll nv = get<1>(box[j]) + v[i];
                //if(nw > W) continue;
                box.push_back(make_tuple(nw, nv));
            }
        }
    };
    vector<tuple<ll, ll>> box1, box2;
    calc(box1, 0, N / 2);
    calc(box2, N / 2, N);

    int box2_active_size = 0;
    {
        // 無駄要素（重くて価値のないやつ）を消す
        sort(all(box2));
        ll box2_max = 0;
        rep(i, box2.size()){
            if(get<1>(box2[i]) >= box2_max){
                box2_max = get<1>(box2[i]);
                box2[box2_active_size++] = box2[i];
            }
        }
        // ここでbox2はw, v 両方について単調増加
    }
    
    ll res = 0;
    rep(i, box1.size()){
        ll max_w = W - get<0>(box1[i]);
        if(max_w < 0) continue;
        auto l = box2.begin();
        auto r = box2.begin() + box2_active_size;
        int idx = lower_bound(l, r, make_tuple(max_w+1, -1)) - box2.begin() - 1;
        assert(idx >= 0);
        res = max(res, get<1>(box1[i]) + get<1>(box2[idx]));
    }
    return res;
}

bool solve(){
    int N, W; cin >> N >> W;
    vector<int> v(N), w(N);
    rep(i, N) cin >> v[i] >> w[i];
    
    if(*max_element(all(w)) <= 1000)
        cout << knapsack_n_w(N, W, v, w) << endl;
    else if(*max_element(all(v)) <= 1000)
        cout << knapsack_n_v(N, W, v, w) << endl;
    else
        cout << knapsack_n(N, W, v, w) << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
