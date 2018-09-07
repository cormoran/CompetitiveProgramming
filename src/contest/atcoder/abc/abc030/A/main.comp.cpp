/**
 * file   : A.cpp
 * date   : 2015-10-24
 */

#include<iostream>
using namespace std;
int main()
{
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    cout << (B*C==D*A ? "DRAW" : (B*C>D*A ? "TAKAHASHI" : "AOKI")) <<endl;
    return 0;
}
