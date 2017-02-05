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

const string token  = "KPP52J0VX3MNF96O66B9BFV3AW6BG3JT";

const string URL ="https://game.coderunner.jp/query?token=%1%&v=";

int main() {
    srand(time(NULL));
    
    ReadSelect stdin_select(STDIN_FILENO);

    int dist[1001][1001]={};

    //load
    {
        FILE* f = fopen("./log", "r");
        int ret;
        int a,b,c;//a<b
        while((ret=fscanf(f,"%d\t%d\t%d",&a,&b,&c)) != EOF){
            if(a>b)swap(a,b);
            dist[a][b]=max(dist[a][b],c);
            dist[b][a]=dist[a][b];
        }
        fclose(f);
        cout << "Load Completed!" << endl;
    }

    ReadSelect StdReader(STDIN_FILENO);
    
    while(true){
        if(StdReader.isNew()){
            char c ;
            scanf("%c",&c);
            cerr << "Stdin : "<<c<<endl;
            if(c=='q'){
                break;
            }
        }
        
        int a,b;
        do{
            a=rand()%1000+1;
            b=rand()%1000+1;
        }while(a==b or dist[a][b]>0);
        if(a>b)swap(a,b);
        
        string url = str(boost::format(URL) % token);
        url = url + to_string(a) +","+ to_string(b);
        string result = my::query(url);
        try {
            int pt = stoi(result);
            dist[a][b]=pt;
            dist[b][a]=pt;
            cout<<str(boost::format("%1%\t%2%\t%3%") % a % b % pt)<<endl;
            cerr<<str(boost::format("%pair( %1% %2% ) point : %3%") % a % b % pt)<<endl;
        }
        catch (...) {
            cerr << "err " << result <<endl;
        }
        sleep(1);
    }

    FILE* f = fopen("./log","w");
    rep(i,1001){
        for(int j=i+1;j<=1000;j++){
            if(dist[i][j]>0){
                fprintf(f, "%d\t%d\t%d\n",(int)i,j,dist[i][j]);
            }
        }
    }

    fclose(f);
    
    return 0;
}
