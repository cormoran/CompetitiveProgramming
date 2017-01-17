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

template<typename T>
ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}

template<typename T>
istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R>
void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}

struct Node {
    int n;
    Node *l, *r;
};

Node* parse(string A, int &i) {
    assert(A[i] == '(');
    i++;
    if(A[i] == ')') { i++; return NULL; }
    Node *ret = new Node();
    ret->l = parse(A, i);

    assert(A[i++] == '[');
    ret->n = atoi(&A[i]);
    while(isdigit(A[i])) i++;
    assert(A[i++] == ']');
    
    ret->r = parse(A, i);
    i++;
    return ret;
}

string marge(Node *a, Node *b) {
    if(a == NULL or b == NULL) return "()";
    string ret = "";
    ret  += "(";
    ret += marge(a->l, b->l);
    ret += "[" + to_string(a->n + b->n) + "]";
    ret += marge(a->r, b->r);
    ret += ")";
    return ret;
}

bool solve() {
    string a, b; cin >> a >> b;
    int i = 0;
    a = "(" + a + ")";
    b = "(" + b + ")";
    Node * an = parse(a, i);
    i = 0;
    Node * bn = parse(b, i);
    string ans = marge(an, bn);
    cout << ans.substr(1, ans.size() - 2) << endl;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
