#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
typedef long long ll;
const ll INF = 1LL << 60;

int n, m;
vector<int> a, b;

ll calc(vector<int> &v, int i, int s) {
    ll sum = 0;
    for(int j = i - s; j < i; j++) {
        if(v[j] >= 0) sum += v[j];
    }
    return sum;
}

int depth = 0;

ll memo[2][51][51][51][51][3];

ll dfs(bool is_a, int ai, int bi, int as ,int bs, int pass_cnt) {
    if(memo[is_a][ai][bi][as][bs][pass_cnt] != INF) return memo[is_a][ai][bi][as][bs][pass_cnt];
    
    depth++;
    ll ret;
    if(is_a) {        
        ll pass = -INF;
        if(pass_cnt < 2) pass = dfs(!is_a, ai, bi, 0, 0, pass_cnt + 1) + calc(a, ai, as) - calc(b, bi, bs);
        else pass = 0;
        ll use = -INF;
        if(ai < a.size()) use = dfs(!is_a, ai + 1, bi, as + 1, a[ai] == -1 ? 0 : bs, 0);
        ret = max(pass, use);
        // rep(i, depth) cerr << " ";
        // fprintf(stderr ,"is_a %d  i %d %d s %d %d pass_cnt %d pass %lld use %lld -> %lld\n", is_a, ai ,bi, as, bs, pass_cnt, pass , use, ret);        
    } else {
        ll pass = INF;
        if(pass_cnt < 2) pass = dfs(!is_a, ai, bi, 0, 0, pass_cnt + 1) + calc(a, ai, as) - calc(b, bi, bs);
        else pass = 0;
        ll use = INF;
        if(bi < b.size()) use = dfs(!is_a, ai, bi + 1, b[bi] == -1 ? 0 : as, bs + 1, 0);
        ret = min(pass, use);
        // rep(i, depth) cerr << " ";
        // fprintf(stderr , "is_a %d  i %d %d s %d %d pass_cnt %d pass %lld use %lld -> %lld\n", is_a, ai ,bi, as, bs, pass_cnt, pass , use, ret);
    }
    depth--;
    return memo[is_a][ai][bi][as][bs][pass_cnt] = ret;
}

int main(){

    rep(i, 51) rep(j, 51) rep(k, 51) rep(l, 51) rep(m, 3) {
        memo[0][i][j][k][l][m] = INF;
        memo[1][i][j][k][l][m] = INF;
    }
    
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    ll ans = dfs(true, 0, 0, 0, 0, 1);
    assert( llabs(ans) < 1e8);
    cout << ans << endl;    
    
    return 0;
}
