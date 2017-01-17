#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N,K;
    cin>>N>>K;
    vector<int> t(N+1,0);
    for(int i=1;i<=N;i++){
        cin>>t[i];
        t[i]+=t[i-1];
        if(i>=3 && t[i]-t[i-3]<K){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
