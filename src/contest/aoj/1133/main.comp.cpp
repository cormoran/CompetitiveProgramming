#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
const double EPS = 1e-8;

struct Node {
    int l, r, h;
    double water;
    bool is_child_full;
    list<Node> children; // all children shold have same height.
    Node(int l, int r, int h) : l(l), r(r), h(h), water(0), is_child_full(false) {}    
    void insert(int b, int h, int d = 0) {
        if(children.size() == 0) {
            children.push_back(Node(l, b, h));
            children.push_back(Node(b, r, h));
        } else {
            auto child = find(b);
            if(child->h != h) {
                child->insert(b, h, d+1);
            } else {
                int lc = child->l;
                child->l = b;
                children.insert(child, Node(lc, b, h));
            }
        }
    }
    // find child which range contains p
    list<Node>::iterator find(int p) {
        for(auto c = begin(children); c != end(children); c++) {
            if(c->l <= p and p < c->r) return c;
        }
        assert(0);
    }
    double capacity() {
        return 30.0 * h * (r - l);
    }
    double pour(int p, double a) {
        if(water + a >= capacity()) {
            double left = water + a - capacity();
            water = capacity();
            return left;
        }
        water += a;
        assert(water / 30.0 / (r - l) <= h);
        if(children.size() > 0) {
            auto child = find(p);
            double left = child->pour(p, a);
            if(left == 0) return 0;
            assert(abs(child->height(p) - child->h) < EPS); // child is full
            double left1 = left / 2, left2 = left / 2;
            // go right
            auto c2 = child;
            while(left1 > 0 and c2 != end(children)) {
                left1 = c2->pour(c2->l, left1);
                c2++;
            }
            // go left
            c2 = child;            
            left2 += left1;
            if(c2 != begin(children)) {
                do {
                    c2--;
                    left2 = c2->pour(c2->r - 1, left2);
                } while(left2 > 0 and c2 != begin(children));
            }
            // go right(2nd)
            c2 = child;
            while(left2 > 0 and c2 != end(children)) {
                left2 = c2->pour(c2->l, left2);
                c2++;
            }
            if(left2 > 0) is_child_full = true;
        }
        return 0;
    }
    double height(int p) {
        if(is_child_full or children.size() == 0) return water / 30.0 / (r - l);
        return find(p)->height(p);
    }
    void show_structure(int d = 0) {        
        if(is_child_full) return;
        rep(i, d) cerr << "\t";
        for(auto p : children) cerr << "[" << p.l << ", " << p.water / 30.0 / (p.r - p.l) << "/" << p.h << " , " << p.r << ")" << " ";
        cerr << endl;
        for(auto p : children) p.show_structure(d + 1);
    }
};


void solve() {
    int N; cin >> N;
    // make tree
    vector<pii> HB(N); rep(i, N) cin >> HB[i].second >> HB[i].first;
    sort(all(HB), greater<pii>());    
    Node root(0, 100, 50);
    rep(i, N) root.insert(HB[i].second, HB[i].first);
    //root.show_structure();
    
    // input pour
    int M; cin >> M;
    vector<int> F(M), A(M); rep(i, M) cin >> F[i] >> A[i];
    // input measure
    int L; cin >> L;
    vector<pair<pii,int>> TP(L);
    rep(i, L) {
        cin >> TP[i].first.second >> TP[i].first.first;
        TP[i].second = i;
    }
    sort(all(TP));

    // simulate for each t    
    int tp_i = 0;
    vector<double> ans(L, -1);
    rep(t, 1000000) {
        // measure point
        while(tp_i < L and TP[tp_i].first.first == t) {            
            double a = root.height(TP[tp_i].first.second);
            ans[TP[tp_i].second] = a;
            tp_i++;
        }
        // update height
        rep(m, M) root.pour(F[m], A[m]);
    }
    rep(i, L) printf("%.6lf\n", ans[i]);
}


int main() {
    int D; cin >> D;
    rep(i, D) solve();
    return 0;
}
