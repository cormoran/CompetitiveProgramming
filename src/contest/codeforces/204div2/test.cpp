

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;
int main(){
    int n; cin >> n;
    for(int i = 0; i < n;i++){
        float s; cin >> s;
        cout << s << endl;
        cout << scientific << setprecision(50) << s * 1000 << endl;
        cout << (int)(s*1000) << endl << endl;
        
    }
    return 0;
}
