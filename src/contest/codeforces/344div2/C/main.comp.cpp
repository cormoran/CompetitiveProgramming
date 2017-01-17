//  codeforces -  - C  / 2016-03-04
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
#include<numeric>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}
template<typename T>istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R> void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}


bool solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n); cin >> a;
    vector<int> t(m), r(m);
    rep(i, m) cin >> t[i] >> r[i];
    int ed = *max_element(all(r));
    sort( a.begin(), a.begin() + ed );

    stack<int> a_r, a_t;
    {
        vector<bool> use(m);
        int tail = 0;
        for(int i = m-1; i >= 0; i--){
            if(r[i] <= tail) continue;
            a_r.push(r[i]);
            a_t.push(t[i]);
            tail = r[i];
        }
    }
    
    stack<int> ans;
    
    int l = 0, ri = n-1;
    rep(i, n - a_r.top()){
        ans.push(a[ri--]);
    }
    sort(a.begin(), a.begin() + ri + 1);
    int size = a_r.size();
    rep(i, size - 1){
        int rr = a_r.top(); a_r.pop();
        int left = rr - a_r.top();
        while(left--){
            if(a_t.top() == 1) ans.push(a[ri--]);
            else ans.push(a[l++]);
        }
        a_t.pop();
    }

    while(ri >= l){
        ans.push(a_t.top() == 1 ? a[ri--] : a[l++]);
    }

    while(not ans.empty()){
        int f = ans.top(); ans.pop();
        cout << f << (ans.empty() ? "\n" : " ");
    }


    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
