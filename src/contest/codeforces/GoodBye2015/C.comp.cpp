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


bool solve(){
    int h,w; cin >> h >> w;
    vector<string> G(h); cin >> G;

    vector<vector<int>> sum(h+1,vector<int>(w+1,0));
    vector<vector<int>> hsum(h+1,vector<int>(w+1,0)),wsum(h+1,vector<int>(w+1,0));
    
    rep(r,h){
        rep(c,w){
            sum[r+1][c+1] = sum[r][c+1] + sum[r+1][c] - sum[r][c] ;

            hsum[r+1][c+1] = hsum[r][c+1] ;
            wsum[r+1][c+1] = wsum[r+1][c] ;
            
            if(G[r][c] == '.'){
                if(r >0 and G[r-1][c] == '.'){
                    sum[r+1][c+1]++;
                    wsum[r+1][c+1]++;
                }
                if(c >0 and G[r][c-1] == '.'){
                    sum[r+1][c+1]++;
                    hsum[r+1][c+1]++;
                }
            }

        }
    }
    

    int q; cin >> q;
    rep(i,q){
        int r1,c1; cin >> r1 >> c1;
        r1--;c1--;
        int r2,c2; cin >> r2 >> c2;
        int diff = hsum[r2][c1+1] - hsum[r1][c1+1] + wsum[r1+1][c2] - wsum[r1+1][c1];
        cout << sum[r2][c2] - sum[r2][c1] - sum[r1][c2] + sum[r1][c1] - diff <<endl;
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
