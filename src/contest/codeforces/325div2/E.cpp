//#include<bits/stdc++.h>
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
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

int main()
{
    char A='A';
    char B='B';
    ll X,Y;
    cin>>X>>Y;

    if(X==1){
        cout<<Y-1<<B<<endl;
    }
    else if(Y==1){
        cout<<X-1<<A<<endl;
    }else{
        if(X<Y){
            swap(X,Y);
            swap(A,B);
        }
        ll l = Y-1;
        if((X-1)%Y==0){
            ll k = (X-1)/Y;
            cout << k<<A<<l<<B<<endl;
        }else{
            cout << "Impossible" << endl;
        }
    }
    


    
    return 0;
}
