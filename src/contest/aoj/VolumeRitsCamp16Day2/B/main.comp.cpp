#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)

template<typename T>
istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

bool solve(){
    int W, H; cin >> W >> H;
    int N; cin >> N;
    vector<int> P(N); cin >> P;

    int x[2] = {0, 0}, y[2] = {0, 1};
    int dx[2] = {1, 1}, dy[2] = {};

    int ans = 0;
    for(int p : P){
        x[p] += dx[p];
        y[p] += dy[p];
        if(y[p] == p and x[p] == W-1-p) dx[p] =  0, dy[p] = 1;
        if(x[p] == W-1-p and y[p] == H-1-p) dx[p] = -1, dy[p] = 0;

        if(x[0] == x[1] and abs(y[0] - y[1]) == 1) ans++;
        if(y[0] == y[1] and abs(x[0] - x[1]) == 1) ans++;
    }
    
    cout << ans << endl;
        
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
