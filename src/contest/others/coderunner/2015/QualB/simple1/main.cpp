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

//入室/攻撃
const string enter_attack_api = "http://game.coderunner.jp/enter?token=%1%";
//情報取得
const string get_info_api = "http://game.coderunner.jp/info?token=%1%";
const string get_info_json_api = "http://game.coderunner.jp/infoJson?token=%1%";
//戦績取得
const string get_myrank_api = "http://game.coderunner.jp/myrank?token=%1%";

const string get_myrank_json_api = "http://game.coderunner.jp/myrankJson?token=%1%";

const string get_rank_api = "http://game.coderunner.jp/rank?uid=[user_id]";

const string get_rank_json_api = "http://game.coderunner.jp/rankJson?uid=[user_id]";

const string get_room_info_api = "http://game.coderunner.jp/room?rid=%1%";//room

const string get_room_info_json_api = "http://game.coderunner.jp/roomJson?rid=%1%";//room

//const string a = "";


/*
http://game.coderunner.jp/roomJson?rid=[room_id]
コメント変更http://game.coderunner.jp/comment?token=[your_token]&text=[message]
質問フォーラムhttp://game.coderunner.jp/clar?token=[your_token]
質問の送信http://game.coderunner.jp/sendClar?token=[your_token]&text=[question]
*/


void get_info(){
    string u = str(boost::format(get_info_api) % token );
    string result = my::query(u);
    cout <<result<<endl;
}

int main() {
    get_info();
    return 0;
    
    srand(time(NULL));
    
    ReadSelect stdin_select(STDIN_FILENO);


    while(true){
        string u = str(boost::format(enter_attack_api) % token );
        string result = my::query(u);
        
        cout <<result <<endl;

        
        sleep(rand()%3+1);
    }
        
    
    return 0;
}
