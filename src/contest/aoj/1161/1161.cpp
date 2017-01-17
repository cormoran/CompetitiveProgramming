//#include<bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <cmath>
#include <cassert>
#include <cstdint>
#include <map>
using namespace std;

#define rep(i, j) for (int i = 0; i < (int)j; i++)
#define repeat(i, j, k) for (int i = (j); i < (k); i++)
#define all(v) begin(v), end(v)

const int INF = 1 << 30;  // 10E10

//順列生成
int rec(map<char, int>::iterator itr, map<char, int>::iterator end, const set<char> &tops, vector<bool> &used, int sum) {
    if(itr == end) return sum == 0;
    char c = itr->first;
    int weight = itr->second;
    itr++;
    int ret = 0;
    rep(i, 10) {
        if(used[i]) continue;
        if(i == 0 and tops.count(c)) continue;
        used[i] = true;
        ret += rec(itr, end, tops, used, sum + weight * i);        
        used[i] = false;
    }
    return ret;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        map<char, int> coefficient;
        set<char> tops;

        rep(i, n) {
            string s;
            cin >> s;
            if(s.size() > 1) tops.insert(s.front());
            
            for(int j = s.size() - 1, k = 1; j >= 0; j--, k *= 10) {
                coefficient[s[j]] += k * (i != n - 1 ? 1 : -1);
            }
        }
        vector<bool> used(10);
        int ans = rec(coefficient.begin(), coefficient.end(), tops, used, 0);

        cout << ans << endl;
    }
}
