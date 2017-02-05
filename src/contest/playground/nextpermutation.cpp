#include<algorithm>
#include<iostream>
using namespace std;
#define N 3
bool used[N];
int perm[N];

int perm1(int pos,int n){
  if(pos==n){
    for(int i=0;i<N;i++)
      cout<<perm[i];
    cout<<endl;
    return 0;
  }
  for(int i=0;i<N;i++){
    if(!used[i]){
      perm[pos]=i;
      used[i]=true;
      perm1(pos+1,N);
      used[i]=false;
    }
  }
     return 0;
}

int perm2(){
  int n=3;
  int perm2[n];
  for(int i=0;i<n;i++){
    perm2[i]=i;
  }
  do{
    for(int j=0;j<n;j++)cout<<perm2[j];
    cout<<endl;
  }while(next_permutation(perm2,perm2+n));
  return 0;
}

int main (){
  cout<<"perm1"<<endl;
  perm1(0,N);
  cout<<"perm2"<<endl;
  perm2();
}
