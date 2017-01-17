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


bool solve(){
    int N; cin >> N;
    vector<int> u(N), l(N);
    rep(i, N) cin >> u[i] >> l[i];
    bool is_even_u = accumulate(all(u), 0) %2 == 0;
    bool is_even_l = accumulate(all(l), 0) %2 == 0;

    if(is_even_l and is_even_u){
        cout << 0 << endl;
        return 0;
    } else if(not (is_even_u or  is_even_l) ){
        auto check = [](int a, int b){
            return (a % 2 == 1 and  b % 2 == 0) or (b % 2 == 1 and a % 2 == 0);
        };
        rep(i, N){
            if( check(u[i], l[i]) ){
                cout << 1 << endl;
                return 0;
            }
            rep(j, i){
                int uu = u[i] + u[j];
                int ll = l[i] + l[j];
                if( check(uu, ll) ){
                    cout << 2 << endl;
                    return 0;
                }   
            }
        }
        cout << -1 << endl;
    } else {
        cout << -1 << endl;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
