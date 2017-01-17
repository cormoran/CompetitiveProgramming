#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
//#include<>
using namespace std;

typedef long long int64;
typedef int int32;
typedef char int8;
typedef int32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

struct node{
  int index;
  node *parent;
  node *child;
  node(){
    parent=(node*)-1;
    child=(node*)-1;
  }
};

//fをsの上に
void ins_node(node *f,node *s){
  if(f==s)return;
  
  if(f->child!=(node*)-1)
    f->child->parent=f->parent;
  
  f->parent->child=f->child;

  f->parent=s->parent;
  
  f->child=s;

  s->parent->child=f;
  s->parent=f;
}

int main()
{
  int n,m;cin>>n>>m;
  vector<int> w(n);
  rep(i,n)cin>>w[i];
  vector<int> b(m);
  rep(i,m)cin>>b[i];

  vector<bool> used(n,false);

  node book[501];//book[0]:top,none
  rep(i,n+1)book[i].index=i;
  book[0].child=&book[b[0]];
  book[b[0]].parent=&book[0];
  node *now = &book[b[0]];
  used[b[0]]=true;
  rep(i,m){
    if(!used[b[i]]){
      now->child=&book[b[i]];
      book[b[i]].parent=now;
      now=&book[b[i]];
      used[b[i]]=true;
    }
  }
  int cost=0;
  rep(i,m){
    now=&book[0];
    rep(j,n){
      now=now->child;
      if(now->index==b[i]){
	ins_node(now,book[0].child);
	break;
      }
      else
	cost+=w[now->index-1];
    }
    /*
    now=book[0].child;
    rep(j,3){
      cout<< now->index <<" ";
      if(now->child==(node*)-1)break;
      now=now->child;
    }
    cout<<endl;
    cout<<"s "<<cost<<endl;
    */
  }
  cout<<cost<<endl;
  return 0;
}
