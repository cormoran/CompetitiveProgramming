#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<string>
#include<cmath>
#include<cassert>
#include<map>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long i64;typedef i64 int64;
typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

pair<string,int> splitString(string s){
  int spliter=1;
  for(;spliter<=s.size();spliter++){
    double x=(double)s.size()/spliter;
    if(ceill(x)!=floor(x))continue;
    string subs=s.substr(0,spliter);
    bool flg=true;
    for(int i=0;i<s.size()-spliter;i+=spliter){
      if(s.substr(i,spliter)!=subs){
        flg=false;
        break;
      }
    }
    if(flg){
      return make_pair(subs,s.size()/spliter);
    }
  }

  assert(0);
  return make_pair("", -1);
}


double inline solve(int K,int L,int S,string &key,string &tar){
  pair<string,int> asdf=splitString(tar);

  string unt_str =asdf.first;
  int seq=asdf.second;

  //printf("Debug : unit: %s  seq: %d\n",unt_str.c_str(),seq);

  //最大総数
  int allcnt=S/unt_str.size() - seq +1;

  printf("all %d\n",allcnt);

  //1つのユニットが現れる確率
  double unit_prob=1;
  double not_unit_prob;
  vector<int> key_cnt(30,0);
  rep(i,K)key_cnt[key[i]-'A']++;
  rep(i,tar.size()){
    unit_prob*=key_cnt[tar[i]-'A'];
    unit_prob/=K;
  }
  not_unit_prob=1-unit_prob;

  vector<double> unit_probs(S/unt_str.size() +1,0);
  unit_probs[0]=1;
  rep(i,unit_probs.size()-1)unit_probs[i+1]=unit_probs[i]*unit_prob;

  
  double prob=0;
  rep(i,S-unt_str.size()+1){
    //tar[i]から始まる繰り返し
    rep(j,(S-i)/unt_str.size()){
      //j+1回繰り返される時
      double temp=(j+i-seq+1)*unit_probs[j+1];
      if(i>=unt_str.size())temp*=not_unit_prob;
      prob+=temp;
    }
  }
  return allcnt-prob;
}


int main()
{
  int T;
  cin>>T;
  int cnt=1;
  while(T){
    int K,L,S;
    string key,tar;
    //K: all key num
    //L: target length
    //S: times of typing key
    cin>>K>>L>>S;
    cin>>key;
    cin>>tar;
    
    double ans=solve(K,L,S,key,tar);
    //printf("Case #%d: %.10f\n",cnt,ans);
    T--;cnt++;
  }
  return 0;
}
