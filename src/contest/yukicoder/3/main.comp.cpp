#include <bits/stdc++.h>
using namespace std;


template<class T>
int bitcount(T n){
	int ret = 0;
	while (n > 0) ret++, n &= n - 1;
	return ret;
}

int main() {
    int N; cin >> N;
    vector<int> visited(N);
    queue<int> que;
    que.push(0);
    int ans = 1;
    for(; que.size(); ans++) {
        queue<int> nxt_que;
        while(que.size()) {
            int a = que.front(); que.pop();
            if(visited[a]) continue;
            visited[a] = true;
            if(a == N - 1) goto OK;
            // int b = __builtin_popcount(a + 1);
            int b = bitcount(a + 1);
            if(a + b < N and not visited[a + b]) nxt_que.push(a + b);
            if(a - b >= 0 and not visited[a - b]) nxt_que.push(a - b);
        }
        swap(que, nxt_que);
    }
    cout << -1 << endl;
    return 0;
OK:
    cout << ans << endl;
    return 0;
}
