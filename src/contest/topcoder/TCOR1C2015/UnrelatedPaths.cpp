#include <string>
#include <vector>
#include<iostream>
using namespace std;

#define rep(i,j) for(int i=0;i<(j);i++)



class UnrelatedPaths {
 public:
  typedef pair<int,int> pii;

  vector<vector<int> > children;
  int ans=0;
  // -> (number of children,number of node)
  int rec(int node){
    int sumofchild=0;
    for(int i : children[node]){
      int ret=rec(i);
      sumofchild+=ret;
    }
    if(sumofchild==0)return 1;
    return sumofchild;
  }
  
  int maxUnrelatedPaths(vector <int> parent) {
    children.resize(parent.size()+1,vector<int>());
    rep(i,parent.size()){
      children[parent[i]].push_back(i+1);
    }
    return rec(0);

  }
};
