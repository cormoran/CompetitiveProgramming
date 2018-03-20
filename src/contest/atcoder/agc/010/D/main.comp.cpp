#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
template<class T> istream&
operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

template<typename T>
T gcd(T a,T b){
    T c=a,d=b,r;
    do{r=c%d;c=d;d=r;}while(r);
    return c;
}

bool does_win_first(vector<int> &A) {
    ll sum = accumulate(all(A), 0ll) - A.size();
    
    if(sum % 2 == 1) return true;
    
    vector<int> odd_indices;
    rep(i, A.size()) if(A[i] % 2) odd_indices.push_back(i);
    
    if(odd_indices.size() == 1 and A[odd_indices[0]] > 1) {
        A[odd_indices[0]]--;
        ll g = accumulate(all(A), A[0], gcd<ll>);
        rep(i, A.size()) A[i] /= g;
        return not does_win_first(A);
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<int> A(N); cin >> A;

    cout << (does_win_first(A) ? "First" : "Second") << endl;
    
    return 0;
}
