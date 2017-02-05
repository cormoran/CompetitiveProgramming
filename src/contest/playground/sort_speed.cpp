#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;

inline void swap_(int *a,int*b)
{
  int c=*a;
  *a=*b;
  *b=c;
}

void bubble_sort(int *pt,long num)
{
  //昇順例
  long i,j;
  int temp;
  for(i=0;i<num;i++)
    for(j=1;j<num-i;j++)
      if(pt[j]<pt[j-1])
	swap_(pt+j,pt+j-1);
}

void selection_sort(int *pt,long num)
{
  long i,j;
  //昇順例
  int min_num,temp;
  for(i=0;i<num-1;i++)
    {
      min_num=i;
      for(j=i+1;j<num;j++)
	if(pt[min_num]>pt[j])
	  min_num=j;
      swap_(pt+min_num,pt+i);
    }
}

void insert_sort(int *pt,long num)
{
  //適切な場所に挿入を繰り返す
  long i,j;
  int temp;
  for(i=1;i<num;i++){
    temp=pt[i];
    if(pt[i-1]>temp){
      j=i;
      do
	pt[j]=pt[j-- -1];
      while(j>0 && pt[j-1]>temp);
      pt[j]=temp;
    }
  }
}

void std_sort(int *pt,long num)
{
  sort(pt,pt+num);
}




int main()
{
  long data_num=10000;
  clock_t start,end;
  srand(time(NULL));
  int numbers[4][data_num];
  for(long i=0;i<data_num;i++)
    {
      int temp=rand();
    for(int j=0;j<4;j++)
      numbers[j][i]=temp;
    }
  cout<<"start bubble"<<endl;
  start=clock();
  bubble_sort(numbers[0],data_num);
  end=clock();
  cout<<"時間 "<<(double)(end-start)/CLOCKS_PER_SEC*1000<<" ms"<<endl;

  cout<<"start selection"<<endl;
  start=clock();
  selection_sort(numbers[1],data_num);
  end=clock();
  cout<<"時間 "<<(double)(end-start)/CLOCKS_PER_SEC*1000<<" ms"<<endl;

  cout<<"start insert"<<endl;
  start=clock();
  insert_sort(numbers[2],data_num);
  end=clock();
  cout<<"時間 "<<(double)(end-start)/CLOCKS_PER_SEC*1000<<" ms"<<endl;  
  

  cout<<"start insert"<<endl;
  start=clock();
  std_sort(numbers[3],data_num);
  end=clock();
  cout<<"時間 "<<(double)(end-start)/CLOCKS_PER_SEC*1000<<" ms"<<endl;

  return 0;
}
