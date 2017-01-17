#include<iostream>
#include<string>
using namespace std;


void fail(){
    cout << -1 << endl;
    exit(0);
}

int main(){
    int N;string S;
    cin >> N >> S;
    if(N%2==0)fail();

    const pair<char,char> con[] = {{'b','b'},{'a','c'},{'c','a'}};
    auto st = begin(S);
    auto ed = end(S);
    ed--;
    int ans=0;
    int n = N/2;
    for(;n>=0;n--){
        if(*st==con[n%3].first and *ed==con[n%3].second){
            ++st;--ed;
            ++ans;
        }else{
            fail();
        }
    }

    cout << ans -1 << endl;
    
    return 0;
}
