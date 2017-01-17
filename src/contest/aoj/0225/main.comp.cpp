#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<set>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

const int alpha_size = 'z' - 'a' + 1;

void visit(int now, vector<bool> &visited, const vector<set<int>> &E){
    visited[now] = true;
    for(int nxt : E[now]){
        if(not visited[nxt]){
            visit(nxt, visited, E);
        }
    }
}

bool solve(){
    int N; cin >> N;
    if(N == 0) return false;
    vector<int> d(alpha_size);
    vector<set<int>> E(alpha_size);
    rep(i, N){
        string s; cin >> s;
        int f = s.front() - 'a';
        int b = s.back() - 'a';
        ++d[f];
        --d[b];
        E[f].insert(b);
    }
    vector<bool> visited(alpha_size);
    rep(i, E.size()){
        if(E[i].size() > 0){
            visit(i, visited, E);
            break;
        }
    }
    bool flg = true;
    rep(i, alpha_size){
        if(d[i] != 0 or  (E[i].size() > 0 and not visited[i])) flg = false;
    }
    cout << (flg ? "OK" : "NG") << endl;
    
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
