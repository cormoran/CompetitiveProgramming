//  aoj-VolumeICPCOOC2015-C  / 2015-11-29
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
#include<array>
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

template<typename T>ostream& operator << (ostream &os , const set<T> &v){
    os << "[";
    for(T i : v) os << i << " ";
    os << "]" << endl;
    return os;
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

typedef vector<vector<int>> Edgelist;

set<int> get_neighbors(const Edgelist &E,int s,int dist){
    set<int> state[2];
    state[0].insert(s);
    rep(i, dist){
        set<int> &pre = state[ i%2 ],
                 &now = state[ (i+1)%2 ];
        now.clear();
        for(int pv : pre){
            for(int nxt : E[pv]){
                now.insert(nxt);
            }
        }
        //debug("get",dist,i+1,now);
    }
    return state[dist%2];
}

set<int> get_intersection(int n,array<set<int>,3> &sets){
    vector<int> cnt(n,0);
    rep(i,3){
        for(int v : sets[i]){
            cnt[v]++;
        }
    }
    set<int> ret;
    rep(i,n)if(cnt[i]==3)ret.insert(i);
    return ret;
}

bool solve(){
    int n,m; cin >> n >> m;
    array<int,3> abc; rep(i,3) cin>>abc[i];
    Edgelist E(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        --a;--b;
        E[b].push_back(a); // reversed edge
    }
    debug(E);
    
    set<int> goals;
    array<set<int>,3> neighbors;
    vector<bool> visited(n);
    vector<int> dist(n,-1);
    goals.insert(n-1);
    int pre_goals_size = 0;
    int turn = 1;
    while(pre_goals_size != (int)goals.size()){
        pre_goals_size = goals.size();
        set<int> goals_clone = goals;
        for(int v : goals_clone){
            if(visited[v])continue;
            visited[v] = true;
            rep(i,3){
                set<int> tmp = get_neighbors(E, v, abc[i]);
                neighbors[i].insert( all(tmp) );
                debug(i,neighbors[i]);
            }
        }

        set<int> intersection = get_intersection(n,neighbors);
        debug(intersection);
        for(int ng : intersection){
            if(not goals.count(ng)){
                dist[ng] = turn;
                goals.insert(ng);
            }
        }
        turn++;
    }

    if(dist[0] < 0) cout << "IMPOSSIBLE" <<endl;
    else cout << dist[0] << endl;
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
