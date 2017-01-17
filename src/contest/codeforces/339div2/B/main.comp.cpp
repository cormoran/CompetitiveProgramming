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


bool solve(){
    int n; cin >> n;
    vector<string> S(n); cin >> S;
    string ans = "";
    bool f = false;
    for(string& s : S){
        if(s == "0"){
            cout << "0" <<endl;
            return false;
        }
        bool flg = false;
        bool one = false;
        rep(i,s.size()){
            if(s[i] == '1'){
                if(one){
                    flg = true;
                    break;
                }
                one = true;
            }
            if(s[i] != '1' and s[i] != '0'){
                flg = true;
                break;
            }
        }
        if(not flg){
            rep(i,s.size()-1){
                ans += '0';
            }
        } else {
            assert(not f);
            ans = s + ans;
            f = true;
        }
    }
    if(not f) ans = '1' + ans;
    cout << ans <<endl;
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
