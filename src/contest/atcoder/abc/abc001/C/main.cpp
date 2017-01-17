#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int  main(){
  int deg,dis;
  string ansdeg="";
  cin>>deg>>dis;


  vector<string> s{"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"};

  int tmp=113;
  for(int i=0;i<s.size();i++){
    if(deg<tmp){
      ansdeg=s[i];
      break;
    }
    tmp+=225;
  }
  if(ansdeg=="")ansdeg="N";

  double diss=(double)dis/6;
  diss=(double)round(diss)/10;

  vector<double> d{0.3,1.6,3.4,5.5,8.0,10.8,13.9,17.2,20.8,24.5,28.5,32.7};
  int disans=-1;

  for(int i=0;i<d.size();i++){
    if(diss<d[i]){
      disans=i;
      break;
    }
  }
  if(disans<0)disans=12;
  if(disans==0)ansdeg="C";

  cout<<ansdeg<<" "<<disans<<endl;
  return 0;
}
