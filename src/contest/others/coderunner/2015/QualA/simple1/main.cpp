#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include<boost/format.hpp>
#include "../myselect.hpp"
#include "../query.hpp"
#include<ctime>
using namespace std;
using namespace my;

const string token  = "KPP52J0VX3MNF96O66B9BFV3AW6BG3JT";

const string url ="https://game.coderunner.jp/query?token=%1%&v=%2%,%3%";

int main() {
    srand(time(NULL));
    
    ReadSelect stdin_select(STDIN_FILENO);
    
    for(int one =0;one<=999 ;one++){
        for(int two =one+1;two<=999;two++){
        if(stdin_select.isNew()){
            char c;
            cin >> c;
            if(c=='q')break;
        }

        
        if(one ==two){
            two = one +1;
            two %=100;
            two +=1;
        }
        string u = str(boost::format(url) % token % one % two);
        //cout <<u<<endl;
        string result = my::query(u);

        cout <<boost::format("%1%\t%2%\t%3%") % one % two % result <<endl;
        cerr <<boost::format("%1%\t%2%\t%3%") % one % two % result <<endl;
        
        sleep(1);
    }
    }

    
    return 0;
}
