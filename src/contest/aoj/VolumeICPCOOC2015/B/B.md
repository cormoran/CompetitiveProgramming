---
title        : aoj-VolumeICPCOOC2015-B
date         : 2015-11-30
contests     : aoj
status        : AC
problemtypes :
- 幾何

---

# ICPC2015-B

<!--more-->

## 問題概要

  地上に並んだ丸棒を、地面に接したまま、順番を変えずに隙間なくおいた場合に必要な全体の幅を求める.
  

## 解法

　片側から置く場所を二分探索した。


~~~
const double EPS=1e-8;

struct Point{
    double x,y;
    Point():x(0),y(0){}
    Point(double x,double y):x(x),y(y){};
    bool operator == (const Point &a) const { return x == a.x && y == a.y; }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
};
istream &operator >> (istream& is, Point& p){ return is >> p.x >> p.y;}
ostream &operator << (ostream& os, const Point& p){ return os << "(" << p.x << "," << p.y << ")";}

double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
double norm(const Point& a) { return sqrt(dot(a, a)); }
double distance(const Point& a, const Point& b) { return norm(a - b); }

bool check(vector<Point> &P, vector<int> &R,Point &np,int nr){
    rep(i,P.size()){
        if(distance(P[i],np) - (R[i] + nr) < 0.0) return false;
    }
    return true;
}

bool solve(){
    int n; cin >> n;
    vector<int> R(n); cin >> R;
    vector<Point> P;
    for(int r : R){
        double l= P.size() > 0 ? max(P.back().x,(double)r) : r;
        double h=1e10;
        while(h-l>1e-8){
            double m = (l+h)/2;
            Point p = Point(m,r);
            if(check(P, R, p, r)) h = m;
            else l = m;
        }
        P.push_back(Point(h,r));
    }
    debug(P);
    double ans = 0;
    rep(i,P.size()) ans = max(ans,P[i].x+R[i]);
    printf("%.10f\n",ans);
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}


~~~