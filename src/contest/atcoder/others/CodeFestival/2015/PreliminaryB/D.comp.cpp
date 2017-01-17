/*
  --- 
  title : -D.comp.cpp
  date : 2015-10-25
  status : AC(コンテスト後)
  ---
  
  # Memo

  シミュレーション
  区間を統合していくことでO(NlogN)程度でできる
  区間は大きすぎるのでmapやsetで持つ
  ちゃんと統合できていれば itr-- が直前の区間になる 
 */
 
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cassert>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()


void debug_out(const map<ll,char> &line){
    for(auto &p : line){
        cout << p.first << " ";
    }
    cout << endl;
    for(auto &p : line){
        cout << p.second << " ";
    }
    cout << endl;
}
 
bool solve(){
    ios::sync_with_stdio(false);
    ll N;cin>>N;
    map<ll,char> line;
    
    rep(i,N){
        ll S,C;cin>>S>>C;
        auto nxt = line.lower_bound(S);
        while(true){
            if(nxt == line.end()){
                if(line.count(S)){
                    line.erase(S);
                } else {
                    line[S] = '[';
                }
                line[S+C] = ')';
                cout << S+C-1 << endl;
                break;
            } else {
                if(nxt->second == '['){
                    ll dist = nxt->first - S;
                    if(dist >= C){
                        if(line.count(S)){
                            line.erase(S);
                        } else {
                            line[S] = '[';
                        }
                        if(dist == C)line.erase(nxt);
                        else line[S+C] = ')';
                        cout << S+C-1 <<endl;
                        break;
                    } else {
                        C -= dist;
                        auto tmp = nxt;
                        nxt++;
                        line.erase(tmp);
                        if(line.count(S)){
                            line.erase(S);
                        } else {
                            line[S] = '[';
                        }
                        S++;
                        continue;
                    }
                } else if (nxt->second == ')'){
                    S = nxt->first;
                    nxt++;
                    continue;
                }
            }
        }
        //debug_out(line);
    }    
    return false;
}
 
int main()
{
    while(solve());
    return 0;
}
