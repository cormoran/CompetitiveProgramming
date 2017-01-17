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

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl
// vector
template<class T> ostream& operator << (ostream &os , const vector<T> &v) {
    for(const T &t : v) os << "\t" << t; return os << endl;
}
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) {
    return os << "<" << v.first << " " << v.second << ">";
}

struct Node {
    int val;
    int idx;
    Node *l, *r;
    Node() {
        l = NULL;
        r = NULL;
    }
    Node(int val, int idx) :val(val), idx(idx) {
        l = NULL;
        r = NULL;
    }
    
};

void print(Node * root) {
    if(root == NULL) return;
    print(root->l);
    cerr << " " << root->val << " ";
    print(root->r);
}

bool solve() {
    int n; scanf("%d", &n);
    

    vector<int> parent(n);

    Node *root = new Node;
    scanf("%d", &root->val);
    root->idx = 0;
    map<int, Node*> link, link2;
    link[-root->val] = root;
    link2[root->val] = root;
    rep(i, n - 1) {
        int val; scanf("%d", &val);
        Node *now = root;
        auto p = link.upper_bound(-val);
        auto p2 = link2.upper_bound(val);
        if(p != link.end()) now = p->second;
        if(p2 != link2.end()) now = p2->second;
        
        while(true) {
            //cerr << "debug" << endl;
            //print(root);
            //cerr << endl;
            if(now->val < val) {
                if(now->r == NULL) {
                    now->r = new Node(val, i + 1);
                    parent[i] = now->val;
                    link[-val] = now->r;
                    link2[val] = now->r;
                    break;
                } else now = now->r;
            } else {
                if(now->l == NULL) {
                    now->l = new Node(val, i + 1);
                    parent[i] = now->val;
                    link[-val] = now->l;
                    link2[val] = now->l;
                    break;
                } else now = now->l;
            }
        }
    }
    //print(root);
    
    rep(i, n - 1) {
        cout << parent[i] << (i == n -2 ? "\n" : " ");
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
