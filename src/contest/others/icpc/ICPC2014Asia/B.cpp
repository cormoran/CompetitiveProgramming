#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
//#include<>
using namespace std;

#define rep(i,j) for(i=0;i<j;(i)++)

int main()
{
  string line;
  getline(cin,line);
  int ans;
  cin>>ans;

  int ans_M=0,ans_L=0;
  int i;
  for(i=0;i<line.size();i++){
    //L計算
    if(i==0)ans_L+=atoi(&line[i]);
    else if(line[i]=='+'){
      ans_L+=atoi(&line[i+1]);
      i++;
    }
    else if(line[i]=='*'){
      ans_L*=atoi(&line[i+1]);
      i++;
    }
  }
  int val=0;
  for(i=0;i<line.size();i+=2){
    val=atoi(&line[i]);
    while(i+1<line.size() && line[i+1]=='*'){
      i+=2;
      val*=atoi(&line[i]);
    }
    ans_M+=val;
  }
  //cout<<ans_L<<" "<<ans_M<<endl;
  if(ans_L==ans && ans_M==ans)cout<<"U"<<endl;
  else if(ans_L==ans)cout<<"L"<<endl;
  else if(ans_M==ans)cout<<"M"<<endl;
  else cout<<"I"<<endl;
  return 0;
}
