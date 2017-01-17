#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<array>
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

bool solve(){
    int N; cin >> N;
    const int size = 100001;
    pair<int,int> mem[size];
    fill(mem, mem + size, make_pair(0, -1));
    vector<int> A(N); cin >> A;
    rep(i, N){
        int a = A[i];
        if(mem[a].first == 0) mem[a].second = i;
        else if(mem[a].first == 1){
            int d = i - mem[a].second;
            mem[a].second = d;
        } else {
            int d = mem[a].second;
            if(d > 0 and a != A[i-d]){
                mem[a].second = -1;
            }
        }
        mem[a].first++;
    }
    int cnt = 0;
    rep(i, size){
        if(mem[i].first > 0 and mem[i].second >= 0) cnt ++;
    }
    cout << cnt << endl;
    rep(i, size){
        if(mem[i].first > 0 and mem[i].second >= 0){
            cout << i << " " << (mem[i].first > 1 ? mem[i].second : 0) << endl; 
        }
    }
    
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
