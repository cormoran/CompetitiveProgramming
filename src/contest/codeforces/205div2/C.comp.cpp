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


bool solve(){
    int N; cin >> N;
    vector<int> A(N); cin >>A;
    string s; cin >> s;
    vector<int> sum(N);
    vector<int> m_sum(N);
    sum[0] = A[0];
    m_sum[0] = s[0] == '1' ? A[0] : 0;
    repeat(i, 1, N){
        sum[i] = sum[i-1] + A[i];
        m_sum[i] = m_sum[i-1] + (s[i] == '1' ? A[i] : 0);
    }

    int ans = m_sum[N-1];
    for(int i = N-1; i >= 1; i--){
        if(s[i] == '1'){
            ans = max(sum[i-1], ans);
            ans = max(sum[i-1] + m_sum[N-1] - m_sum[i], ans);
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
