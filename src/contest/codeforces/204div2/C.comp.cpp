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

void update(double &a, double b){
    a =  abs(a) < abs(b) ? a : b;
}

bool solve(){
    int N; cin >> N;
    double sum = 0;
    int natural = 0;
    rep(i, 2*N){
        double a; cin >> a;        
        sum += a - (int)a;
        natural += a -(int)a == 0;
    }
    double d = sum - (N - (natural+1) / 2);

    if(natural % 2) update(d, d - 1);

    int left = min(natural / 2, N - (natural+1) / 2);

    rep(i, left){
        update(d, d + 1);
        update(d, d - 1);
    }
    
    printf("%.3f\n", abs(d));
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
