#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

class PingPongQueue {
  public:
    vector <int> whoPlaysNext(vector <int> skills, int N, int K) {
        queue<int> que;
        rep(i, skills.size()) que.push(i);        
        vector<int> win(skills.size());
        int a, b;
        a = que.front(); que.pop();
        b = que.front(); que.pop();
        rep(k, K) {
            if(skills[a] > skills[b]) swap(a, b);

            if(k == K - 1) {
                return {skills[a], skills[b]};
            }

            que.push(a);
            a = que.front(); que.pop();
            if(++win[b] > N) {
                win[b] = 0;
                que.push(b);
                b = que.front(); que.pop();
            }
        }
        return {};
    }
};


