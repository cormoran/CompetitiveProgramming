//#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<string>
#include<cmath>
#include<cassert>
#include<map>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

int N,K;
vector<string> G;
bool visited[3][100];

bool rec(int y,int x){
    if(x>=N-1)return true;
    if(visited[y][x])return false;
    visited[y][x]=true;
    
    if(G[y][x+1] != '.')return false;
    
    bool ret =false;
    for(int dy =-1;dy<=1;dy++){
        int ny = y+dy;
        if(0<=ny && ny <3){
            bool check=true;
            for(int dx =1;dx<=3;dx++){
                int nx = x+dx;
                if(nx<N && G[ny][nx]!='.')check=false;
            }
            if(check)ret |= rec(ny, x+3);
        }
    }
    return ret;
}


int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;

    while(T--){
        cin>>N>>K;
        G.clear();
        G.resize(3);
        rep(i,3)rep(j,100)visited[i][j]=false;
        rep(i,3){
            cin>>G[i];
        }
        int sy=-1;
        rep(i,3)if(G[i][0]=='s')sy=i;
        assert(sy>=0);
        cout << (rec(sy,0) ? "YES" : "NO") <<endl;
    }
    
    return 0;
}
