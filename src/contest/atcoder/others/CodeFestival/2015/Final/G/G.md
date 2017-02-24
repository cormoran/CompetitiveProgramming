---
title        : CodeFestival-2015-Final-G
date         : 2015-11-20
contests     : atcoder
problemtypes :
              - dp

---

# G.スタンプラリー

<!--more-->

## 問題概要

1を根とする木の、行きがけ順順序が与えられる。

元の木として考えられるものの総数を求めよ。

ただし、あるノードから子に遷移する場合、常に、まだ訪れていない最小の番号の子に移動することとする。

## 解法

本番中は部分木でDPできそうって思うところまでは行ったけどDPが書けず、諦めた。

下で実装した解法はchokudaiさんの解説そのまま。以下参照。（スライドはminになってるけどΣの間違いっぽい？）

<http://www.slideshare.net/chokudai/code-festival-2015-final>

区間DPをする。

行きがけ順序を{C[i]}とする。

DPTree[l][r]   : C[l] を根とし、C[r]までを子とする木の総数

DPForest[l][r] : C[l] を一番左の木の根として、C[r]まで使って作られる森の総数

するとDPテーブルは、

森の根全てをC[l]の子にする

$$ DP\\_Tree[l][r]   = DP\\_Forest[l+1][r] $$

森の左端に木をくっつける、(木は森)

以下を満たすmについて$$ l<m+1<=r , C[l]<C[m+1] $$
$$ DP\\_Forest[l][r] = DP\\_Tree[l][r] + \sum_m{DP\\_Tree[l][m] * DP\\_Forest[m+1][r]} $$

初期値

(単一点からなる木、森の種類は１種類)

$$ DP\\_Forest[i][i] = DP\\_Tree[i][i] = 1 $$

( i > j の部分は使わない)

DPテーブル２個使うのは初めて解いた気がする。テーブルの埋まり方はTree,Forestともに、右下からC[l]<C[m+1]の条件を満たすところだけ埋まっていく感じだと思う

|  |  1  |  2  |  3  |  4  |
|:---:|:---:|:---:|:---:|:---:|
|  1  |  1  |  -  |  -  |  -  |
|  2  |  x  |  1  |  -  |  -  |
|  3  |  x  |  x  |  1  |  -  | 
|  4  |  x  |  x  |  x  |  1  |

|     |  1  |  2  |  3  |  4  |
|:---:|:---:|:---:|:---:|:---:|
|  1  |  1  |     |     |     |
|  2  |  x  |  1  |  -  |  -  |
|  3  |  x  |  x  |  1  |  -  | 
|  4  |  x  |  x  |  x  |  1  |

|     |  1  |  2  |  3  |  4  |
|:---:|:---:|:---:|:---:|:---:|
|  1  |  1  |     |     |     |
|  2  |  x  |  1  |     |     |
|  3  |  x  |  x  |  1  |  -  | 
|  4  |  x  |  x  |  x  |  1  |



~~~
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

~~~