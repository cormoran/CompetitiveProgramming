#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()

class ModInt{
  public:
    static const ll MOD = 1000000007LL;
    ll x;
    ModInt():x(0){};
    ModInt(ll x){
        while(x < 0) x += MOD;
        x %= MOD;
        this->x = x;
    }
    ModInt& operator += (const ModInt &l){ x += l.x; if( x >= MOD) x -= MOD; return *this; }
    ModInt& operator -= (const ModInt &l){ x -= l.x; if( x < 0 ) x += MOD; return *this; }
    ModInt& operator *= (const ModInt &l){ x = (x * l.x) % MOD; return *this; }
    ModInt operator +(const ModInt &l) const { return ModInt( x + l.x); }
    ModInt operator -(const ModInt &l) const { return ModInt( x - l.x); }
    ModInt operator *(const ModInt &l) const { return ModInt( x * l.x); }
};

// @warning rの部分はmodとってはいけない
ModInt pow(const ModInt &n, ll r){
    if(r == 0) return ModInt(1);
    ModInt ret = pow(n, r / 2);
    ret *= ret;
    if(r % 2 != 0) ret = ret * n;
    return ret;
}

// @waring nはMODと互いに素
ModInt inverse(const ModInt &n){
    return pow(n, ModInt::MOD - 2);
}

ModInt factorial(const ModInt &n){
    ll ret =1;
    for(ll i=n.x; i>1; i--){
        ret*=i;
    }
    return ModInt(ret);
}

struct UnionFind{
    int n;
    vector<int> p;
    UnionFind(int nn) {
        n = nn;
        p.resize(n);
        rep(i, n) p[i] = i;
    }
    int root(int x) {
        return p[x] == x ? x : (p[x] = root(p[x]));
    }
    void unite(int x,int y) {
        x = root(x); y = root(y);
        if(x != y) p[y] = x;
    }
    bool query(int x,int y){
        return root(x) == root(y);
    }
    map<int, vector<int>> get_group() {
        map<int, vector<int>> res;
        rep(i, p.size()) {
            res[root(i)].push_back(i);
        }
        return res;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, X, Y; cin >> N >> X >> Y;
    vector<int> C(N), W(N);
    rep(i, N) cin >> C[i] >> W[i];

    if(N == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    UnionFind uf(N);
    
    map<int, vector<int>> color_group;
    rep(i, N) color_group[C[i]].push_back(i);

    if(color_group.size() == 1) {
        cout << 1 << endl;
        return 0;
    }
    for(auto &p : color_group) {
        vector<int> &group = p.second;
        int min_i = *min_element(all(group), [&] (int i, int j) { return W[i] < W[j]; });
        for(int i : group) {
            if(W[min_i] + W[i] <= X) uf.unite(min_i, i);
        }
    }
    vector<int> sorted_indices(N);
    rep(i, N) sorted_indices[i] = i;
    sort(all(sorted_indices), [&] (int i, int j) { return W[i] < W[j]; });

    int min_1st = sorted_indices[0];
    int min_2nd = -1;
    for(int i = 1; i < N and min_2nd < 0; i++) {
        if(C[min_1st] != C[sorted_indices[i]]) min_2nd = sorted_indices[i];
    }
    assert(min_2nd >= 0);

    rep(i, N) {
        int min_i = C[i] != C[min_1st] ? min_1st : min_2nd;
        if(W[min_i] + W[i] <= Y) uf.unite(min_i, i);
    }

    if(not uf.query(min_1st, min_2nd)) {
        cout << 1 << endl;
        return 0;
    }

    ModInt ans = 1;
    for(auto &p : uf.get_group()) {
        if(not uf.query(min_1st, p.second[0])) continue;
        map<int, int> num_colors;
        for(int i : p.second) num_colors[C[i]]++;
        ans *= factorial(p.second.size());
        for(auto nc : num_colors) ans *= inverse(factorial(nc.second));
    }
    cout << ans.x << endl;
    return 0;
}
