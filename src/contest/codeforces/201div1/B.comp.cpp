/*
  --- 
  title : -B.comp.cpp
  date : 2015-10-29
  status : NULL
  ---
  
  # Memo

  
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


string &max_len(string &s1,string &s2){
    if(s1.size() >= s2.size() ) return s1;
    else return s2;
}

bool solve(){
    string s1,s2;
    cin>>s1>>s2;
    string virus;
    cin >> virus;

    map<char,int> virus_map;
    rep(i,virus.size())virus_map[virus[i]]=i+1;
    
    int DP[101][101][101] = {}; // s1[i] s2[j] まででvirus[k]までを含む最大

    // cout << "    ";
    // repeat(i,1,s2.size()+1){
    //     cout << s2[i-1] << string(virus.size()+2,' ');
    // }
    //cout << endl;
    
    repeat(i,1,s1.size()+1){
        cout << s1[i-1] << " : ";
        repeat(j,1,s2.size()+1){
            repeat(k,0,virus.size()+1){
                if(k>0 and s1[i-1] == virus[k-1]){
                    if(s1[i-1] == s2[j-1]){
                        DP[i][j][k] = DP[i-1][j-1][k-1] + 1 ;
                    }
                } else {
                    if(s1[i-1] == s2[j-1]){
                        DP[i][j][k] = DP[i-1][j-1][k] + 1 ;
                    }
                }
                DP[i][j][k] = max(DP[i][j][k] , DP[i-1][j  ][k]);
                DP[i][j][k] = max(DP[i][j][k] , DP[i  ][j-1][k]);
                cout <<DP[i][j][k]<<" ";
            }
            cout <<" ";
        }
        cout<<endl;
    }

    int ans = -1;
    int ans_idx = -1;
    rep(i,virus.size()){
        if(ans < DP[s1.size()][s2.size()][i]){
            ans =DP[s1.size()][s2.size()][i];
            ans_idx = i;
        }
    }
    cout <<ans<<endl;
    string ans_str="";
    
    int i = s1.size(),j = s2.size(),k = ans_idx;
    int now = ans;
    while(DP[i][j][k]>0){
        //cout <<i << " : " <<j<<" : "<<k<<endl;
        if(DP[i-1][j][k] == now){
            i--;
        }
        else if(DP[i][j-1][k] == now)j--;
        else {
            ans_str += s1[i-1];
            if(k>0 and s1[i-1] == virus[k-1]){
                k--;
            }
            i--;j--;
            now = DP[i][j][k];
        }
    }
    if(ans_str.size() ==0 ){
        cout << 0 << endl;
    } else {
        reverse(all(ans_str));
        cout << ans_str <<endl;
    }
    
    return false;
}

int main()
{
    while(solve());
    return 0;
}
