#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<set>
#include<bitset>
//#include<>
using namespace std;

typedef bitset<26> b26;
typedef long long int64;
typedef int int32;
typedef char int8;
typedef int32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

void rec(set<string> &ans,b26 rplflg,b26 preflg,string str,int pos){
  //最後まで見たら終わり
  if(pos==str.size()){
    ans.insert(str);
    return;
  }

  //まだ置き換えしていない文字
  if(rplflg[str[pos]-'a']==false){

    //aならそのままもあり
    if(str[pos]=='a'){
      rec(ans,rplflg,preflg|(b26)1,str,pos+1);
    }
    
    //以前にその文字が現れているなら置き換えない場合ある。
    else if(preflg[str[pos]-'a']==true){
      rec(ans,rplflg,preflg|(b26)(1<<(str[pos]-'a')),str,pos+1);
    }
    
    //z以外なら置き換え可能性あり
    if(str[pos]!='z'){
      str[pos]=str[pos]+1;
      rec(ans,rplflg|b26(1<<(str[pos]-1-'a')),preflg|b26(1<<(str[pos]-'a')),str,pos+1);
    }
    
  }
  //すでに置き換えた文字
  else if(str[pos]=='a'||preflg[str[pos]-'a']==true){
    rec(ans,rplflg,preflg|(b26)(1<<(str[pos]-'a')),str,pos+1);
  }
    
}

int main()
{
  string in_str;
  while(true){
    cin>>in_str;
    if(in_str=="#")break;
    b26 repflg,preflg;
    set<string> ans;
    rec(ans,repflg,preflg,in_str,0);

    cout<<ans.size()<<endl;
    if(ans.size()<=10){
      for(auto item : ans){
	cout<<item<<endl;
      }
    }
    else{
      auto eitr=ans.begin();
      advance(eitr,5);
      for(auto itr=ans.begin();itr!=eitr;itr++)
	cout<<*itr<<endl;
      auto itr=ans.end();
      advance(itr,-5);
      for(;itr!=ans.end();itr++)
	cout<<*itr<<endl;
    }
  }

  
  return 0;
}
