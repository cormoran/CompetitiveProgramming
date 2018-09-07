#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cassert>
#include<map>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<class T>
using Mat = vector<vector<T>>;
pair<int,int> calc(Mat<int> &g,Mat<int> &C, Mat<int> &B){
    pair<int,int> ret;
    rep(r,g.size()){
        rep(c,g[r].size()){
            if(r<2 and g[r][c] == g[r+1][c]) ret.first += B[r][c];
            else if(r < 2) ret.second += B[r][c];
            if(c<2 and g[r][c] == g[r][c+1]) ret.first += C[r][c];
            else if(c<2) ret.second += C[r][c];
        }
    }
    return ret;
}

map<Mat<int>,pair<int,int>> memo;
pair<int,int> rec(Mat<int> g, bool fst, Mat<int> &C, Mat<int> &B){
    if(memo.count(g)) return memo[g];
    pair<int,int> ret = make_pair(-1,-1);
    bool flg = false;
    rep(r,g.size()){
        rep(c,g[r].size()){
            if(g[r][c] == 0){
                flg = true;
                g[r][c] = (fst ? 1 : -1);
                pair<int,int> tmp = rec(g,!fst,C,B);
                if(fst) ret = max(ret, tmp);
                else {
                    if(tmp.second > ret.second) ret = tmp;
                    else if(tmp.second == ret.second) ret = max(ret, tmp);
                }
                g[r][c] = 0;
            }
        }
    }
    if(not flg){
        ret = calc(g,C,B);
    }
    return memo[g] = ret;
}

bool solve(){
    Mat<int> B(2,vector<int>(3)), C(3,vector<int>(2));
    rep(i,2) rep(j,3) cin >> B[i][j];
    rep(i,3) rep(j,2) cin >> C[i][j];
    Mat<int> g(3,vector<int>(3,0));
    pair<int,int> ret = rec(g,true,C,B);
    cout << ret.first << endl << ret.second << endl;
    return false;
}

int main()
{
    while(solve());
    return 0;
}
