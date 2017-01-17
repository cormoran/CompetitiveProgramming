//  aoj-1345  / 2015-11-28
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
#define rep(i,j) for(int i=0 ;i<(j);i++)
#define repeat(i,j,k) for(int i=j ;i<(k);i++)
#define all(v) v.begin(),v.end()
int solve(vector<int> b,vector<int> t){
    if( accumulate(all(b),0) != accumulate(all(t),0)) return 1<<30;
    int ret = 0;
    rep(i,b.size()){
        repeat(j,i,b.size()){
            if(b[j] == t[i]){
                b.erase(b.begin()+j);
                b.insert(b.begin()+i,t[i]);
                ret += j-i;
                break;
            }
        }
    }
    return ret;
}

int main(){
    int n,m; cin >> n >> m;
    vector<int> b(n),p(m);
    rep(i,n) cin >> b[i];
    rep(i,m)cin>>p[i];
    vector<int> t[2];
    rep(i,2)t[i].resize(n,0);
    {
        int now =0;
        rep(i,m)rep(j,p[i]){
            if(i%2) t[0][now] = 1;
            else t[1][now] = 1;
            now++;
        }
    }

    cout << min(solve(b,t[0]),solve(b,t[1])) << endl;
    return 0;
}
