#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;



int calP(int num,int num2){
  int i,num_=1,k=num-num2+1;
  for(i=num;i>=k;i--)num_*=i;
  return num_;
}

int calkai(int num){
  return calP(num,num);
}

/*n:入力N noko:N-|x|/d-|y|/d x,y,d:入力 */
double calk(int n,int noko,int x,int y,int d){
  int k,r,val2,val3;
  double ans=0;
  r=noko/2;
  for(k=0;k<=r;k++){
    ans+=(double)calP(n,n-k)/(double)calP(y/d+k,y/d)/(double)calkai(k)/(double)calP(x/d+r-k,x/d)/(double)calkai(r-k)/(double)calkai(r-k);
  }
  return ans;
}

int main(){
  int  i,n,d,x,y,k;
  long fo;
  double p;
  cin >>n>>d>>x>>y;
    k=n-(abs(x)/d+abs(y)/d);  
    if(x%d!=0||y%d!=0||abs(d)*n<abs(x)+abs(y)||k%2!=0){
    cout << "0.0" <<"\n";
    return 0;
    }
    fo=1<<(2*n);
    p=calk(n,k,abs(x),abs(y),abs(d));
    for(i=0;i<2*n;i++)p/=(double)2;
    printf("%.16f\n",p);
//    cout << fixed<<p << "\n";
    return 0;
}
