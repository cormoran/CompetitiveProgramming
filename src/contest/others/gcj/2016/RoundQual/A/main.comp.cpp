#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int solve(int n){
    if(n == 0) return -1;
    int bits = 0;
    ll  i;
    for(i = 1; __builtin_popcount(bits) < 10; i++) {
        ll nn = n * i;
        while(nn){
            bits |= 1 << (nn % 10);
            nn /= 10;
        }
    }
    return  (i-1) * n;
}

int main(){
    ios::sync_with_stdio(false);
    int T; cin >> T;
    int t = 1;
    while(t <= T) {
        int in; cin >> in;
        ll ret = solve(in);
        cout << "Case #" << t++ << ": ";
        if(ret < 0) cout << "INSOMNIA" << endl;
        else cout << ret << endl;
    }
    return 0;
}
