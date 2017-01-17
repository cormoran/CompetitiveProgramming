//負けない優先プログラム
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<utility>
#define rep(i,j) for(i=0;i<j;i++)
using namespace std;
//player:4 language:6 turn:9?

typedef struct 
{
  //初期値
  int attention;//3 to 6
  //変動値
  int revealed_num[4];//各プレーヤの平日信者＋6ターンからはそれ以前の休日信者
  int guess_num[4];
  int real_num;//休日も含めた自分の信者数
  int preholiday_num;//平日のみ
  int mini,macs;
}language;

int all_Time,all_Player,all_Language;
language Language[6];

void init()
{
  int i,j;
  srand(time(NULL));
  cout<<"READY"<<endl;
  cin>>all_Time>>all_Player>>all_Language;
  rep(i,all_Language)
    {
      rep(j,all_Player)Language[i].guess_num[j]=0;
      cin>>Language[i].attention;
    }
}

void turn()
{
  //入力
  int now_Time;
  char Day;
  cin>>now_Time>>Day;
  int i,j;
  rep(i,all_Language)rep(j,all_Player)
    cin>>Language[i].revealed_num[j];

  rep(i,all_Language)cin>>Language[i].real_num;
  if(Day=='W'){
    rep(i,all_Language)cin>>Language[i].preholiday_num;
    rep(j,all_Player)Language[i].guess_num[j]+= (Language[i].preholiday_num>2 ? 2 : Language[i].preholiday_num);
  }
  //6ターン目に全て教えてくれる
  if(now_Time==6)
    rep(i,all_Language)rep(j,all_Player)Language[i].guess_num[j]=0;


  //解析
  
  //各言語最小のやつを探す、自分と比べる
  pair<int,int> diff[6]={};//自分が最小のやつに対してどれくらいか
  rep(i,all_Language)
    {
      //0は自分で除外
      Language[i].mini=Language[i].revealed_num[1]+Language[i].guess_num[1];
      for(j=2;j<all_Player;j++)
	{
	  Language[i].mini=min(Language[i].mini,Language[i].revealed_num[i]+Language[i].guess_num[i]);
	}
      diff[i]=pair<int,int>(Language[i].real_num-Language[i].mini,i);
    }
  sort(diff,diff+all_Language);//小さい順になる
  //  cout<<"diff : ";
  //  rep(i,all_Language)cout<<diff[i].first<<" ";
  //  cout<<endl;
  if(Day=='W')
    {
      rep(i,5)//5回布教
	{
	  if(diff[0].first<=2)
	    {
	      cout<<diff[0].second<<(i==4 ? "\n" : " ");
	      diff[0].first+=1;
	      sort(diff,diff+all_Language);//小さい順になる
	    }
	  else
	    {
	      cout<<diff[5].second<<(i==4 ? "\n" : " ");
	      diff[5].first+=1;
	    }
	}
    }
 else 
   {
     if(diff[0].first<=2)
       {
	 cout<<diff[0].second<<" ";
	 diff[0].first+=2;
	 sort(diff,diff+all_Language);//小さい順になる
       }
     else
       {
	 cout<<diff[5].second<<" ";
	 diff[5].first+=2;
       }
     if(diff[0].first<=2)
       {
	 cout<<diff[0].second<<endl;
	 diff[0].first+=2;
	 sort(diff,diff+all_Language);//小さい順になる
       }
     else
       {
	 cout<<diff[5].second<<" ";
	 diff[5].first+=2;
       }
   }

}

int main()
{

  init();
  int i;
  rep(i,all_Time)
    turn();

  return 0;
}
