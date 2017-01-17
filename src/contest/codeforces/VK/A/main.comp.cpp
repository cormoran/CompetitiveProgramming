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
#include<numeric>
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

const int INF = 1 << 31;

bool solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> A(n, vector<int>(m, 0));
    vector<vector<int>> in(q);
    rep(i, q) {
        int a; cin >> a;
        in[i].push_back(a);
        if(a == 3) rep(j, 3) {
                int c; cin >> c;
                in[i].push_back(c);
            }
        else {
            int c; cin >> c;
            in[i].push_back(c);
        }
    }

    // solve

    for(int i = q-1; i >= 0; i--) {
        if(in[i][0] == 3) {
            int r = in[i][1] - 1;
            int c = in[i][2] - 1;
            int v = in[i][3];
            A[r][c] = v;
        } else if(in[i][0] == 1) {
            int r = in[i][1] - 1;
            int tmp = A[r][m-1];
            for(int j = m-2; j >= 0; j--) A[r][j+1] = A[r][j];
            A[r][0] = tmp;
        } else if(in[i][0] == 2) {
            int c = in[i][1] - 1;
            int tmp = A[n-1][c];
            for(int j = n-2; j >= 0; j--) A[j+1][c] = A[j][c];
            A[0][c] = tmp;
        }
    }

    rep(i, n) {
        rep(j, m) {
            cout << A[i][j] << (j == m-1 ? "\n" : " ");
        }
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
