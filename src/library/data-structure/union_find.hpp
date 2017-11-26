#pragma once
#include "common/simple_header.hpp"

//0 to n-1 でも1 to nでもOK
struct UnionFind{
    int n;
    vector<int> p;
    UnionFind(int nn) {
        n = nn + 1; // 1-based safe
        p.resize(n);
        rep(i, n) p[i] = i;
    }
    int root(int x) {
        return p[x] == x ? x : (p[x] = root(p[x]));
    }
    void unite(int x,int y) {
        x = root(x); y = root(y);
        if(x != y) p[y] = x;
    }
    bool query(int x,int y){
        return root(x) == root(y);
    }
    map<int, vector<int>> get_group() {
        map<int, vector<int>> res;
        rep(i, p.size()) {
            res[root(i)].push_back(i);
        }
        return res;
    }
};
