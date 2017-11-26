//順列組み合わせ
vector< vector<ll> > combination_array(int n){
    vector<vector<ll>> nCk(n + 1, vector<ll>(n + 1));
    nCk[0][0] = 1;
    repeat(i, 1, n + 1) {
        nCk[i][0] = nCk[i-1][0];
        repeat(j, 1, i + 1) {
            nCk[i][j] = nCk[i-1][j] + nCk[i-1][j-1];
        }
    }
    return nCk;
}
/*
    Modの逆元を利用することで高速に求める
    条件 : ModとnCkの分母の数が互いに素
    Info : 大量に欲しい場合はfactとinverse_fact を最初に計算して持っておくとO(1)でいける
*/
//Combination (Mod) based on ModInt
//O(N + log Mod)
ll nCk(ll n,ll k){
    vector<ModInt<ll>> fact(n+1);
    fact[0]=1;
    for(int i=1;i<=n;i++){
        fact[i]=fact[i-1]*i;
    }
    return (fact[n] * ModInt<ll>::inverse(fact[k]*fact[n-k])).x;
}
//Homogeneous product : 重複組み合わせ nこの中から重複を許してk個とる場合の数
ll NHK(ll n,ll k){
    return nCk(n+k-1,n-1);
}