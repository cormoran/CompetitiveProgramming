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

template<typename T>
ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i != (int)v.size() - 1 ? " " : ""); return os;
}

template<typename T>
istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R>
void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}

pair<int,int> dfs(vector<vector<int>> &E, int now, vector<bool> &visited){
    pair<int,int> res = make_pair(1, now);
    visited[now] = true;
    for(int nxt : E[now]){
        if(not visited[nxt]){
            res = max(res, dfs(E, nxt, visited));
        }
    }
    visited[now] = false;
    res.first++;
    return res;
}

bool solve(){
    int n; cin >> n;
    vector<int> type(n), from(n); cin >> type >> from;

    vector<int> out_rank(n);
    rep(i, n){
        from[i]--;
        if(from[i] >= 0) out_rank[from[i]]++;
    }
    vector<vector<int>> E(n); // reversed edge
    rep(i, n){
        if(out_rank[i] <= 1
           and from[i] >= 0 and out_rank[from[i]] <= 1
           and type[from[i]] == 0){
            E[i].push_back(from[i]);
        }
    }

    vector<bool> visited(n);
    pair<int,int> res;
    int finish = -1;
    rep(i, n){
        if(type[i] == 1){
            auto ret = dfs(E, i, visited);
            if(ret.first > res.first){
                res = ret;
                finish = i;
            }
        }
    }

    
    vector<int> ans;
    int nxt = finish;
    
    while(nxt != res.second){
        ans.push_back(nxt + 1);
        nxt = from[nxt];
    }
    ans.push_back(nxt + 1);
    
    reverse( all(ans) );
    cout << ans.size() << endl;
    cout << ans << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
