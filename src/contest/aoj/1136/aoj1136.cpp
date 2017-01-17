#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i,j) for(i=0;i<j;i++)
using namespace std;

int main(){
    while(1){
        int n;
        cin >>n;
        //cout<<"aaaaaa";
        if(n==0)break;
        int i,j;
        vector< vector<int> > lines;
        rep(i,n+1){
            vector<int> line;
            int m;
            cin >>m;
            int x,y,x_,y_,sail;
            cin >>x>>y;
            line.push_back(0);
            sail=1;
            rep(j,m-1){
                cin >>x_>>y_;
                int val;
                if(j==m-2)val=0;
                else if(sail==0){
                    line.push(1);
                }
                else{
                    else if(sail==1){
                        if(x_>x)val=-2;
                        else if(x_<x)val=2;
                        else if(y_>y)val=1;
                        else if(y_<y)val=-1;
                    }
                    else if(sail==-1){
                        
                        if(x_>x)val=2;
                        else if(x_<x)val=-2;
                        else if(y_>y)val=-1;
                        else if(y_<y)val=1;
                    }
                    else if(sail==2){
                        
                        if(x_>x)val=1;
                        else if(x_<x)val=-1;
                        else if(y_>y)val=2;
                        else if(y_<y)val=-2;
                    }
                    else if(sail==-2){
                        if(x_>x)val=1;
                        else if(x_<x)val=-1;
                        else if(y_>y)val=-2;
                        else if(y_<y)val=2;
                    }
                    
                    line.push_back(val);
                    sail=val;
                    x_=x;
                    y_=y;
                }
            }
            lines.push_back(line);
        }
        rep(i,n){
            if(lines.at(0)==lines.at(i+1))cout <<i+1<<endl;
            else{
                reverse(lines.at(i+1).begin(),lines.at(i+1).end());
                if(lines.at(0)==lines.at(i+1))cout <<i+1<<endl;
            }
        }
        cout <<"+++++"<<endl;
    }
}
