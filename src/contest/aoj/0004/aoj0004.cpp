/*coutの書式設定に関する例
<iomanip>にsetprecision()がはいってる
doubleには-0.000が存在する : L12,13で対策
*/
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
  double a,b,c,d,e,f;
  while(cin >>a>>b>>c>>d>>e>>f){
    double x=(c*e-b*f)/(a*e-b*d),y=(c*d-a*f)/(b*d-a*e);
    if(x==0)x=0;
    if(y==0)y=0;
    cout <<fixed<<setprecision(3)<< x <<" "<< y <<endl;
  }
  return 0;
}
