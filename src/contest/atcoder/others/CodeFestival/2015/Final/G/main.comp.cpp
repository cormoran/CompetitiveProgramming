//  CodeFestival-2015-Final-G  / 2015-11-17
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}
template<typename T>istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R> void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}

const ll MOD = 1000000007;

vector<vector<ll>> dp_tree;
vector<vector<ll>> dp_forest;

ll rec_tree(const vector<ll> &C,ll l,ll r);

ll rec_forest(const vector<ll> &C,ll l,ll r){
    if(dp_forest[l][r] >= 0) return dp_forest[l][r];

    ll ret = 0;
    ret += rec_tree(C, l, r);
    repeat(m,l,r){
        if(C[l] < C[m+1]){
            ret += rec_tree(C, l, m) * rec_forest(C, m+1, r);
            ret %= MOD;
        }
    }

    dp_forest[l][r] = ret;
    debug("forest");
    debug(dp_forest);
    return ret;
}

ll rec_tree(const vector<ll> &C,ll l,ll r){
    if(dp_tree[l][r]>=0)return dp_tree[l][r];
    dp_tree[l][r] = rec_forest(C, l+1, r);
    debug("tree");
    debug(dp_tree);
    return dp_tree[l][r];
}

bool solve(){
    ll N;cin>>N;
    vector<ll> C(N);cin>>C;
    if(C[0] != 1){
        cout << 0 <<endl;
        return false;
    }
    rep(i,N)C[i]--;
    dp_tree.resize(N,vector<ll>(N));
    dp_forest.resize(N,vector<ll>(N));    
    rep(i,N)rep(j,N){
        dp_tree[i][j]=dp_forest[i][j]=-1;
    }
    rep(i,N){
        dp_tree[i][i] = 1;
        dp_forest[i][i] = 1;
    }
    
    cout << rec_tree(C, 0, C.size()-1) %MOD <<endl;
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
