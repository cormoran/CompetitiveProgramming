/**
 * file   : A.cpp
 * date   : 2015-05-05
 * author : cormoran
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> point {25,39,51,76,163,111,136,128,133,138};

vector<int> allp;

void rec(int n,int sum){
  if(n==point.size()){
    allp.push_back(sum);
    return ;
  }

  rec(n+1,sum+point[n]);
  rec(n+1,sum);
}

int main()
{
  rec(0,0);
  point[6]=58;
  rec(0,0);

  sort(begin(allp),end(allp));

  allp.erase(unique(allp.begin(),allp.end()),allp.end());

  for( auto item : allp){
    cout<<item<<endl;
  }
  
  return 0;
}
