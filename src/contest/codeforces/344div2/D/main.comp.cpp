//  codeforces -  - D  / 2016-03-04
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

vector<int> buildFail(const vector<pair<ll,char>> &p) {
    int m = p.size();
    vector<int> fail(m+1);
    int j = fail[0] = -1;
    for (int i = 1; i <= m; ++i) {
        while (j >= 0 && p[j] != p[i-1]) j = fail[j];
        fail[i] = ++j;
    }
    return fail;
}

vector<int> match(const vector<pair<ll,char>> &t, const vector<pair<ll,char>> &p, const vector<int> &fail) {
    int n = t.size(), m = p.size();
    vector<int> ret;
    for (int i = 0, k = 0; i < n; ++i) {
        while (k >= 0 && p[k] != t[i]) k = fail[k];
        if (++k >= m) {
            ret.push_back(i-m+1);
            k = fail[k];
        }
    }
    return ret;
}

bool solve(){
    int n, m; cin >> n >> m;
    vector<pair<ll,char>> src, tgt;
    src.reserve(n);
    tgt.reserve(m);

    rep(i, n){
        string s; cin >> s;
        char c = s.back();
        s[s.size()-2] = '\0';
        ll k = atoi(s.c_str());
        if(src.size() > 0 and src.back().second == c){
            src.back().first += k;
        } else{
            src.push_back(make_pair(k, c));
        }
    }
    rep(i, m){
        string s; cin >> s;
        char c = s.back();
        s[s.size()-2] = '\0';
        ll k = atoi(s.c_str());
        if(tgt.size() > 0 and tgt.back().second == c){
            tgt.back().first += k;
        } else{
            tgt.push_back(make_pair(k, c));
        }
    }

    // rep(i, src.size()){
    //     cerr << src[i].first << "-" << src[i].second << " ";
    // }
    // cerr << endl;
    // rep(i, tgt.size()){
    //     cerr << tgt[i].first << "-" << tgt[i].second << " ";
    // }
    
    
    ll ans = 0;
    if(tgt.size() == 1){
        char c = tgt[0].second;
        ll num = tgt[0].first;
        rep(i, src.size()){
            if(src[i].second == c){
                ans += max(0LL, src[i].first - (num -1));
            }
        }
        // linear
    } else if(tgt.size() == 2){
        rep(i, src.size() - 1){
            if( src[i].second == tgt[0].second and
                src[i].first >= tgt[0].first ){ 
                if( src[i+1].second == tgt[1].second and
                    src[i+1].first >= tgt[1].first){
                    ans++;
                }
            }
        }
    } else {
        vector<pair<ll,char>> tgt2(tgt.size() -2);
        rep(i, tgt2.size()) tgt2[i] = tgt[i+1];
        
        vector<int> fail = buildFail(tgt2);
        vector<int> matches = match(src, tgt2, fail);
        
        //debug("match", matches.size());
        
        for(int i : matches){
            if(i > 0 and i + tgt2.size() - 1 + 1 < src.size()){
                if( src[i-1].second == tgt[0].second and
                    src[i-1].first >= tgt[0].first ){ 
                    if( src[i+tgt2.size()].second == tgt.back().second and
                        src[i+tgt2.size()].first >= tgt.back().first){
                        ans++;
                    }
                }   
            }
        }
        
    }
    
    cout << ans << endl;
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
