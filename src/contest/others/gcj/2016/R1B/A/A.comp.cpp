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

const string numbers[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void dec(vector<int> &al, int num, int count) {
    for(char c : numbers[num]) {
        al[c - 'A'] -= count;
    }
}


bool solve(int C){
    string s; cin  >> s;
    vector<int> alpha_count('z' - 'a' + 1);
    rep(i, s.size()) alpha_count[s[i] - 'A']++;
    const char feature[] = {'Z', 0, 'W', 0, 'U', 0, 'X', 'S', 'G', 0};
    vector<int> num_count(10);
    
    rep(i, 10) {
        if(feature[i] == 0) continue;
        num_count[i] = alpha_count[feature[i] - 'A'];
        dec(alpha_count, i, num_count[i]);
    }
    num_count[3] = alpha_count['H' - 'A'];
    dec(alpha_count, 3, num_count[3]);
    
    num_count[5] = alpha_count['V' - 'A'];
    dec(alpha_count, 5, num_count[5]);

    num_count[1] = alpha_count['O' - 'A'];
    dec(alpha_count, 1, num_count[1]);
    
    num_count[9] = alpha_count['I' - 'A'];
    dec(alpha_count, 9, num_count[9]);

    cout << "Case #" << C << ": ";
    rep(i, 10) {
        rep(j, num_count[i]) cout << i;
    }
    cout << endl;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    int T; cin >> T;
    int C = 1;
    while(C <= T) solve(C++);
    return 0;
}
