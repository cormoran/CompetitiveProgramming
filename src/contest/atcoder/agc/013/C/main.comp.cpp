#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pli = pair<ll, int>;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define debug(x) cerr << #x << " : " << x << endl
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, L, T; cin >> N >> L >> T;
    vector<ll> X(N), W(N);
    rep(i, N) cin >> X[i] >> W[i];
    ll w = W[0];
    // 蟻0を時計回りに固定
    if(W[0] == 2) {
        rep(i, N) {
            W[i] = W[i] == 1 ? 2 : 1;
            X[i] = L - X[i];
        }
    }
    ll roll = T / L, left = T % L, sum = 0;
    // 衝突回数計算
    repeat(i, 1, N) {
        if(W[i] != W[0]) {
            sum += roll * 2;
            ll d = (X[i] - X[0] + L) % L;            
            if(left * 2 >= d) sum += 1;
            if(left * 2 - d >= L) sum += 1;
        }
        sum %= N;
    }
    // 蟻本方式に動いて移動先計算
    rep(i, N) {
        X[i] += (W[i] == 1 ? left : -left) + L;
        X[i] %= L;        
    }
    // 正しい座標に戻す
    if(w == 2) rep(i, N) X[i] = (L - X[i]) % L;

    ll i = (w == 1 ? sum : N - sum + N) % N; // i番目の蟻が，蟻本方式での0番目の蟻の移動先にいる

    ll x0 = X[0];
    sort(begin(X), end(X));
    
    ll ii = find(begin(X), end(X), x0) - begin(X);
    if(w == 1) while(ii < N - 1 and X[ii + 1] == X[ii]) ii++;    
    
    ll i2 = (ii - i + N) % N; // 0番目の蟻はi2番目の蟻の移動先にいる

    rep(j, N) {
        cout << X[(i2 + j) % N] << endl;
    }    

    return 0;
}
