//  codeforces -  - A  / 2016-02-11
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


template<typename T>
T gcd(T a,T b){
    T c=a,d=b,r;
    do{r=c%d;c=d;d=r;}while(r);
    return c;
}

template<typename T>
T lcm(T a,T b){return a*b/gcd(a,b);}

bool solve(){
    int n; cin >> n;

    vector<int> cnt(8,0);
    rep(i,n){
        int tmp; cin >> tmp;
        cnt[tmp]++;
    }
    bool flg = true;

    if(cnt[7] or cnt[5]) flg = false;
    cnt[2] -= cnt[4];
    cnt[1] -= cnt[4];
    if(cnt[2] < 0 or cnt[1] <0) flg = false;
    if(flg and cnt[6] == cnt[2]+cnt[3] and cnt[6] == cnt[1]){
        rep(i,cnt[4]) puts("1 2 4");
        rep(i,cnt[6]){
            printf("1 %d 6\n", cnt[3]-->0 ? 3 : 2);
        }
    } else {
        cout << -1 <<endl;
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
