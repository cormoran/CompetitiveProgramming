#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
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


bool check(int cand, vector<int> &A, int k) {
    for(int a : A) {
        int x = a / cand;
        if(x * cand < a - k) return false;
    }
    return true;
}

bool solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n); cin >> A;
    int mini = *min_element(all(A));
    int maxi = *max_element(all(A));
    if(maxi - mini <= k) {
        cout << mini << endl;
        return false;
    }
    int ans = 1;
    vector<bool> unable(mini + 1);
    repeat(i, 2, mini + 1) {
        if(unable[i]) continue;
        if(check(i, A, k)) {
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

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
