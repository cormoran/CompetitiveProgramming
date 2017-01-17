#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

  while(true){
    int M,T,P,R;
    cin>>M>>T>>P>>R;
    if(!M and !T and !P and !R)break;

    vector< vector<bool> > is_ac(T,vector<bool>(P,false));
    vector< vector<int> > wa_num(T,vector<int>(P,0));
    vector< pair< pair<int,int> ,int > > point(T);

    for(int i=0;i<T;i++){
      point[i].second=i+1;
    }
    
    for(int i=0;i<R;i++){
      int m,t,p,j;
      cin>>m>>t>>p>>j;
      //cout<<m<<" "<<t<<" "<<p<<" "<<j<<endl;
      t--;
      p--;
      if(j==0){
        is_ac[t][p]=true;
        point[t].first.first++;
        point[t].first.second+=m*(-1);
      }
      else{
        wa_num[t][p]++;
      }
    }

    for(int i=0;i<T;i++){
      for(int j=0;j<P;j++){
        if(is_ac[i][j]){
          point[i].first.second-=wa_num[i][j]*20;
        }
      }
    }
    
    sort(point.begin(),point.end());
    reverse(point.begin(), point.end());


    for(int i=0;i<T;i++){
      if(i>0){
       if(point[i].first==point[i-1].first)printf("=");
       else printf(",");
      }
      printf("%d",point[i].second);
    }
    puts("");
  }
  
}
