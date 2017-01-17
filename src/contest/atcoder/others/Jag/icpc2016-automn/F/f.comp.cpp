//#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<functional>

using namespace std;

#define rep(i, j) for(int i = 0; i < (j); i++)
#define repeat(i, j, k) for(int i = j; i < (k); i++)
using ll = long long;
using pii = pair<int, int>;
const int INF = 1 << 30;

int N, L; 
vector<int> A, B;
vector<pii> AB;
vector<ll> ABsum;

int main() {
    cin >> N >> L;
    A.resize(N);
    B.resize(N);
    AB.resize(N);
    
    rep(i, N) {
        cin >> A[i] >> B[i];
        AB[i] = make_pair(A[i] - B[i], i);
    }
    
    sort(AB.begin(), AB.end(), greater<pii>());
    ABsum.resize(N);

    rep(i, N) {
        if(i == 0) ABsum[i] = AB[0].first;
        else ABsum[i] = ABsum[i - 1] + AB[i].first;
    }
        
    vector<ll> Csum(N);
    rep(i, N) {
        int c; cin >> c;
        if(i == 0) Csum[i] = c;
        else Csum[i] = Csum[i - 1] + c;
    }

    int ans = INF;
    int day = 0;

    vector<int> escape(N);
    
    rep(i, N) { // 前からi 番目のドリンクを最後に使う
        int drink = AB[i].second;
        bool flg = false;
        while(day < N - 1) {
            ll height;
            if(day < i) height = ABsum[day];
            if(day >= i) height = ABsum[day + 1] - AB[i].first;

            if(Csum[day] >= height) {
                escape[i] = day - 1;
                flg = true;
                break;
            }
            day++;
        }
        if(!flg) escape[i] = N - 1;
    }

    rep(i, N) cerr << escape[i] << " ";
    cerr << endl;

    rep(i, N) {
        cerr << i << endl;
        if(escape[i] < 0) continue;
        int drink = AB[i].second;            
        { // ゴール前日を探す(day < i)
            ll need = L - A[drink];
            
            if(i > 0 and ABsum[min(i - 1, escape[i])] >= need) {
                int l = -1, r = min(i - 1, escape[i]); // (l, r]
                while(l + 1 < r) {
                    int m = (l + r) / 2;
                    if(ABsum[m] < need) l = m;
                    else r = m;
                }
                r++; // +1 day
                if(ans > r) {
                    cerr << "day < i binsearch : " << r << endl;
                    ans = r;
                }
            }
        }
        { // ゴールする日を探す(day >= i)
            ll need = L - A[drink] + AB[i].first;
            if(escape[i] > i - 1 and ABsum[escape[i]] >= need) {
                int l = i - 1, r = escape[i];
                while(l + 1 < r) {
                    int m = (l + r) / 2;
                    if(ABsum[m] < need) l = m;
                    else r = m;
                }
                cerr << "day >= i binsearch : " << r << endl;
                if(ans > r) {                    
                    ans = r;
                }
            }
        }
    }

    if(ans >= INF) ans = -2;
    cout << ans + 1 << endl;

    return 0;
}
