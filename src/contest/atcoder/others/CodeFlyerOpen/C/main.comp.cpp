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

using Index = int;
template<typename Data>
class RangeQuery{
  public:
    int n;
    vector<Data> data;
    function< Data(Data,Data) > selector;
    Data default_val;

    RangeQuery(int n, function< Data(Data,Data) > selector,Data default_val)
            :selector(selector),default_val(default_val){
        this->n = 1;
        while(this->n < n) this->n *= 2;
        data.resize(2*(this->n)-1, default_val);
    }

    //index k(=0,1,2...)の値をaにする。
    void update(Index k,Data val){
        assert(0<=k and k<n);
        k += n-1;
        data[k] = val;
        while( k > 0 ){
            k = (k-1)/2; //親
            data[k] = selector(data[k*2+1], data[k*2+2]);
        }
    }

    // [a,b] のクエリ b<n
    int query(Index a,Index b){
        assert(0<=a and b<n);
        return search(a,b+1,0,0,n);
    }
  private:
    //[a,b)の最小値,kは今の場所,[l,r)はkの守備範囲
    Data search(Index a,Index b,Index k,Index l,Index r){
        if( r <= a or b <= l ) return default_val;      // 範囲からずれた
        if( a <= l and r <= b ) return data[k]; // 目的範囲より狭くなった
        else {
            //左の子側の範囲
            Data vl = search(a, b, k*2+1, l, (l+r)/2);
            //右の子側の範囲
            Data vr = search(a, b, k*2+2, (l+r)/2, r);
            return selector(vl, vr);
        }
    }

};

template<typename Data>
class RangeMinimumQuery : public RangeQuery<Data>{
  public:
    RangeMinimumQuery(int n){super(n,[](Data a,Data b){min(a,b);},INF);}
};

template<typename Data>
class RangeMaximumQuery : public RangeQuery<Data>{
  public:
    RangeMaximumQuery(int n){super(n,[](Data a,Data b){max(a,b);},-INF);}
};

class Solver {
  public:
    ll parse(const string &S, int pos) {

    }
    bool solve() {
        string S; cin >> S;


        list<char> S;
        {
            string s_in; cin >> s_in;
            S.push_back('[');
            for(char c : s_in) S.push_back(c);
            S.push_back(']');
        }
        ll ans = 0;
        unordered_map<list<char>::iterator, int, ListIteratorHash> n_map;
        vector<list<char>::iterator> o_pos;
        for(auto itr = S.begin(); itr != end(S); itr++) {
            auto nxt_itr = itr; nxt_itr++;
            if(nxt_itr != end(S) and *itr == '(' and *nxt_itr == ')') {
                *itr = 'o';
                S.erase(nxt_itr);
                ans++;
                o_pos.push_back(itr);
                n_map[itr] = 1;
            }
        }
        // debug(list_to_str(S));
        unordered_set<list<char>::iterator, ListIteratorHash> removed;
        while(o_pos.size() > 0) {
            bool updated = false;
            auto nxt_o_pos = decltype(o_pos)();
            for(auto itr : o_pos) {
                if(removed.count(itr)) continue;
                if(!(*itr == 'o')){
                    // debug(list_to_str(S));
                    // debug(*itr);
                    assert(false);
                }
                ll n = n_map.count(itr) ? n_map[itr] : 1, n2 = 1;
                auto l_itr = itr, r_itr = itr; r_itr++;
                while(*l_itr != '[' and *l_itr == 'o') {
                    if(n_map.count(l_itr)) n += n_map[l_itr];
                    else n++;
                    n2++;
                    l_itr--;
                }
                if(*l_itr != 'o') { l_itr++; n -= n_map[l_itr]; n2--; } // 戻す
                while(*r_itr != ']' and *r_itr == 'o') {
                    if(n_map.count(r_itr)) n += n_map[r_itr];
                    else n++;
                    n2++;
                    r_itr++;
                }
                // [l_itr, r_itr)
                bool squashed = false;
                { // 潰す？
                    auto ll_itr = l_itr; ll_itr--;
                    auto rr_itr = l_itr; rr_itr++;
                    if(l_itr != begin(S) and rr_itr != end(S)) {
                        if(*ll_itr == '(' and *rr_itr == ')') {
                            // cerr << "squash " << list_to_str(S) << " from " << *ll_itr << " to " << *rr_itr << endl;
                            squashed = true;
                            rr_itr++;
                            for(auto itr = l_itr; itr != rr_itr; itr++) removed.insert(itr);
                            S.erase(l_itr, rr_itr);
                            ans += n * (n - 1) / 2;
                            n_map[ll_itr] = 1;
                            *ll_itr = 'o';
                            nxt_o_pos.push_back(ll_itr);
                            updated = true;
                            ans++;
                            // cerr << " after " << list_to_str(S) << endl;
                        }
                    }
                }
                if(not squashed) {
                    // cerr << "summarize " << list_to_str(S) << " from " << *l_itr << " to " << *r_itr << endl;
                    // cerr << n2 << " , " << n << endl;
                    n_map[l_itr] = n;
                    nxt_o_pos.push_back(l_itr);
                    l_itr++;
                    for(auto itr = l_itr; itr != r_itr; itr++) removed.insert(itr);
                    S.erase(l_itr, r_itr);
                    if(n2 > 1) updated = true;
                }
            }
            swap(o_pos, nxt_o_pos);
            // debug(list_to_str(S));

            if(not updated) break;
        }
        // debug(ans);
        for(auto itr : o_pos) {
            if(removed.count(itr)) continue;
            ll n = n_map[itr];
            ans += n * (n - 1) / 2;
        }
        cout << ans << endl;
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
