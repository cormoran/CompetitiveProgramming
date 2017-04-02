#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl

template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "<" << v.first << ", " << v.second << ">"; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;


class Solver {
  public:
    int N;
    vector<int> L, R;
    vector<pii> calc_up_regions() {
        vector<pii> ret;
        rep(i, N) {
            if(L[i] < R[i]) {
                ret.push_back(make_pair(L[i], R[i]));
            }
        }
        sort(all(ret));
        if(ret.size() == 0) return {};

        vector<pii> ret2;
        pii a = ret.front();
        int i = 0;
        while(++i < ret.size()) {
            if(a.second >= ret[i].first) {
                set_max(a.second, ret[i].second);
            } else {
                ret2.push_back(a);
                a = ret[i];
            }
        }
        ret2.push_back(a);
        sort(all(ret2), greater<pii>());
        return ret2;
    }


    struct Regin {
        vector<pii> downregions;
        pii upregion;
        int ok_regin = 0;
    };

    vector<Regin> divide() {
        vector<pii> up_regions = calc_up_regions();
        vector<Regin> ret;

        pii prev_region = make_pair(1e9 + 10, 1e9 + 9);
        debug(up_regions);
        for(auto now_regin : up_regions) {
            Regin r;
            r.upregion = now_regin;
            rep(j, N) {
                if(L[j] >= R[j]) {
                    if(now_regin.second >= L[j] and R[j] >= now_regin.first) {
                        r.ok_regin++;
                    }
                    else if(prev_region.second >= L[j] and prev_region.first > R[j] and R[j] >= now_regin.first) {
                        r.downregions.push_back(make_pair(L[j], R[j]));
                    }
                }
            }
            prev_region = now_regin;
            ret.push_back(r);
        }
        return ret;
    }
    
    bool solve() {
        cin >> N;
        L.resize(N); cin >> L;
        R.resize(N); cin >> R;

        auto ret = divide();

        for(auto a : ret) {
            cerr << a.upregion << endl;
            cerr << "d ";
            cerr << a.downregions << endl;
        }
        
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Solver s;
    s.solve();
    return 0;
}
