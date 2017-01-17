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
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(int)(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()
//end template


typedef vector<string> state;

int x,y;
bool G[8][8]; // [8][8] E:0to3,W:4to7

inline void move_str(string &dest , string & src , size_t idx , size_t len , bool to_head){

    string mv;
    mv = src.substr(idx,len);

    if( (idx==0 && to_head) || (idx!=0 && !to_head) ) reverse(all(mv));
    
    if(to_head) dest = mv  + dest;
    else dest = dest + mv;
    
    src = src.substr( (idx==0 ? len : 0) , src.size() - len);

}


void rec(vector<set<state>> &result,state now , int dep){
    // cout << dep << endl;
    // for(string str : now){
    //     cout << "\t" << str << endl;
    // }

    if(result[dep].insert(now).second == false) return;

    
    if(dep == 3)return ;
    
    rep(src,x){
        rep(i,now[src].size()){
                
            rep(dest,x){
                if(dest != src){
                    //W to W
                    if(G[src][dest]){
                        state next = now;
                        move_str(next[dest], next[src], 0, i+1 , true);
                        rec(result, next, dep+1);
                    }
                    //E to E
                    if(G[src+4][dest+4]){
                        state next = now;
                        move_str(next[dest], next[src], i , next[src].size()-i , false);
                        rec(result, next, dep+1);
                    }
                    
                }
                //W to E
                if(G[src][dest+4]){
                    state next = now;
                    move_str(next[dest], next[src], 0, i+1 , false);
                    rec(result, next, dep+1);
                }
                //E to W
                if(G[src+4][dest]){
                    state next = now;
                    move_str(next[dest], next[src], i , next[src].size()-i , true);
                    rec(result, next, dep+1);
                }
            }
        }
    }
}

int find_ans(vector<set<state>> &from_start , vector<set<state>> from_goal){
    int ret = 7;
    rep(st_dep,4){
        rep(gl_dep,4){
            for(state ss : from_start[st_dep]){
                for(state fs : from_goal[gl_dep]){
                    if(ss == fs){
                        ret = min(ret , (int)st_dep + (int)gl_dep );
                    }
                }
            }
        }
    }
    return ret;
}



bool solve(){
    rep(i,8){
        rep(j,8){
            G[i][j]=false;
        }
    }
    
    cin >> x >> y;
    if(x==0 and y==0){
        return false;
    }
    rep(i,y){
        int p,q;
        char P,Q;
        scanf("%d%c %d%c",&p,&P,&q,&Q);
        //printf("%d%c %d%c\n",p,P,q,Q);
        if(P=='E')p+=4;
        if(Q=='E')q+=4;
        G[p][q]=true;
        G[q][p]=true;
    }

    state start = vector<string>(x);
    state goal = vector<string>(x);

    rep(i,x){
        cin >> start[i];
        if(start[i]=="-")start[i]="";
    }
    rep(i,x){
        cin >> goal[i];
        if(goal[i]=="-")goal[i]="";
    }

    vector< set<state> > from_start(4);
    vector< set<state> > from_goal(4);
    rec(from_start,start,0);
    rec(from_goal,goal,0);


    // rep(i,4){
    //     cout << "size : " << from_start[i].size() <<endl;
    //     // for(state s : from_start[i]){
    //     //     cout << i <<endl;
    //     //     for(string str : s){
    //     //         cout << "\t" << (str.size()==0 ? "-" : str) << endl;
    //     //     }
    //     // }
    // }

    
    int ans = find_ans(from_start, from_goal);
    assert(ans<=6);
    cout << ans << endl;
    return true;
}


int main()
{
    while(solve());
    return 0;
}
