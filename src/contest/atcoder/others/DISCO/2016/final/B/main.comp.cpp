#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cmath>
#include<tuple>
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


#include<functional>
using Index = int;
template<typename Data>
class SegmentTree{
  public:
    int n;
    vector<Data> data;
    function< Data(Data,Data) > selector;
    Data default_val;
    
    SegmentTree(int n, function< Data(Data,Data) > selector,Data default_val)
            :selector(selector),default_val(default_val){
        this->n = 1;
        while(this->n < n) this->n *= 2;
        data.resize(2*(this->n)-1, default_val);
    }
    void update(Index k,Data val){
        k += n-1;
        data[k] = val;
        while( k > 0 ){
            k = (k-1)/2; //親
            data[k] = selector(data[k*2+1], data[k*2+2]);
        }
    }
    int query(Index a,Index b){
        return search(a,b+1,0,0,n);
    }
  private:
    Data search(Index a,Index b,Index k,Index l,Index r){
        if( r <= a or b <= l ) return default_val;      // 範囲からずれた
        if( a <= l and r <= b ) return data[k]; // 目的範囲より狭くなった
        else {
            Data vl = search(a, b, k*2+1, l, (l+r)/2);
            Data vr = search(a, b, k*2+2, (l+r)/2, r);
            return selector(vl, vr);
        }
    }

};

const int INF = 1 << 30;

bool solve(){
    int n,x; cin >> n >> x;
    vector<pair<pair<int,int>,int>> A(n);
    rep(i, n){
        cin >> A[i].first.second;
        A[i].first.second = -1 * min(A[i].first.second, n);
    }
    rep(i,n){
        cin >> A[i].first.first;
        A[i].second = i;
    }
    sort( all(A) ,greater<pair<pair<int,int>,int>>());
    vector<bool> used_time(n);
    SegmentTree<int> jump_to(n,[](const int a,const int b){return min(a,b);}, INF);
    ll sum = 0;
    ll ans = 0;
    rep(i,n){
        int t = A[i].first.second * -1 - 1;
        while(t >= 0){
            if(not used_time[t]){
                sum += A[i].first.first;
                ans++;
                if(sum >= x){
                    cout << ans << endl;
                    return 0;
                }
                used_time[t] = true;
                break;
            } else {
                int k = t;
                while( t >= 0 and used_time[t]){
                    int nxt = jump_to.query(t,n-1);
                    if(nxt != INF and nxt < t) t = nxt;
                    else t--;
                }
                jump_to.update(k, t);
            }
        }
    }
    cout << -1 << endl;
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
