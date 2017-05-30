#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()

int main() {
    int N; cin >> N;
    vector<int> dist(N, -1);        
    repeat(i, 1, N) {
        printf("? %d %d\n", 1, i + 1);
        fflush(stdout);
        cin >> dist[i];
    }
    int a = max_element(all(dist)) - begin(dist);
    fill(all(dist), -1);
    rep(i, N) {
        if(i == a) continue;
        printf("? %d %d\n", a + 1, i + 1);
        fflush(stdout);
        cin >> dist[i];
    }
    printf("! %d\n", *max_element(all(dist)));
    return 0;
}
