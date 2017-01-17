#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;

#define rep(i,j) for(int i=0;i<(j);i++)

int main()
{
  double H,B;
  cin>>H>>B;

  printf("%.10f\n",B*H*H/10000);

  
  return 0;
}
