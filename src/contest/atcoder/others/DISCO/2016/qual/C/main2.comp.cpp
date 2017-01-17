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

#define MAX_N 10
int n,k;
int rank[MAX_N + 1];
int tmp[MAX_N+1];

bool compare_sa(int i, int j){
    if(rank[i] != rank[j]){
         return rank[i]<rank[j];
    } else {
        int ri = i + k <= n ? rank[i+k] : -1;
        int rj = j + k <= n ? rank[j+k] : -1;
        return ri<rj;
    }
}
void construct_sa(string S, int *sa){
    int n = S.size();
    for(int i=0;i<=n;i++){
        sa[i] = i;
        rank[i] = i < n ? S[i] : -1;
    }
    for(k=1;k<=n;k*=2){
        sort(sa,sa+n+1,compare_sa);
        tmp[sa[0]]=0;
        for(int i=1;i<=n;i++){
            tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1],sa[i])?1:0);
        }
        for(int i=0;i<=n;i++){
            rank[i]=tmp[i];
        }
    }
}

bool solve(){
    string S; cin >> S;
    int K; cin >> K;
    vector<int> num(S.size());
    rep(i,S.size()){
        if(i == 0) num[i] = (S[i] == 'a');
        else {
            num[i] = num[i-1] + (S[i] == 'a');
        }
    }

    int a_len = 1<<30;
    rep(i,S.size()){
        
    }
    
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
