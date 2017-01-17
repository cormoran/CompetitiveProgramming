//  codeforces-334div2-A  / 2015-12-02
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


ll near(double d){
    double d1 = ceil(d),d2 = floor(d);
    if(abs(d1-d) < abs(d2-d))return d1;
    else return d2;
}

bool solve(){
    vector<int> m(5),w(5);
    int hs,hu;
    cin>>m>>w>>hs>>hu;
    double sum = 0;
    rep(i,5){
        int x = 500*(i+1);
        sum += max(0.3 * x , (1 - m[i]/250.0)*x-50.0*w[i]);
    }
    sum += hs * 100;
    sum -= hu *50;
    cout << near(sum) <<endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
