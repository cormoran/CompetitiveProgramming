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




bool solve(int case_cnt){
    int n; cin >> n;
    vector<string> f(n), s(n);
    rep(i, n) cin >> f[i] >> s[i];

    vector<int> fakers, good;
    {
        vector<string> ff, ss;
        ff = f;
        ss = s;
        sort(all(ff));
        sort(all(ss));
        rep(i, n) {
            if(upper_bound(all(ff), f[i]) - lower_bound(all(ff), f[i]) > 1) {
                if(upper_bound(all(ss), s[i]) - lower_bound(all(ss), s[i]) > 1) {
                    fakers.push_back(i);
                    goto FAKE;
                }
            }
            good.push_back(i);
      FAKE:;
        }
    }
    int ans = 0;
    {
        set<string> ff, ss;
        for(int i : good) {
            ff.insert(f[i]);
            ss.insert(s[i]);
        }

        while(fakers.size()) {
            rep(i, fakers.size()) {
                int idx = fakers[i];
                if(ff.count(f[idx]) and ss.count(s[idx])) {
                    ans++;
                    fakers.erase(fakers.begin() + i);
                    i--;
                }
            }
            if(fakers.size()) {
                cerr << "Case left : " << case_cnt << endl;
                int i = fakers.back(); fakers.pop_back();
                ff.insert(f[i]);
                ss.insert(s[i]);
            }
        }
    }
    cout << "Case #" << case_cnt << ": " << ans << endl;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    int T; cin >> T;
    int C = 1;
    while(C <= T) solve(C++);
    return 0;
}
