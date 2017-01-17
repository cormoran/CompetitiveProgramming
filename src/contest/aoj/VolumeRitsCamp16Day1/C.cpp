#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cmath>
using namespace std;

#define rep(i,j) for(int i = 0;i<(int)(j);i++)

int count(vector<char> &cs, int cnt){
    if(cs.size() == 1) return cnt > 1 ? 3 : 1;
    else if(cnt > 1){
        return cs.size() * 2 - 1 + 2 + (int)log10(cnt) + 1 + 1;
    } else {
        return cs.size() * 2 - 1;
    }
}

int main(){
    int N; cin >> N;
    string s; cin >> s;
    vector<int> c_cnt('z'-'a' + 1, 0);
    for(char c : s) if('a' <= c and c <= 'z') c_cnt[c-'a']++;
    map<int, vector<char>> i_cnt;
    rep(i, c_cnt.size()){
        if(c_cnt[i] > 0) i_cnt[c_cnt[i]].push_back(i + 'a');
    }
    int ans  = -1;
    for(auto& p : i_cnt){
        int cnt = p.first;
        vector<char> cs = p.second;
        ans += count(cs, cnt) + 1;
    }
    cout << ans << endl;
    return 0;
}
