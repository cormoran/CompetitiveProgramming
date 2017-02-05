#include<iostream>
#include<cstdio>
#include<limits>

using namespace std;

int main()
{
  printf("int size %ld bit\n",8*sizeof(int));
  printf("char size %ld bit\n",8*sizeof(char));
  printf("long size %ld bit\n",8*sizeof(long));
  printf("long long size %ld bit\n",8*sizeof(long long));
  puts("");
  
  printf("char min %d\n",CHAR_MIN);
  printf("char max %d\n",CHAR_MAX);


  printf("int min %d\n",INT_MIN);
  printf("int max %d\n",INT_MAX);


  printf("long min %ld\n",LONG_MIN);
  printf("long max %ld\n",LONG_MAX);
  
  printf("long long min %lld\n",LONG_LONG_MIN);
  printf("long long max %lld\n",LONG_LONG_MAX);

  

  
  cout<<07654321<<endl;
  cout<< (1LL << 62LL) <<endl;
}
