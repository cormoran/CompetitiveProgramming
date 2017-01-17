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
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

void fail(){
    cout << "No" << endl;
    exit(0);
}

void ok(){
    cout << "Yes" << endl;
    exit(0);
}

int N;
int U, V;
vector<vector<int>> E;

void input(){
    cin >> N >> U >> V;
    E.resize(N);
    rep(i, N-1){
        int a, b; cin >> a >> b;
        a--; b--;
        E[a].push_back(b);
        E[b].push_back(a);    
    }
}

bool is_connected(int a, int b){
    return find(all(E[a]), b) != E[a].end();
}

void erase_edge(int a, int b){
    E[a].erase(find(all(E[a]), b));
    E[b].erase(find(all(E[b]), a));
}

int next_node(int now, int pre){
    if(E[now].size() == 1)  return E[now][0] != pre ? E[now][0] : -1;
    else if(E[now].size() == 2) return E[now][0] != pre ? E[now][0] : E[now][1];
    else assert( false );
}

// depth , last
pair<int,int> go(int now, int pre){
    int depth = 0;
    while(now >= 0){
        int nxt = next_node(now, pre);
        pre = now;
        now = nxt;
        depth++;
    }
    return make_pair(depth, pre);
}

int main(){
    
    input();

    if(N % 2 == 1) fail();
    rep(i, E.size()) if(E[i].size() > 3) fail();
    
    vector<int> rank3, rank1;
    rep(i, N){
        if(E[i].size() == 1) rank1.push_back(i);
        if(E[i].size() == 3) rank3.push_back(i);
    }


    switch(rank3.size()){
        case 2 :
            {
                if(is_connected(rank3[0], rank3[1])){
                    erase_edge(rank3[0], rank3[1]);
                } else fail();
            }
            break;
        case 1 :
            {
                int target, max_depth = -1;
                for(int nxt : E[rank3[0]]){
                    int d = go(nxt, rank3[0]).first;
                    if(d > max_depth){
                        target = nxt;
                        max_depth = d;
                    }
                }
                if(E[target].size() != 1) rank1.push_back(target);
                erase_edge(rank3[0], target);
            }
            break;
        case 0 :
            {
                int now = rank1[0], pre = -1;
                rep(i, N/2){
                    int nxt = next_node(now, pre);
                    pre = now;
                    now = nxt;
                }
                cerr << now << " " << pre << endl;;
                if(E[now].size() > 1) rank1.push_back(now);
                if(E[pre].size() > 1) rank1.push_back(pre);
                erase_edge(now, pre);
            }
            break;
        default :
            fail();
    }
    
    
    if(rank1.size() != 4) fail();

    if( find( all(rank1), U) != rank1.end() and
        find( all(rank1), V) != rank1.end() ){
        pair<int,int> p = go(U, -1);
        if(p.first +1 == N/2 and p.second != V) ok();
    }

    fail();
    
    return 0;
}
