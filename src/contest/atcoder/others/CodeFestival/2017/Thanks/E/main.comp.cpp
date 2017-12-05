#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
template<class T> ostream&
operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << " " << t; return os << endl; }

int main() {
    int N; cin >> N;
    
    vector<int> ans(N);
    for(int i = 0; i < N; i += 5) {
        vector<int> s(N);
        ll sum_num = 0;
        rep(j, 5) if(i + j < N) {
            s[i + j] = pow(10, j);
            sum_num += s[i + j];
        }
        cout << "?" << s;
        
        ll sum_w; cin >> sum_w;
        sum_w -= sum_num * 7;
        rep(j, 5) if(i + j < N) {
            ans[i + j] = sum_w % 2 == 0;
            sum_w /= 10;                     
        }
    }
    cout << "!" << ans << endl;
    return 0;
}
