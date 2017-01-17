#include<cstdio>
#include<iostream>
int main (){
  int n;
  int h,m,s;

  std::cin>>n;
  h=n/(60*60);
  m=(n-h*60*60)/60;
  s=n-h*60*60-m*60;
  printf("%02d:%02d:%02d\n",h,m,s);
  return 0;
}
