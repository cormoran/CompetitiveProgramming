#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cassert>
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

typedef vector<vector<int>> EdgeList;

class LCA{
  public:
    vector< vector<int> > parent;//[i][j]：点jの2^i上の親　存在しない場合は-1
    vector<int> depth;
    int N,  log2_N;//log2_Nの端数 切り上げ 
    
    LCA(int n):N(n),log2_N( floor(log2(N))+1 ){
        parent.resize(log2_N,vector<int>(N,-1));
        depth.resize(N,-1);
    }
    
    //rootを根(depth=0)にして各nodeの深さを作る
    void makedepth(int root , const EdgeList &E){
        makedepth_dfs(E,-1,root,0);
    }
    
  private:
    //O(n)
    void makedepth_dfs(const EdgeList &E,int pre,int now,int dep){
        parent[0][now]=pre;
        depth[now]=dep;
        rep(i,E[now].size()){
            if(E[now][i]!=pre){
                makedepth_dfs(E,now,E[now][i],dep+1);
            }
        }
    }
    
  public:
    //O(nlogn)
    void doubling(){
        rep(i,log2_N-1){
            rep(j,N){
                if(parent[i][j]>=0)
                    parent[i+1][j]=parent[i][parent[i][j]];
                else parent[i+1][j]=-1;
            }
        }
    }
  
 int get_LCA(int n1,int n2) const {
        if(depth[n1]>depth[n2])swap(n1,n2);
        for(int i=0;i<log2_N;i++){
            if(((depth[n2] - depth[n1])>>i)&1) n2=parent[i][n2];
        }
        if(n1==n2) return n1;
        else{
            for(int i=log2_N-1;i>=0;i--)
                if(parent[i][n1]!=parent[i][n2]){
                    n1=parent[i][n1];
                    n2=parent[i][n2];
                }
            return parent[0][n1];
        }
    }
    
    int get_depth(int node) const { return depth[node]; }
    
};




struct EulerTour_t{
    vector<int> tour;
    vector<int> begins;
    vector<int> ends;
};

void dfs(const EdgeList &E,EulerTour_t &et,int now,int pre){
    et.begins[now] = et.tour.size();
    et.tour.push_back(now);
    for(int nxt : E[now]){
        if(nxt == pre)continue;
        dfs(E,et,nxt,now);
        et.tour.push_back(now);
    }
    et.ends[now] = et.tour.size();
}

EulerTour_t EulerTour(const EdgeList &E){
    int n = E.size();
    EulerTour_t et;
    et.begins.resize(n);
    et.ends.resize(n);
    dfs(E,et,0,-1);
    return et;
}

void EulerTour_Show(const EulerTour_t &et){
    rep(i,et.tour.size())cout << et.tour[i] << " ";
    cout << endl;
    rep(i,et.begins.size())cout << et.begins[i] << " ";
    cout << endl;
    rep(i,et.ends.size())cout << et.ends[i] << " ";
    cout << endl;
}


int query(const EulerTour_t &et, const LCA &lca){
    int M,K;cin>>M>>K;
    vector<int> fruits(M);
    rep(i,M){
        int v; cin >> v; v--;
        fruits[i]=et.begins[v];
    }
    
    sort(all(fruits));
    int max_depth = 0;
    rep(i,M-K+1){
        int l =fruits[i] , r = fruits[i+K-1];
        int cp = lca.get_LCA( et.tour[l], et.tour[r] );
        max_depth = max(max_depth , lca.get_depth(cp));
    }
    return max_depth;
}


bool solve(){
    int n;
    cin>>n;
    EdgeList E(n);
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--;b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    EulerTour_t et = EulerTour(E);

    //EulerTour_Show(et);
    
    LCA lca(n);
    lca.makedepth(0, E);
    lca.doubling();

    int Q; cin >> Q;
    rep(i,Q){
        cout <<query(et, lca) <<endl;
    }

    return false;
}

int main()
{
    while(solve());
    return 0;
}
