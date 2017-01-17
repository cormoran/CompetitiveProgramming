//  codeforces-191div2-D  / 2015-12-17
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

struct Point{
    int x,y;
    Point(){};
    Point(int x,int y):x(x),y(y){};
    Point operator +(const Point &p) const{
        return Point(x + p.x,y + p.y);
    }
    bool operator == (const Point &p) const{
        return (x == p.x and y == p.y);
    }
};

struct Ans{
    char c;
    int x,y;
    Ans(char c,int x,int y):c(c),x(x),y(y){};
    Ans(){};
};

const Point dp[] = { {0,1},{0,-1},{1,0},{-1,0}};

void dfs(vector<Ans> &ans,vector<string> &G,Point now,Point pre){
    G[now.x][now.y] = 'R';
    rep(i,4){
        Point nxt = now + dp[i];
        if( nxt.x < 0 or (int)G.size() <= nxt.x or nxt.y < 0 or (int)G[0].size() <= nxt.y) continue;
        if( nxt == pre || G[nxt.x][nxt.y] != '.') continue;
        dfs(ans, G, nxt, now);
        ans.push_back(Ans('D',nxt.x,nxt.y));
        ans.push_back(Ans('R',nxt.x,nxt.y));
    }
    return;
}

bool solve(){
    int n,m; cin >> n >> m;
    vector<string> G(n);
    cin >> G;
    int ans_num = 0;
    vector<Ans> ans;
    rep(r,n){
        rep(c,m){
            if(G[r][c] != '#'){
                ans_num++;
            }
        }
    }
    
    rep(r,n){
        rep(c,m){
            if(G[r][c] == '.'){
                dfs(ans,G,Point(r,c),Point(-1,-1));
            }
        }
    }

    cout << ans.size() + ans_num << endl;

    rep(r,n){
        rep(c,m){
            if(G[r][c] != '#'){
                printf("%c %d %d\n",'B',(int)r+1,(int)c+1);
            }
        }
    }
    rep(i,ans.size()){
        printf("%c %d %d\n",ans[i].c, ans[i].x+1, ans[i].y+1);
    }

    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
