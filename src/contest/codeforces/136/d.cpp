#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
//#include<>
using namespace std;

typedef long long int64;
typedef int int32;
typedef char int8;
typedef int32 int__;
typedef pair<int,int> pii;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j),i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j),i<=(k);i++)
#define rev_rep(i,j,k) for(int__ i=(j)-1;i>=k;i--)
#define all(v) (v).begin(),(v).end()

const int INF=1<<30;//=10E10

struct point_{
  int n;
  int x;
  int y;
  bool operator<(const point_&l)const{
    return l.n>n;
  }
};

bool is_rect(point_ p[4]){
  rep(i,3){
    //長方形か
    int64 inp=(p[i%4].x-p[(i+1)%4].x)*(p[(i+2)%4].x-p[(i+1)%4].x)+(p[i%4].y-p[(i+1)%4].y)*(p[(i+2)%4].y-p[(i+1)%4].y);//二方向へのベクトルの内積
    if(inp!=0)return false;
  }
  return true;
}

//a,b,c,dの順に回って正方形かどうか
bool is_square(point_ p[4]){
  int64 dist=-1;
  rep(i,4){
    //長方形か
    if(is_rect(p)==false)return false;
    //平行四辺形か?
    int64 dist_t=(p[i%4].x-p[(i+1)%4].x)*(p[i%4].x-p[(i+1)%4].x)+(p[i%4].y-p[(i+1)%4].y)*(p[i%4].y-p[(i+1)%4].y);
    if(dist<0)dist=dist_t;
    else if(dist!=dist_t)return false;
  }
  return true;
}

int main()
{
  point_ pt[8];
  rep(i,8){
    pt[i].n=i+1;
    cin>>pt[i].x>>pt[i].y;
  }
  //sort(pt,pt+8);
  do{
    if(is_square(pt) && is_rect(pt+4)){
      cout<<"YES"<<endl;
      sort(pt,pt+4);
      sort(pt+4,pt+8);
      printf("%d %d %d %d\n",pt[0].n,pt[1].n,pt[2].n,pt[3].n);
      printf("%d %d %d %d\n",pt[4].n,pt[5].n,pt[6].n,pt[7].n);
      return 0;
    }
  }while(next_permutation(pt,pt+8));
  cout<<"NO"<<endl;
  
  return 0;
}

















