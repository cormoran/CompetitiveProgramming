#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
const int INF = 1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int K; cin >> K;
    vector<pii> points; // (x, y)
    int W = 2000 / 4;
    int H = (K - 2) / (4 * W);
    points.emplace_back(0, 0);
    { // make cols
        rep(i, W) {
            int x = i * 4 + 1;
            points.emplace_back(x, 0);
            points.emplace_back(x, INF);
            points.emplace_back(x + 2, INF);
            points.emplace_back(x + 2, 0);
        }
    }
    points.emplace_back(INF, 0);
    points.emplace_back(INF, -1);
    if(K % 2 == 0) {
        points.emplace_back(-1, -1);
    } else {
        points.emplace_back(-2, -1);
        points.emplace_back(-2, -2);
        points.emplace_back(-1, -2);
        K--;
    }
    points.emplace_back(-1, INF);
    points.emplace_back(0, INF);
    { // make rows        
        rep(i, H) {
            int y = INF - (i + 1) * 2;
            points.emplace_back(0, y);
            points.emplace_back(INF, y);
            points.emplace_back(INF, y - 1);
            points.emplace_back(0, y - 1);
        }
        int left = K - (4 * W * H + 2);
        if(left > 0) {
            points.emplace_back(0, 2);
            points.emplace_back(left, 2);
            points.emplace_back(left, 1);
            points.emplace_back(0, 1);
        }
    }
    cout << points.size() << endl;
    for(auto p : points) cout << p.first << " " << p.second << endl;
    
    return 0;
}
