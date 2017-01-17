//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
int main()
{
  ll n;
  cin>>n;
  ll th=1;
  while(n%th==0)th*=3;
  cout<<n/th+1<<endl;
  return 0;
}
