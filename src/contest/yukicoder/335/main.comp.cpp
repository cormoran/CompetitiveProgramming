#include<iostream>
#include<vector>
#include<cassert>
#include<functional>
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


typedef int Index;
const int INF = 1 << 30;
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
    void update(const vector<Data> &v){
        assert(v.size() <= n);
        rep(i,v.size()) update(i,v[i]);
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
    // [a,b) のクエリ b<=n
    int query(Index a,Index b){
        assert(0<=a and b<=n);
        return search(a,b,0,0,n);
    }
  private:
    Data search(Index a,Index b,Index k,Index l,Index r){
        if( r <= a or b <= l ) return default_val;
        if( a <= l and r <= b ) return data[k];
        else {
            Data vl = search(a, b, k*2+1, l, (l+r)/2);
            Data vr = search(a, b, k*2+2, (l+r)/2, r);
            return selector(vl, vr);
        }
    }
};

bool is_matu(int a, int b, int c){
    if(a == b or a == c or b == c) return false;
    return not (a < b and b < c) and not (c < b and b < a);
}

int max(int a, int b, int c,int d){
    return max(a, max(b,max(c, d)));
}

ll value_sum(vector<int> E){
    int N = E.size();
    RangeQuery<int> rminq = RangeQuery<int>(N,[](int a,int b){return min(a,b);},INF);
    RangeQuery<int> rmaxq = RangeQuery<int>(N,[](int a,int b){return max(a,b);},-INF);
    rep(i,N){
        rminq.update(i,E[i]);
        rmaxq.update(i,E[i]);
    }
    
    ll sum = 0;
    rep(i,N){
        rep(j,i){
            int max_value = 0;
            if( 0 < j ){
                int b = E[j], c = E[i];
                int max_a = rmaxq.query(0, j);
                int min_a = rminq.query(0, j);
                if( is_matu(max_a, b, c) ) max_value = max(max_a, b, c, max_value);
                if( is_matu(min_a, b, c) ) max_value = max(min_a, b, c, max_value);
            }
            if( j +1 < i ){
                int a = E[j], c = E[i];
                int max_b = rmaxq.query(j+1, i);
                int min_b = rminq.query(j+1, i);
                if( is_matu(a, max_b, c) ) max_value = max(a, max_b, c, max_value);
                if( is_matu(a, min_b, c) ) max_value = max(a, min_b, c, max_value);
            }
            if(i + 1 < N){
                int a = E[j], b = E[i];
                int max_c = rmaxq.query(i+1, N);
                int min_c = rminq.query(i+1, N);
                if( is_matu(a, b, max_c) ) max_value = max(a, b, max_c, max_value);
                if( is_matu(a, b, min_c) ) max_value = max(a, b, min_c, max_value);
            }
            sum += max_value;
        }
    }
    return sum;
}

bool solve(){
    int N,M; cin >> N >> M;
    vector<vector<int>> E(M, vector<int>(N));
    rep(i,M) cin >> E[i];
    
    int ans;
    ll max_sum = -1;
    rep(i,M){
        ll tmp = value_sum(E[i]);
        if(tmp > max_sum){
            ans = i;
            max_sum = tmp;
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
