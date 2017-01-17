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
istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}


bool findString(string &s, int &pos, const string &tgt){
    int i = 0;
    while(pos < (int)s.size() and i < (int)tgt.size()){
        if(s[pos] == tgt[i]) i++;
        pos++;
    }
    return i == (int)tgt.size();
}


bool solve(){
    int N; cin >> N;
    vector<string> S(N); cin >> S;
    string A; cin >> A;
    S.push_back("");
    int pos = 0;
    rep(i, S.size()){
        if(not findString(A, pos, "<3") or not findString(A, pos, S[i])){
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

