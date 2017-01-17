//  atcoder-CodeFestival-2015-Thanks-D  / 2015-12-05
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

struct Student{
    int p;
    int knowsum;
    set<int> knows;
};

bool solve(){
    int n; cin >> n;
    int sum = 0;
    vector<Student> s(n);
    rep(i,n){
        cin >> s[i].p;
        sum += s[i].p;
        s[i].knowsum = s[i].p;
        s[i].knows.insert(i);
    }
    int m; cin >> m;
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        b--;c--;
        if(a == 0){
            s[b].knows.insert(c);
            s[b].knowsum += s[c].p;
        } else {
            if(s[b].knows.count(c)){
                printf("%d %d\n",s[c].p,s[c].p);
            } else {
                int left = sum - s[b].knowsum;
                int unknown = n - s[b].knows.size() -1;
                printf("%d %d\n",
                       max(0, left - 100 * unknown),
                       min(100, left));
            }
        }
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
