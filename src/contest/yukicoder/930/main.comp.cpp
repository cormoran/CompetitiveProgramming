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

vector<int> memo(1<<13);
vector<pair<int,pair<int,int>>> first_hands;
bool is_matu(int a,int b,int c){
    if(a == b or a == c or b == c) return false;
    return not(a < b and b < c) and not(c < b and b < a);
}
int c = 0;
bool rec(const vector<int> &K, int used, bool first, bool first_hand){
    //cerr << c++ <<endl;
    if( memo[used] != -1 ) return memo[used];
    if( (int)__builtin_popcount(used) == (int)K.size() ){
        return memo[used] = ! first;
    }
    bool can_win_first = ! first;
    rep(i,K.size()){
        if(not( used & (1<<i))){
            used |= (1<<i);
            rep(j,i){
                if(not( used & (1<<j))){
                    used |= (1<<j);
                    rep(k,j){
                        if(not( used & (1<<k))){
                            used |= (1<<k);
                            if(is_matu(K[k],K[j],K[i])){
                                bool tmp = rec(K, used, !first, false);
                                if(first_hand and tmp) first_hands.push_back(
                                       make_pair(k, make_pair(j, i)) );
                                if(first) can_win_first |= tmp;
                                else can_win_first &= tmp;
                            }
                            used &= ~(1<<k);
                        }
                    }
                    used &= ~(1<<j);
                }
            }
            used &= ~(1<<i);
        }
    }
    return memo[used] = can_win_first;
}

void printbin(int b){
    vector<int> a;
    while(b){
        a.push_back(b & 1);
        b = b >> 1;
    }
    cout << a ;
}

const int INF = 1<<30;




bool solve(){
    int N; cin >> N;
    vector<int> K(N); cin >> K;
    fill(all(memo),-1);
    rec(K ,0 ,true ,true);


    // rep(i,first_hands.size()){
    //     printf("%d %d %d\n",
    //            first_hands[i].first ,
    //            first_hands[i].second.first,
    //            first_hands[i].second.second);
    // }
    
    if(first_hands.size() == 0){
        cout << -1 <<endl;
    } else {
        sort(all(first_hands));
        printf("%d %d %d\n",
               first_hands[0].first ,
               first_hands[0].second.first,
               first_hands[0].second.second);
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
