//#include<bits/stdc++.h>
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

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ (i)=0;(i)<(j);(i)++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);(i)++)
#define all(v) v.begin(),v.end()

#include <unistd.h>
#include<boost/format.hpp>
#include "../myselect.hpp"
#include "../query.hpp"
#include<ctime>

using namespace std;
using namespace my;
typedef pair<int,int> pii;

const string token  = "KPP52J0VX3MNF96O66B9BFV3AW6BG3JT";
const string URL ="https://game.coderunner.jp/query?token=%1%&v=";

int send_query(vector<pii> &v){
    sleep(1);
    string url = str(boost::format(URL) % token);
    string v_str="";
    string v_out="{";
    for(pii p : v){
        v_str = v_str + to_string(p.first) +","+ to_string(p.second) ;
        v_out +="{"+to_string(p.first) +","+ to_string(p.second) +"},";
        if(p!=v.back())v_str+=',';
    }
    string result ;
    int pt=0;

    //cout <<url+v_str<<endl;

    try{
        result = my::query(url + v_str);
        pt = stoi(result);
        cout << pt << " " << v_str  <<endl;
        cerr << pt << " " << v_out   <<endl;
    }
    catch (std::invalid_argument e) {
        cerr << result<< endl;
    }
    return pt;
}

const int max_d = 100;

int main() {
    cout << "Start" << endl;

    srand(time(NULL));
    
    ReadSelect stdin_select(STDIN_FILENO);
    ReadSelect StdReader(STDIN_FILENO);

    int dist[1001][1001]={};
    
    
    vector<pii> pairs;
    pairs.reserve(10000);
    int prept =0;



    
    while(true){
        if(StdReader.isNew()){
            char c ;
            scanf("%c",&c);
            cerr << "Stdin : "<<c<<endl;
            if(c=='q'){
                break;
            }
        }
        int new_pt=0;
        int a,b;
        int add_s = 0;
        while(new_pt <=0 or max_d  <new_pt){
            int rn =rand()%10;
            if(add_s >5 and rn %2){
                cerr << "SWAP : " <<endl;
                int idx = rand() % pairs.size();
                pii old_p = pairs[idx];

                do{
                    a=rand()%1000+1;
                    b=rand()%1000+1;
                }while(a==b or dist[a][b]>0);
                if(a>b)swap(a,b);                
                pairs[idx] = make_pair(a,b);
                new_pt = send_query(pairs);
                if(new_pt <=0 or max_d < new_pt)pairs[idx] = old_p;
                
            }else{
                cerr << "ADD : " <<endl;
                do{
                    a=rand()%1000+1;
                    b=rand()%1000+1;
                }while(a==b or dist[a][b]>0);
                if(a>b)swap(a,b);
                
                pairs.push_back(make_pair(a,b));
                new_pt = send_query(pairs);
                if(new_pt<=0 or max_d < new_pt){
                    pairs.pop_back();
                    add_s++;
                }
            }
        }
        dist[a][b]=dist[b][a]=prept-new_pt;
    }
    
    return 0;
}
