#include<iostream>
using namespace std;

bool solve(){
    int l = 1, r = 1e9+1;
    while(l+1 < r){
        int m = (l + r) / 2;
        cout << "? " << m << endl;
        cout.flush();
        int a; cin >> a;
        if(a == 1) l = m;
        else r = m;
    }
    cout << "! " << l << endl;
    cout.flush();
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
