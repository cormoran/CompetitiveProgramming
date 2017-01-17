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
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>
ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
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

const int INF = 1 << 30;

struct State{
    int index;
    ll cost;
    set<int> visited;
    State(int i,ll c, set<int> visited):index(i),cost(c),visited(visited){;}
    bool operator < (const State &r) const {return cost < r.cost;}
    bool operator > (const State &r) const {return cost > r.cost;}
};

int dijkstra(const vector<vector<int>> &G, const vector<string> &S, int K){
    int N = G.size();
    priority_queue< State ,vector<State>,greater<State> > que;
    vector<vector<int>> norm(K+1, vector<int>(N, INF));

    rep(i,N){
        set<int> s;
        s.insert(i);
        que.push( State(i, S[i].size()+1, s) );
        norm[1][i] = S[i].size()+1;
    }
    
    while(not que.empty()){
        State now = que.top(); que.pop();
        int k = now.visited.size();
        if(norm[k][now.index] < now.cost) continue;
        debug("k", k, "c", now.cost, S[now.index]);
        if( k == K ) continue;
        rep(i,N){
            if(not now.visited.count(i)){
                if(norm[k+1][i] > now.cost + G[now.index][i]){
                    set<int> nxtset = now.visited;
                    nxtset.insert(i);
                    State nxt = State(i, now.cost + G[now.index][i], nxtset);
                    norm[k+1][i] = nxt.cost;
                    que.push( nxt );
                }
            }
        }
    }
    int ret = INF;
    debug(norm[K]);
    rep(i,N){
        ret = min(ret, (int)norm[K][i]+(int)S[i].size());
    }
    
    return ret;
}

// s to t
int calc_distance(const string &s, const string &t){
    int same = 0;
    rep(i,min(s.size(),t.size())){
        if(s[i] == t[i]) same++;
        else break;
    }
    return s.size() + t.size() - same * 2 + 1;
}

bool solve(const int C){
    cerr << "case" << C << endl;
    int K,N; cin >> N >> K;
    vector<string> S(N); cin >> S;
    vector<vector<int>> d(N,vector<int>(N,INF));
    rep(i,N){
        rep(j,N){
            if(i != j){
                d[i][j] = calc_distance(S[i],S[j]);
                debug(S[i],"->",S[j],d[i][j]);
            }
        }
    }
    cerr << "calcd" << C << endl;
    printf("Case #%d: %d\n", C, dijkstra(d,S,K));
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    int T; cin >> T;
    int C = 1;
    while( C <= T ) solve(C++);
    return 0;
}
