#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()
const int INF=1<<30;

class Segment_Tree{
  public:
    int n;
    vector<int> data;

    Segment_Tree(int n_){
        n=1;
        while(n<n_)n*=2;
        data.resize(2*n-1,0);
    }

    void update(int k,int a){
        k+=n-1;
        data[k]=a;
        while(k>0){
            k=(k-1)/2;
            data[k]=max(data[k*2+1],data[k*2+2]);
        }
    }

    int query(int a,int b){
        return search(a,b+1,0,0,n);
    }
  private:
    int search(int a,int b,int k,int l,int r){
        if(r<=a||b<=l)return 0;
        if(a<=l&&r<=b)return data[k];
        else {
            int vl=search(a,b,k*2+1,l,(l+r)/2);
            int vr=search(a,b,k*2+2,(l+r)/2,r);
            return max(vl,vr);
        }
    }

};

bool solve(){
    int N;cin>>N;
    vector<int> S(N),T(N);
    vector<int> line(100010);
    Segment_Tree st(line.size()+1);
    rep(i,N){
        cin>>S[i]>>T[i];
        line[S[i]]++;
        line[T[i]]--;
    }
    rep(i,line.size()){
        if(i==0)continue;
        line[i]+=line[i-1];
        st.update(i, line[i]);
    }

    int ans=INF;
    rep(i,N){
        int m = st.query(S[i], T[i]-1) -1 ;
        int l = st.query(0, S[i]-1) ;
        int r = st.query(T[i], 100000) ;
        ans = min(ans,max(max(l,r),m));
    }
    cout <<ans<<endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
