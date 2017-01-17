#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define rep(i, j) for(int i = 0; i < (j); i++)
using namespace std;

bool visit[51][2501][2501] = {};

int main(){
    int n; cin >> n;
    vector<int> t(n);
    int allsum = 0;
    rep(i, n){
        cin>>t[i];
        allsum += t[i];
    }
    int ans = 1 << 30;
    visit[0][0][0] = true;
    int cnt = 0;
    rep(i, n){
        rep(j, allsum){
            rep(k, allsum){
                if(visit[i][j][k] and j + t[i] <= allsum and k + t[i] <= allsum){
                    cnt++;
                    visit[i+1][j+t[i]][k] = true;
                    visit[i+1][j][k+t[i]] = true;
                    visit[i+1][j][k] = true;
                }
            }
        }
    }
    cerr << cnt << endl;
    rep(j, allsum){
        rep(k, allsum){
            if(visit[n][j][k]) ans = min(ans, max({j, k, allsum - j - k}));
        }
    }

    cout<< ans <<endl;
    return 0;
}
