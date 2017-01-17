#include<iostream>
#include<vector>
#include<set>
#include<cmath>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

struct UnionFind{
    int n;
    vector<int> p;
    UnionFind(int nn) : n(nn+1){
        p.resize(n);
        rep(i, n) p[i] = i;
    }
    int root(int x){
        if(p[x] == x) return x;
        else return p[x] = root(p[x]);
    }
    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x != y) p[y] = x;
    }
    bool query(int x, int y){
        return root(x) == root(y);
    }
};


int main(){
    int N, M; cin >> N >> M;
    UnionFind ut(N);
    set<int> absorbed;
    rep(i, M){
        int a, b; cin >> a >> b;
        a--; b--;
        absorbed.insert(a);
        absorbed.insert(b);
        ut.unite(a, b);
    }
    set<int> city;
    rep(i, N){
        if(ut.root(i) != i) city.insert(ut.root(i));
    }
    int villedge = N - absorbed.size();
    cout << abs(villedge - (int)city.size()) << endl;

    return 0;
}
