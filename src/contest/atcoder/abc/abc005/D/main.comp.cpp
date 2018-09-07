/*
  長方形を全探索
  O(N^4)
  N <= 50
 */

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef int int__;
#define rep(i,j) for(int__ i=0;i<(int)(j);(i)++)
#define rep_eq(i,j) for(int__ i=0;i<=(int)(j);(i)++)

int main()
{
    int N;
    cin>>N;
    vector<vector<int>> D(N,vector<int>(N,0)); // 累積和化
    rep(y,N){
        rep(x,N){
            int d ;cin>>d;
            D[y][x] += d;
            if(x+1<N)D[y][x+1] += D[y][x];
            if(y>0)D[y][x]+=D[y-1][x];
        }
    }
    
    vector<int> count(N*N+1,0);

    rep(ye,N){
        rep_eq(ys,ye){
            int h = ye - ys +1;
            rep(xe,N){
                rep_eq(xs,xe){
                    int w = xe - xs +1;
                    int sum = D[ye][xe];
                    if(xs>0)sum -= D[ye][xs-1];
                    if(ys>0)sum -= D[ys-1][xe];
                    if(xs>0 && ys >0) sum += D[ys-1][xs-1];
                    
                    //printf("D (%d,%d) -> (%d,%d) : %d\n",xs,xe,ys,ye,sum);
                    
                    count[h*w] = max(count[h*w],sum);
                }
            }
        }
    }

    rep(i,count.size()){
        if(i>0)
            count[i]=max(count[i-1],count[i]);
    }

    
    int Q;
    cin>>Q;

    rep(i,Q){
        int P;
        cin>>P;
        cout << count[P] <<endl;
    }
    
    
    
    return 0;
}
