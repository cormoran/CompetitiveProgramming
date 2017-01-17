//  yukicoder -  - 307  / 2016-03-01
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


const int dx[] = { 0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

struct UnionFind{
    int n;
    vector<int> p;
    int size;
    UnionFind(int nn):n(nn){
        p.resize(n);
        rep(i,n) p[i] = i;
        size = n;
    }
    int root(int x){
        if(p[x] == x) return x;
        else return p[x] = root(p[x]);
    }
    void unite(int x,int y){
        x = root(x);
        y = root(y);
        if(x != y){
            p[y] = x;
            size--;
        }
    }
    bool query(int x,int y){
        return root(x) == root(y);
    }
};


// ---------- --------- ---------
int H, W;
vector<vector<int>> G;


int ptoi(int x, int y){
    return y * W + x;
}

bool is_in_field(int x, int y){
    return 0 <= x and x < W and 0 <= y and y < H;
}

bool solve(){
    cin >> H >> W;
    G.resize(H, vector<int>(W));
    rep(i, H) cin >> G[i];
    vector<int> color(H * W);
    rep(y,H) rep(x, W) color[ptoi(x,y)] = G[y][x];
    
    UnionFind ut(H*W);
    rep(y,H){
        rep(x, W){
            rep(dir, 4){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(0 <= nx and nx < W and
                   0 <= ny and ny < H){
                    if(G[y][x] == G[ny][nx]){
                        ut.unite(ptoi(x, y), ptoi(nx, ny));
                    }
                }
            }
        }
    }
    
    vector<set<int>> E(H * W);
    rep(y, H){
        rep(x, W){
            rep(dir, 4){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(is_in_field(nx, ny) and not ut.query(ptoi(x,y), ptoi(nx,ny))){
                    E[ut.root(ptoi( x,  y))].insert(ut.root(ptoi(nx, ny)));
                    E[ut.root(ptoi(nx, ny))].insert(ut.root(ptoi( x,  y)));
                }
            }
        }
    }
    
    int Q; cin >> Q;
    rep(i, Q){
        int y, x, c; cin >> y >> x >> c;
        y--; x--;
        int p = ut.root(ptoi(x, y));
        if(color[p] == c) continue;
        color[p] = c;
        for(int nxt : E[p]){
            if(nxt != ut.root(nxt)){
                E[p].insert(ut.root(nxt));
                E[p].erase(nxt);
            }
            if(color[p] == color[ut.root(nxt)]){
                for(int to : E[ut.root(nxt)]){
                    if(not ut.query(p, to)){
                        E[p].insert(ut.root(to));
                        E[ut.root(to)].insert(p);
                    }
                }
                ut.unite(p, nxt);
            }
        }
    }

    rep(y, H){
        rep(x, W){
            cout << color[ut.root(ptoi(x, y))] << (x != W-1 ? " " : "\n");
        }
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
