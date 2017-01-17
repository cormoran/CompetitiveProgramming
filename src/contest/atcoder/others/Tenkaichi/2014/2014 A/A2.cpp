#include<iostream>
#include<queue>
using namespace std;



/*
struct {
  int time;
  int attype;
  int damage;
}typedef attack;
*/

int main(){

  char in;
  long long combo=0;
  double wait=0;
  int mykabrin=5;
  long long score=0;
  queue<double> Abox;//アタックまでの時間を格納
  queue<double> Kbox;//かぶりんが戻ってくるまで。一体ずつで管理

  string line;
  getline(cin,line);
  //  cout <<line.size();
  long long k;
  //一秒ごと実行されるつもり。
  for(k=0;k<line.size();k++){

    long long i,j,val;
    for(i=0;i<Kbox.size();i++){
      if(Kbox.front()>=1){
	Kbox.push(Kbox.front()-1);
	Kbox.pop();
      }
      else {
	Kbox.pop();
	mykabrin+=1;
	i--;
      }
    }
    
    for(i=0;i<Abox.size();i++){
      if(Abox.front()>=1){
	Abox.push(Abox.front()-1);
	Abox.pop();
      }
      else{
	Abox.pop();
	combo+=1;
	i--;
      }

    }

    in=line.at(k);
    if(wait>=1)wait-=1;
    else{
      wait=0;
      if(in=='-'){
	//何もなし
      }
      else if(in=='N'){
	//普通なげ
	if(mykabrin ){
	  //wait+=0.5;
	   score+=10*(1 + (combo/10) *0.1);
	   mykabrin-=1;
	   Kbox.push(6.5);
	   Abox.push(1.5);
	}
      }
      else {
	//ため投げ
	if(mykabrin>=3 ){
	   wait+=2.5;
	   score+=50*(1 + (combo/10) *0.1);
	   mykabrin-=3;
	   Kbox.push(8.5);
	   Kbox.push(8.5);
	   Kbox.push(8.5);
	   Abox.push(3.5);
	}
      }
    }



  }//End While
    
    cout << score<<endl;

    return 0;

}
