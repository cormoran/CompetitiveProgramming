#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define all(v) v.begin(),v.end()
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) {
    for(T &a : v) is >> a; return is;
}

bool solve() {
    int N, K, T, U, V, L; cin >> N >> K >> T >> U >> V >> L;
    vector<int> D(N); cin >> D;
    sort(all(D));
    int carrot = 0;
    int left_time = 0;
    int high_speed_range = 0;
    int di = 0;
    rep(l, L) {
        if(di < N and D[di] == l) {
            if(carrot == K) left_time = T * V;
            else carrot++;
            di++;
        }
        if(carrot > 0 and left_time == 0) {
            carrot--;
            left_time = T * V;
        }

        high_speed_range += (left_time > 0);
        left_time = max(0, left_time - 1);
    }
    printf("%.10f\n", (double)(L - high_speed_range) / U + (double)(high_speed_range) / V);
    
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
