#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)

template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K; cin >> N >> K;

    vector<vector<int>> sum_black(2 * K + 1, vector<int>(2 * K + 1));
    vector<vector<int>> sum_white(2 * K + 1, vector<int>(2 * K + 1));

    int init_ans = 0;
    int init_ans2 = 0;
    rep(i, N) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        x = x % (2 * K);
        y = y % (2 * K);
        (c == 'B' ? sum_black : sum_white)[y + 1][x + 1]++;
        bool in_black = (x < K and y < K) or (x >= K and y >= K);
        init_ans += (c == 'B' ? in_black : not in_black);
        init_ans2 += (c == 'W' ? in_black : not in_black);
    }
    rep(y, 2 * K + 1) {
        rep(x, 2 * K) {
            sum_black[y][x + 1] += sum_black[y][x];
            sum_white[y][x + 1] += sum_white[y][x];
        }
    }
    rep(y, 2 * K) {
        rep(x, 2 * K + 1) {
            sum_black[y + 1][x] += sum_black[y][x];
            sum_white[y + 1][x] += sum_white[y][x];
        }
    }    

    auto block_sum = [&] (vector<vector<int>> &sum, int sy, int sx, int ey, int ex) {
        int block1 = sum[ey][ex] - sum[ey][sx] - sum[sy][ex] + sum[sy][sx];
        sy = (sy + K) % (2 * K);
        ey = (ey + K) % (2 * K);
        sx = (sx + K) % (2 * K);
        ex = (ex + K) % (2 * K);
        if(ey == 0) ey = 2 * K;
        if(ex == 0) ex = 2 * K;
        int block2 = sum[ey][ex] - sum[ey][sx] - sum[sy][ex] + sum[sy][sx];
        return block1 + block2;
    };

    auto solve = [&] (vector<vector<int>> &sum_white, vector<vector<int>> &sum_black, int init_ans) {
        int ans = init_ans;
        rep(dy, K) {
            rep(dx, K) {
                int black_to_white = block_sum(sum_white, dy, 0, K, dx) + block_sum(sum_white, 0, dx, dy, K);
                black_to_white    -= block_sum(sum_black, dy, 0, K, dx) + block_sum(sum_black, 0, dx, dy, K);            
                int white_to_black = block_sum(sum_black, dy + K, 0, K + K, dx) + block_sum(sum_black, 0, dx + K, dy, K + K);
                white_to_black    -= block_sum(sum_white, dy + K, 0, K + K, dx) + block_sum(sum_white, 0, dx + K, dy, K + K);
                set_max(ans, init_ans + black_to_white + white_to_black);
            }
        }
        return ans;
    };    

    cout << max<int>(solve(sum_white, sum_black, init_ans), solve(sum_black, sum_white, init_ans2)) << endl;
    return 0;
}
