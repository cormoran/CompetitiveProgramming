#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R>
void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}


bool cmp(const string &s,int i,const string &ss){
    int j=0;
    for(;i<(int)s.size() and j<(int)ss.size();){
        if(s[i] != ss[j])return false;
        i++;j++;
    }
    return j==ss.size();
}

bool solve(){
    string S;cin>>S;
    int n =S.size();
    reverse(all(S));

    while(1){
        int i=0;
        bool flg=false;
        while(i<(int)S.size()){

            if(cmp(S,i,"--")){
                debug(": --");
                flg=true;
                S.erase(i,2);
            }
            else if(cmp(S,i,"!!!")){
                debug(": !!!");
                flg=true;
                S.erase(i+1,2);
            }
            else if(cmp(S,i,"-!")){
                debug(": -!");
                flg=true;
                S.erase(i,1);
            }
            else{
                i++;
            }
        }
        if(!flg)break;
    }
    reverse(all(S));
    cout << S <<endl;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
