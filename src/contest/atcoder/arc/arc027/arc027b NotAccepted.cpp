#include<iostream>
#include<cstdlib>
//#include<ctype>
#include<string>
#include<map>
using namespace std;

#define rep(i,j) for(i=0;i<j;i++)

map<char,int> mapa,mapb,mapl;
int obvisum_a=0,obvisum_b=0,cnt=0;


bool is_a_b(){
  int i,j,va=0,vb=0;
  map<char,int>::iterator iter=mapa.begin();
  while(iter!=mapa.end()){
    iter->second=mapl.find(iter->first)->second;
    va+=inter->second;
    iter++;
  }
  iter=mapb.begin();
  while(iter!=mapb.end()){
    iter->second=mapl.find(iter->first)->second;
    vb+=iter->second;
    iter++;
  }
  if(obvisum_a+va==obvisum_b+vb){
    return mapa==mapb;
  }
  return false;
}

void eachnum(map<char,int>::iterator iter){
  int i;
  rep(i,10){
    iter->second=i;
    if(iter !=mapl.end()){
      eachnum(++iter);
      iter--;
    }
    else if(is_a_b())cnt++;
  }
}


int main(){
  int N;
  char a[N+1],b[N+1];
  cin >>N>>a>>b;

  int i,j;
  rep(i,N){
    if(isdigit(a[i])){
      obvisum_a += atoi(&a[i]);
    }
    else{
      mapa.insert(pair<char,int>(a[i],0));
      mapl.insert(pair<char,int>(a[i],0));
    }

       if(isdigit(b[i]))obvisum_b+=atoi(&b[i]);
    else{
      mapb.insert(pair<char,int>(b[i],0));
      mapl.insert(pair<char,int>(a[i],0));
    }
  }
  
  eachnum(mapl.begin());
 
  cout <<cnt<<endl;
  return 0;
}
