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
};

bool comp_x(point_ &l,point_ &r){
  return l.x!=r.x ? l.x<r.x : l.y<r.y;
}

bool comp_y(point_ &l,point_ &r){
  return l.y!=r.y ? l.y<r.y : l.x<r.x;
}

int main()
{
  point_ pt[8];
  rep(i,8){
    pt[i].n=i+1;
    cin>>pt[i].x>>pt[i].y;
  }
  sort(pt,pt+8,comp_x);
  int fst[4],snd[4];
  
  //全探索
  rep(a,8)rep(b,8)
    if(a!=b && pt[a].x==pt[b].x)
      rep(c,8)
	if(a!=c&&b!=c&&pt[c].y==pt[b].y && abs(pt[a].x-pt[b].x)==abs(pt[b].y-pt[c].y))
	  rep(d,8)
	    if(a!=d&&b!=d&&c!=d&&pt[d].x==pt[c].x && pt[a].y==pt[d].y && abs(pt[a].x-pt[b].x)==abs(pt[c].x-pt[d].x))//スクエアOK
	      rep(e,8)
		if(a!=e&&b!=e&&c!=e&&d!=e)
		  rep(f,8)
		    if(a!=f&&b!=f&&c!=f&&d!=f&&e!=f&&pt[e].x==pt[f].x)
		      rep(g,8)
			if(a!=g&&b!=g&&c!=g&&d!=g&&e!=g&&f!=g&&pt[f].y==pt[g].y)
			  rep(h,8)
			    if(a!=h&&b!=h&&c!=h&&d!=h&&e!=h&&f!=h&&g!=h&&pt[g].x==pt[h].x&&pt[e].y==pt[h].y){
			      fst[0]=a;fst[1]=b;fst[3]=c;fst[4]=d;
			      snd[0]=e;snd[1]=f;snd[3]=g;snd[4]=h;
			    }
  sort(fst,fst+4);
  sort(snd,snd+4);
  rep(i,4)
    cout<<fst[i]<<" ";
  cout<<endl;
  rep(i,4)
    cout<<snd[i]<<" ";
  cout<<endl;
  return 0;
}

















