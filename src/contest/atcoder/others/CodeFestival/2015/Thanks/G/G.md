---
title        : atcoder-CodeFestival-2015-Thanks-G
date         : 2015-12-08
contests     : atcoder
status        : AC
problemtypes :
- グラフ

---

# G.カメレオン

<!--more-->

## 問題概要

  私はカメレオン。 N個の広場があり、M本の道でつながっている。各道には色（非負整数）が指定されており、色cの道を通るには体色をcに変える必要がある。色を変えるには自分の色をkとすると|c-k|だけ時間がかかる。

　広場1からNまで移動する際の最短時間を求める

## 解法

　現在の自分の色を持ってダイクストラ。

　今まで、自分のダイクストラ法はpopの直後でその状態までの距離を決定し、push周辺では距離の更新をしていなかったのだが、その方法ではTLEした。蟻本に乗っているような感じの、push前後で最短距離を更新してダメなやつらをpush前に切り捨てる実装にしたら通った。前者の実装の方がダイクストラっぽさが出ていてわかりやすいと思うけど、heapに明らかに無駄な状態をpushしまくっているので無駄が多い。今までほとんど前者でやってきたけど今度からは後者の方法にしようと思った。


~~~
#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()
#define mp(x,y) make_pair(x,y)

// vector
template<typename T>ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}
template<typename T>istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

// debug
#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R> void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}

// begin ...

struct Edge{
    int to; ll cost,color;
    Edge(int to,ll cost,ll color):to(to),cost(cost),color(color){}
};

typedef vector<vector<Edge>> EdgeList;

struct state{
    int index; ll cost,color;
    state(int i,ll c,ll cl):index(i),cost(c),color(cl){;}
    bool operator<(const state &r)const{return cost < r.cost;}
    bool operator>(const state &r)const{return cost > r.cost;}
};

ll dijkstra(EdgeList &G, int start, int goal){
    priority_queue< state ,vector<state>,greater<state> > que;
    map< pair<int,ll>, ll > dist; // index, color
    
    que.push(state(start,0,1));
    dist[ mp(0,1) ] = 0;
    
    while(not que.empty()){
        state now = que.top(); que.pop();

        if(now.index == goal) return now.cost;
        
        for(Edge e : G[now.index]){
            ll nxt_cost = now.cost + e.cost + abs(now.color - e.color);

            if(not dist.count( mp(e.to, e.color) )
               or nxt_cost < dist[ mp(e.to, e.color) ] ){

                dist[ mp(e.to, e.color) ] = nxt_cost;
                que.push( state(e.to, nxt_cost, e.color) );
                
            }
        }
    }
    assert( false );
}

bool solve(){
    int n,m; cin >> n >> m;
    EdgeList E(n);
    rep(i,m){
        ll a,b,c,t; cin >> a >> b >> c >> t;
        a--,b--;
        E[a].push_back( Edge(b, t, c) );
        E[b].push_back( Edge(a, t, c) );
    }
    
    cout << dijkstra(E, 0, n-1) << endl;
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~