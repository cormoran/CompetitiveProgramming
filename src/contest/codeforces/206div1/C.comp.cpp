#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>
istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}


bool check(int cand, vector<int> &C, int k, int n) {
    int num = 0;
    int imax = C.size() - 1;
    k = min(k, cand);
    for(int i = cand; i < (int)C.size(); i += cand) {
        num += C[min(i + k, imax)] - C[i - 1];
    }
    return num >= n;
}

bool solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n); cin >> A;
    int mini = *min_element(all(A));
    int maxi = *max_element(all(A));

    vector<int> C(maxi + 1); // C[i] : i以下の数の数
    rep(i, n) C[A[i]]++;
    rep(i, C.size() - 1) C[i+1] += C[i];
    
    int ans = 1;
    vector<bool> unable(mini + 1);
    repeat(i, 2, mini + 1) {
        if(unable[i]) continue;
        if(check(i, C, k, n)) {
            ans = i;            
        } else {
            for(int j = i; j <= mini; j += i) {
                unable[j] = true;
            }
        }
    }
    cout << ans << endl;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
