/*
  --- 
  title : -1271.comp.cpp
  date : 2015-10-29
  status : NULL
  ---
  
  # Memo

  反復深化
  
 */

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cassert>
#include<array>
#include<unordered_set>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

bool iddfs(vector<int> &generated,vector<bool> &used,int goal,int left_depth){
    if(used[goal])return true;
    if(left_depth <= 0)return false;
    
    rep(i,generated.size()){
        repeat(j,i,generated.size()){
            for(int sgn : {1,-1}){
                int tmp = abs( generated[i] + generated[j] * sgn );
                if(tmp == 0 or tmp >= (int)used.size())continue;
                if(used[tmp])continue;
                
                generated.push_back(tmp);
                used[tmp]=true;
                if(iddfs(generated,used,goal,left_depth-1)) return true;
                used[tmp]=false;
                generated.pop_back();
            }
        }
    }
    return false;
}


void generate_table(){
    vector<int> buf;
    vector<bool> used(5000,false);
    repeat(i,1,1000){
        int dep =0;
        buf.clear();
        buf.push_back(1);
        fill(all(used),false);
        used[1]=true;
        while(!iddfs(buf, used, i, dep))dep++;
        cout << i << " "  << dep <<endl;
    }
}

//bool solve(){
bool solve(){

    return false;
}

int main()
{
    generate_table();
            
    //while(solve());
    return 0;
}
