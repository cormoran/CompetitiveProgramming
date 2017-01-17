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
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : ""); return os;
}

template<typename T>
istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}



bool solve(){
    int N; cin >> N;
    N *= 2;
    vector<int> A(N); cin >> A;
    vector<vector<int>> cnt(100);
    rep(i, N) cnt[A[i]].push_back(i);
    
    vector<int> heap(N);
    int pair_num = 0;
    rep(i, 100){
        if(cnt[i].size() >= 2){
            int a = cnt[i][0];
            int b = cnt[i][1];
            heap[a] = 1;
            heap[b] = 2;            
            pair_num++;
        }
    }

    int one_num = count_if( all(cnt), [](const vector<int> &v){ return (int)v.size() == 1;});
    
    int one_first = one_num / 2;
    int one_second = one_num - one_first;

    int t = 0;
    rep(i, 100){
        if(cnt[i].size() == 1){
            heap[cnt[i][0]] = t < one_first ? 1 : 2;
            t++;
        }
    }
    int left = N / 2 - pair_num - one_first;
    rep(i, N){
        if(heap[i] == 0){
            heap[i] = left-- > 0 ? 1 : 2;
        }
    }
    
    cout << (one_first + pair_num) * (one_second + pair_num) << endl;
    cout << heap << endl;
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
