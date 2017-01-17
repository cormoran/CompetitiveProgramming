//  codeforces -  - D  / 2016-02-14
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


bool solve(){
    int n; cin >> n;
    vector<int> a(n); cin >> a;
    vector<int> d1;
    vector<int> d2(5001,0); // |ai - aj| <= 5000 - 1
    vector<int> dsum(5001,0); // |ai - aj| <= 5000 - 1
    rep(i,n) rep(j,i){
        int tmp = abs(a[i]-a[j]);
        if(d2[tmp] == 0) d1.push_back(tmp);
        d2[tmp]++;
    }
    dsum[0] = d2[0];
    rep(i,dsum.size()-1){
        dsum[i+1] = d2[i+1];
        dsum[i+1] += dsum[i];
    }
    double ans = 0;
    rep(i,d1.size()){
        double sub = 0;
        rep(j,d1.size()){
            int andrew = d1[i] + d1[j];
            if(andrew < dsum.size()){
                sub += (double)(dsum.back() - dsum[andrew]) * d2[d1[i]] * d2[d1[j]];
            }
        }
        rep(i,3) sub /= n * (n-1)/2;
        ans += sub;
    }
    printf("%.10f\n", ans);
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
