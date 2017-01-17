#include<iostream>
#include<algorithm>

#define rep(i,j) for(i=0;i<j;i++)
#define MaxSize 8

using namespace std;

int bd[MaxSize][MaxSize];
bool bdflg[MaxSize][MaxSize];
int h,w,c;
/*bdの値はかえずにboolでグループ管理*/


/*左上と同じグループになっているやつの周りで同じ色のやつを九州*/
int unionpanels(int color){ 
  int i,j,addcnt=0;

  rep(i,w){
    rep(j,h){
      if(bdflg[i][j]==true){
	//既にグループに加入済み：周りを取り込む
	if(i>0 && bdflg[i-1][j]==false && bdflg[i-1][j]==color){bdflg[i-1][j]=true;addcnt++;}
	if(i<h-1 && bdflg[i+1][j]==false && bdflg[i+1][j]==color){bdflg[i+1][j]=true;addcnt++;}
	if(j>0 && bdflg[i][j-1]==false && bdflg[i][j-1]==color){bdflg[i][j-1]=true;addcnt++;}
	if(j<w-1 && bdflg[i][j+1]==false && bdflg[i][j+1]==color){bdflg[i][j+1]=true;addcnt++;}
      }
    }
  }
    return addcnt;
}


int main(){
 
  int i,j,k,l;

  while(true){
    int cnt1,cnt2,cnt3,cnt4,cnt5,ans=0;
    bool flg[4][MaxSize][MaxSize];
    /*入力*/
    cin >>h>>w>>c;    
    if(h==0 && w==0 && c==0)break;
    rep(i,h)rep(j,w)cin>>bd[i][j];
    
    /*1回目変更 候補は二色のみ*/
    memset(bdflg,0,sizeof(bdflg));
    /*その壱*/
    {
      cnt1=unionpanels(bd[0][0]);
      i=bd[0][1];
      cnt1+=unionpanels(i);
      memcpy(flg[0],bdflg,sizeof(bdflg));
      rep(j,5){
	/*2回目変更*/
	if(j==i)continue;
	cnt2=cnt1+unionpanels(j);
	memcpy(flg[1],bdflg,sizeof(bdflg));
	rep(k,5){
	  /*３回目変更*/
	  if(k==j)continue;
	  cnt3=cnt2+unionpanels(k);
	  memcpy(flg[2],bdflg,sizeof(bdflg));
	  rep(l,5){
	    /*４回目変更*/
	    if(l==k || l==c)continue;
	    cnt4=cnt3+unionpanels(l);
	    memcpy(flg[3],bdflg,sizeof(bdflg));
	    {
	      /*５回目変更　指定色*/
	      ans=max(cnt4+unionpanels(c),ans);
	    }
	    memcpy(bdflg,flg[3],sizeof(bdflg));
	  }
	  memcpy(bdflg,flg[2],sizeof(bdflg));
	}
	memcpy(bdflg,flg[1],sizeof(bdflg));
      }
      memcpy(bdflg,flg[0],sizeof(bdflg));
    }

    memset(bdflg,0,sizeof(bdflg));

    /*その弐*/
    {
      cnt1=unionpanels(bd[0][0]);
      i=bd[1][0];
      cnt1+=unionpanels(i);
      memcpy(flg[0],bdflg,sizeof(bdflg));
      rep(j,5){
	/*2回目変更*/
	if(j==i)continue;
	cnt2=cnt1+unionpanels(j);
	memcpy(flg[1],bdflg,sizeof(bdflg));
	rep(k,5){
	  /*３回目変更*/
	  if(k==j)continue;
	  cnt3=cnt2+unionpanels(k);
	  memcpy(flg[2],bdflg,sizeof(bdflg));
	  rep(l,5){
	    /*４回目変更*/
	    if(l==k || l==c)continue;
	    cnt4=cnt3+unionpanels(l);
	    memcpy(flg[3],bdflg,sizeof(bdflg));
	    {
	      /*５回目変更　指定色*/
	      ans=max(cnt4+unionpanels(c),ans);
	    }
	    memcpy(bdflg,flg[3],sizeof(bdflg));
	  }
	  memcpy(bdflg,flg[2],sizeof(bdflg));
	}
	memcpy(bdflg,flg[1],sizeof(bdflg));
      }
      memcpy(bdflg,flg[0],sizeof(bdflg));
    }
    cout <<ans<<endl;

  }
}
