#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<array>
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

array<vector<int>,2> encode(const array<string,2> &G){
    array<vector<int>,2> ret;
    rep(i,2) ret[i].resize(G[i].size(),0);
    rep(i,2){
        int cnt = 0;
        rep(j,G[i].size()){
            if(G[i][j] == 'X'){
                for(int k = j-1; k>=0 and G[i][k] != 'X';k--) ret[i][k] = cnt;
                cnt = 0;
            } else {
                cnt ++;
            }
        }
        for(int k = (int)G[i].size()-1; k>=0 and G[i][k] != 'X';k--) ret[i][k] = cnt;
    }
    return ret;
}

int count(array<vector<int>,2> &G){
    int cnt = 0;
    rep(i,2){
        int tmp = -1;
        bool decreased = false;
        rep(j,G[i].size()){
            if(G[i][j] != tmp){
                tmp = G[i][j];
                decreased = false;
                if(tmp > 0) cnt++;
            }
            if(G[(i+1)%2][j] == 1){
                if(not decreased and (G[i][j] >= 1)){
                     cnt --;
                     decreased = true;
                     if(G[i][j] == 1 and i == 0) cnt++;
                }
            }
        }
    }
    return cnt;
}

bool solve(int C){
    debug("case",C);
    int N; cin >> N;
    array<string,2> G; cin >> G[0] >> G[1];
    //G = compress(G);
    array<vector<int>,2> Gcnt = encode(G);
    printf("Case #%d: %d\n", C, count(Gcnt));
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    int T; cin >> T;
    int C = 1;
    while(C <= T) solve(C++);
    return 0;
}
