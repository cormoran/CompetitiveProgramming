#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;

bool p5cmp(int a,int b){
  int m=a%100;
  m+=5;
  int h=a/100;
  if(m>=60){
    h+=m/60;
    m=m%60;
  }
  a=h*100+m;
  if(a>b)return true;
  return false;
  
}

int main(){
  int N;
  cin>>N;
  vector<pair<int,int> > lst;
  for(int i=0;i<N;i++){
    string s,t;
    getline(cin,s,'-');
    cin>>t;
    lst.push_back(make_pair(stoi(s),stoi(t)));
  }

  sort(begin(lst),end(lst));

  vector<pair<int,int> > ans;

  int i=0;
  while(i<lst.size()){
    int st,ed;
    st=lst[i].first;
    if(st%5)st-=st%5;
    ed=lst[i].second;
    if(ed%5)ed+=5-ed%5;

    while(i+1<lst.size() and p5cmp(ed,lst[i+1].first)){
      i++;
      int tmp=lst[i].second;
      if(tmp%5)tmp+=5-tmp%5;
      ed=max(ed,tmp);
      if(ed%5)ed+=5-ed%5;
    }
    ans.push_back(make_pair(st,ed));
    i++;
  }
  for(int i=0;i<ans.size();i++){
    printf("%04d-%04d\n",ans[i].first,ans[i].second);
  }
  return 0;
}
