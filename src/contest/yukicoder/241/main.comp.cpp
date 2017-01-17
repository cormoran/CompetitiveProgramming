#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << " " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

using Vatex = int;
template<typename Cost_t = ll>
class MaxFlow{
  public:
    vector< vector<Cost_t> > G; //隣接行列
    MaxFlow(int N) {
        G.resize(N, vector<int>(N));
    }
    
    void add_arc(Vatex v1,Vatex v2,Cost_t capacity){
        G[v1][v2] += capacity;
    }
    //now から end への増加できるフロー
    Cost_t dfs(Vatex now,Vatex end,Cost_t min_capacity,vector<bool> &visited){
        if( now == end ) return min_capacity;
        if( not visited[now] ){
            visited[now] = true;
            rep(i,G.size()){
                if(G[now][i] > 0){//nowからiへの弧容量の残余があれば進んでみる
                    Cost_t ret = dfs(i, end, min(min_capacity,G[now][i]), visited);
                    if(ret > 0){//ゴールに達したならその道で確定して残余ネットワークを更新
                        G[now][i] -= ret;
                        G[i][now] += ret;
                        return ret;
                    }
                }
            }
            return -2;//ゴールに行ける道がなかった
        }
        else return -1;//すでに訪問済みだった
    }
    
    Cost_t get_maxFlow(Vatex start,Vatex end){
        int ans = 0;
        //ゴールへの道がなくなるまで残余ネットワークの経路を検索
        vector<bool> is_visited(G.size());
        while(true){
            rep(i,G.size())is_visited[i]=false;
            int inc_f=dfs(start,end,INF,is_visited);
            if(inc_f>0)ans+=inc_f;
            else return ans;
        }
    }
};


class Solver {
  public:
    int N;
    vector<int> A;
    
    bool solve() {
        cin >> N;
        A.resize(N); cin >> A;

        // 0 ~ 49 : no
        // 50~ 99 : student
        // 100 : root
        // 101 : goal
        
        MaxFlow<int> flow(102);
        rep(i, N) {
            rep(j, N) {
                if(j != A[i]) flow.add_arc(j, i + 50, 1);                
            }
        }
        rep(i, N) flow.add_arc(100, i, 1);
        rep(i, N) flow.add_arc(i + 50, 101, 1);
        
        if(flow.get_maxFlow(100, 101) < N) {
            cout << -1 << endl;
        } else {
            vector<int> ans(N);
            rep(i, N) {
                bool flg = false;
                rep(j, N) {
                    if(flow.G[i + 50][j]) {
                        flg = true;
                        ans[i] = j;
                        break;
                    }                    
                }
                assert(flg);
            }
            rep(i, N) cout << ans[i] << endl;
        }        
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Solver s;
    s.solve();
    return 0;
}
