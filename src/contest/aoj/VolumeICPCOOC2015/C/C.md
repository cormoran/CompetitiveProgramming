---
title        : aoj-VolumeICPCOOC2015-C
date         : 2015-11-29
contests     : aoj
status        : AC
problemtypes :
- ゲーム

---

# ACM-ICPC 2015 Tsukuba C : Sibling Rivalry

  本番中に自分が色々やらかして解けなかった問題。解いておかなければならなかったレベルの問題...
  

<!--more-->


## 問題概要
  ２人が最善を尽くす問題。

  有向グラフが与えられ、Bがスタートからゴールを目指す。

- プレーヤーA :

  Bがゴールするのを防ぐ。

  3種の命令a,b,cから、任意の命令を選べる。

  a,b,cはそれぞれ、Bをa,b,c回移動させる命令

- プレーヤーB :

  startからgoalを目指す。Aの一回の命令でその指定回数だけグラフ上の点を移動する。

  移動先は有向グラフ上で移動できる点ならBが自由に選べるが、必ず指定回移動しないといけない・

  指定回数ぴったりでゴールに着いた場合のみゴールできる。途中で他の点に移動できなくなったらBの負け


  互いに最善を尽くした時、最低何手あればBが必ずゴールできる？


## 解法

  ゴールから見ていく。

　ゴール集合なるものを作り、a,b,cいずれの命令がきてもゴール集合に入れるような点をゴール集合に加えていく。最後に

~~~

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

~~~