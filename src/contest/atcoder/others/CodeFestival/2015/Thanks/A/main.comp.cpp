//  atcoder-CodeFestival-2015-Thanks-A  / 2015-12-05
#include<iostream>
using namespace std;
bool solve(){
    int n,m; cin >> n >> m;
    int ans = 0;
    ans += abs(n - 0);
    ans += abs(m - n);
    ans += abs(0 - m);
    cout << ans <<endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
