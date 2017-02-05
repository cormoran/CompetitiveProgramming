#include "common.hpp"

string AI_NAME ="CM-AI-1st";

enum Charaname{worker=0,knight,fighter,assassin,castle,village,basepoint,};
const bool movable[7]={1,1,1,1,0,0,0};
const bool productive[7]={1,0,0,0,1,1,1};
const int initial_HP[7]={2000,5000,5000,5000,50000,20000,20000};
const int attack_range[7]={2,2,2,2,10,2,2};
const int visible_range[7]={4,4,4,4,10,10,4};
const int cost[7]={40,20,40,60,-1,100,500};
const int damages[7][7]=  //[from][to]
  {
    { 100, 100, 100, 100, 100, 100, 100},
    { 100, 500, 200, 200, 200, 200, 200},
    { 500,1600, 500, 200, 200, 200, 200},
    {1000, 500,1000, 500, 200, 200, 200},
    { 100, 100, 100, 100, 100, 100, 100},
    { 100, 100, 100, 100, 100, 100, 100},
    { 100, 100, 100, 100, 100, 100, 100},
  };

enum command{goup,godown,goleft,goright,make_woker,make_knight,make_fighter,make_assassin,make_village,make_basepoint,none};
const char command_sym[11]={'U','D','L','R','0','1','2','3','4','5','6'};

struct Point{
  int x,y;
};

struct character{
  long id;
  Charaname charatype;
  Point location;
  int HP;
};

struct Input_Data{
  long  remaining_time;
  int stage;
  int turn;
  int allmyresorce;
  int myarmy_num;
  int oppoarmy_num;
  int resource_num;
  vector<character> myarmy;
  vector<character> oppoarmy;
  vector<Point> resorce;
};

struct Output_data{
  //string AI_name;
  long instruction_num;//後で自動的に設定する
  vector< pair<long,command> > instructions;//noneを追加、全キャラに命令を送ってもいいよ。
};


Input_Data input()
{
  Input_Data idata;
  scanf("%ld%d%d%d",&idata.remaining_time,&idata.stage,&idata.turn,&idata.allmyresorce);
  //自軍キャラ
  scanf("%d",&idata.myarmy_num);
  rep(i,idata.myarmy_num){
    character chara;
    scanf("%ld%d%d%d%d",&chara.id,&chara.location.x,&chara.location.y,&chara.HP,&chara.charatype);
    idata.myarmy.push_back(chara);
  }
  //視野内の敵軍キャラ
  scanf("%d",&idata.oppoarmy_num);
  rep(i,idata.oppoarmy_num){
    character chara;
    scanf("%ld%d%d%d%d",&chara.id,&chara.location.x,&chara.location.y,&chara.HP,&chara.charatype);
    idata.oppoarmy.push_back(chara);
  }

  //視野内の資源
  scanf("%d",&idata.resource_num);
  rep(i,idata.resource_num){
    Point rp;
    scanf("%d %d",&rp.x,&rp.y);
    idata.resorce.push_back(rp);
  }
  string temp;
  //cin>>temp;
  return idata;
}

void output(Output_data data){
  data.instruction_num=0;
  //  rep(i,data.instructions.size())
  //  if(data.instructions[i].second!=none)data.instruction_num++;

  printf("%ld\n",data.instruction_num);
  rep(i,data.instructions.size()){
    if(data.instructions[i].second!=none)
      printf("%ld %c\n",data.instructions[i].first,command_sym[data.instructions[i].second]);
  }
}

int main()
{

  cout<<AI_NAME<<endl;
  Input_Data i_data;
  Output_data o_data;
  
  while(true){
    i_data=input();
    o_data.instruction_num=0;
    output(o_data);
  }
  
  return 0;
}
