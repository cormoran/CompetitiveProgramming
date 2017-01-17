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

bool solve(){
    int N; cin >> N;
    vector<int> X(N);
    vector<bool> use(N);
    priority_queue<pair<int,int>> que;
    rep(i, N){
        cin >> X[i];
        if(X[i] == 0){
            for(int j = 0; j < 3 and que.size(); j++){
                use[que.top().second] = true;
                que.pop();
            }
            while(que.size()) que.pop();
        } else {
            que.push(make_pair(X[i], i));
        }
    }

    string str[4] = {"Stack", "Queue", "Front", "Back"};
    int cnt = 0;
    rep(i, N){
        if(X[i] == 0){
            cout << cnt ;
            rep(j, cnt) cout << " pop" << str[j];
            cnt = 0;
        } else {
            cout << "push" << str[use[i] ? cnt++ : 3];
        }
        cout << endl;
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
