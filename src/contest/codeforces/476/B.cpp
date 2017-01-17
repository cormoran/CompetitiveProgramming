#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(){
  string line;
  cin>>line;
  int pl1=0,mi1=0,i;
  for(i=0;i<line.length();i++){
    if(line[i]=='+')pl1++;
    else mi1++;
  }
  cin>>line;
  int pl2=0,mi2=0,q=0;
  for(i=0;i<line.length();i++){
    if(line[i]=='+')pl2++;
    else if(line[i]=='-')mi2++;
    else q++;
  }
  //cout<<pl1<<" "<<pl2<<" "<<mi1<<" "<<mi2<<endl;

  int req_pl=0,req_mi=mi1-mi2<0 ? 0 : mi1-mi2;
  if(pl1-pl2<0)req_mi+=pl2-pl1;
  else req_pl+=pl1-pl2;
  if(mi1-mi2<0)req_pl+=mi2-mi1;
  else req_mi=mi1-mi2;

  if(q<req_pl+req_mi)printf("%.12f",0.0);
  else{
    int qPk=1,pow2_q=1,q_k_ki=1;
    if(q>0)
      for(i=q;i>q-req_pl;i--){
	qPk*=i;
	q_k_ki*=req_pl-q+i;
      }
    for(i=0;i<q;i++)pow2_q*=2;
    printf("%.12f\n",(double)qPk/pow2_q/q_k_ki);
  }

  return 0;
}
