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
#include<unistd.h>
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

// 11 
// inabameguru
// i a a e u u : 6
// n m b g r   : 5

// ni na ne nu 

const string MEGURU = "inabameguru";

const char vowel[] = {'a','i','u','e','o'};
bool is_vowel(char c){
    rep(i,5) if(c == vowel[i]) return true;
    return false;
}

string ans = "";
set<string> S;

bool make(string &s,unsigned int used,int left_vowel){
    int left = MEGURU.size() - __builtin_popcount(used);
    if(left_vowel*2 < left) return false;

    if(left == 0){
        if(is_vowel(s.back()) and not S.count(s)){
            ans = s;
            return true;
        }
        return false;
    }
    
    rep(i,MEGURU.size()){
        if(used & (1<<i)) continue;
        if(s.size() > 0 and
           not is_vowel(s.back()) and
           not is_vowel(MEGURU[i])) continue;
        s.push_back(MEGURU[i]);
        if( make( s, used | (1<<i) , left_vowel - (is_vowel(MEGURU[i])))){
             return true;
        }
        s.pop_back();
    }
    return false;
}

bool solve(){
    
    int N; cin >> N;
    rep(i,N){
        string s; cin >> s;
        S.insert(s);
    }
    string s = "";
    if( make(s,0,6) ){
        cout << ans <<endl;
    } else {
        cout << "NO" << endl;
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
