#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<string>
#include<cmath>
#include<cassert>
#include<map>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef int int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<int> H(N+1);
    bool is_inc=false;
    int ans=0;
    int s=0,t=0,u=0;
    enum {NO,INC,DEC};
    int state=NO;
    H[0]=0;
    
    repeat(i, 1, N+1){
        cin>>H[i];
        if(H[i]>H[i-1]){
            if(state == DEC){
                u=i-1;
                ans=max(ans,u-s+1);
            }
            if(state != INC){
                s=max(1,i-1);
            }
            state=INC;
        }else if(H[i]<H[i-1]){
            if(state == INC){
                t=i-1;
            }else if(state == NO){
                s=t=i-1;
            }
            state=DEC;
        }else{
            if(state==DEC){
                u=i-1;
                ans=max(ans,u-s+1);
            }
            state=NO;
        }
    }

    if(state == INC || state == DEC){
        ans=max(ans,N-s+1);
    }

    cout<<ans<<endl;
    return 0;
}
