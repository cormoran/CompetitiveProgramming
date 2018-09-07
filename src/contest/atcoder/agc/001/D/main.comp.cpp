#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, k, j) for(int i=(k); i < (int)(j); i++)
template<class T> istream&
operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream&
operator << (ostream &os , vector<T> &v) { rep(i, v.size()) os << v[i] << (i + 1 < v.size() ? " " : ""); return os; }

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(M); cin >> A;
    vector<int> odd, even;
    for(int a : A) (a % 2 ? odd : even).push_back(a); 
    if(odd.size() > 2) {
        cout << "Impossible" << endl;
        return 0;
    }
    vector<int> ans_a;
    if(odd.size() >= 1) ans_a.push_back(odd[0]);
    for(int a : even) ans_a.push_back(a);
    if(odd.size() >= 2) ans_a.push_back(odd[1]);    
    cout << ans_a << endl;

    vector<int> ans_b;
    int sum = 0;

    if(ans_a[0] != 1) {
        ans_b.push_back(ans_a[0] - 1);
        sum += ans_b.back();
    }
    repeat(i, 1, ans_a.size() - 1) {
        ans_b.push_back(ans_a[i]);
        sum += ans_b.back();
    }
    if(ans_a.size() == 1) {
        ans_b.push_back(1);
        sum += 1;
    }
    if(sum < N) ans_b.push_back(N - sum);

    cout << ans_b.size() << endl;
    cout << ans_b << endl;
    return 0;
}
