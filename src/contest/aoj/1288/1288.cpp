#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cassert>
#include<tuple>

using namespace std;

typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

const double EPS = 1e-8;

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    bool operator==(const Point &a) const { return a.x==x && a.y==y;}
    bool operator!=(const Point &a) const { return a.x!=x || a.y!=y;}
    bool operator<(const Point &a) const { return a.x!=x ? a.x > x : a.y>y;}
};

double dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
double cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
double norm(const Point& a) { return sqrt(dot(a, a)); }
ostream& operator<<(ostream& os, const Point& p) { return os << "(" << p.x << "," << p.y << ")"; }
istream& operator>>(istream& is, Point& p) { return is >> p.x >> p.y; }

int ccw(Point a, Point b, Point c){
    b = b - a; c = c - a;
    if (cross(b, c) > EPS) return +1;      // a,b,cの順に反時計周り
    if (cross(b, c) < -EPS) return -1;     // a,b,cの順に時計周り
    if (dot(b, c) < 0) return +2;          // c--a--b 直線
    if (norm(b) < norm(c)) return -2;      // a--b--c 直線
    return 0;                              // a--c--b 直線
}

struct Segment {
    Point a, b;
    Segment() {}
    Segment(const Point& a, const Point& b) : a(a), b(b) {}
    bool operator==(const Segment s)const { return a==s.a and b==s.b;}
};
istream& operator>>(istream& is, Segment& s) { return is >> s.a >> s.b; }
bool intersects(const Segment& s, const Segment& t) {
    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

class UnionFindTree
{
  public:
    int Node_num;
    vector<int> parents;
    UnionFindTree(int n):Node_num(n+1){
        n++;//index=1_to_nに対応
        parents.resize(n);
        for(int i=0;i<n;i++){
            parents[i]=i;
        }
    }  
    int get_root(int x){
        if(parents[x]==x)return x;
        else return parents[x]=get_root(parents[x]);
    }
    void unite(int x,int y){
        if( (x=get_root(x))!=(y=get_root(y)) ){
            parents[x]=y;
        }
    }
    bool is_sameset(int x,int y){
        return get_root(x) == get_root(y);
    }
};


int count_intersects(const vector<Segment> &S){
    int ret=0;
    rep(i,S.size()){
        rep(j,i){
            if(intersects(S[i], S[j]))ret++;
        }
    }
    return ret;
}

bool have_midpoint(const vector<Segment> &S){
    rep(i,S.size()){
        rep(j,i){
            if(intersects(S[i],S[j])){
                if( S[i].a != S[j].a and S[i].a != S[j].b and
                  S[i].b != S[j].a and S[i].b != S[j].b)return true;
                //こっちでもOK
                // vector<Point> P = {S[i].a,S[i].b,S[j].a,S[j].b};
                // sort(all(P));
                // P.erase(unique(P.begin(),P.end()),P.end());
                // if(P.size()==4)return true;
            }
        }
    }
    return false;
}

bool is_two(const vector<Segment> &S){
    Segment side;
    bool flg = false;
    rep(i,S.size()){
        int cnt =0;
        rep(j,S.size()){
            if(i!=j and intersects(S[i], S[j]))cnt++;
        }
        if(cnt == 1){
            side = S[i];
            flg = true;
            break;
        }
    }
    assert(flg);
    
    rep(i,S.size()){
        if(side == S[i])continue;
        if(intersects(side, S[i])){
            Point a,b,c;
            if(side.a == S[i].a){
                tie( a , b , c ) = make_tuple( side.b , side.a , S[i].b );
            } else if(side.a == S[i].b){
                tie( a , b , c ) = make_tuple( side.b , side.a , S[i].a );
            } else if(side.b == S[i].a){
                tie( a , b , c ) = make_tuple( side.a , side.b , S[i].b );
            } else if(side.b == S[i].b){
                tie( a , b , c ) = make_tuple( side.a , side.b , S[i].a );
            } else assert(0);

            switch( ccw (a,b,c) ){
                case 1:
                    return false;
                case -1:
                    return true;
                default:
                    assert(0);
            }
        }
    }
    assert(0);
}

int recognize(vector<Segment> &S){
    switch( count_intersects(S) ){
        case 0:
            assert(S.size()==1);
            return 1;
        case 2:
            assert(S.size()==3);
            return have_midpoint(S) ? 4 : 7;
        case 3:
            assert(S.size()==4);
            return 3;
        case 4:
            if( have_midpoint(S) ) return 9;
            else if( S.size() == 4 ) return 0;
            else if( S.size() == 5 ) return is_two(S) ? 2 : 5;
        case 5:
            assert(S.size()==5);
            return 6;
        case 6:
            assert(S.size()==5);
            return 8;
            //fallthrough
        default:
            assert(0);
    }
}

bool solve(){
    int n;
    cin>>n;
    if(n==0)return false;
    vector<Segment> S(n);
    rep(i,n){
        cin >> S[i];
    }
    
    UnionFindTree ut(n);
    rep(i,n)rep(j,i){
        if(intersects(S[i], S[j]))ut.unite(i,j);
    }

    vector<int> ans(10,0);
    vector<bool> used(n,false);
    rep(i,n){
        if(used[i])continue;
        vector<Segment> SS;
        SS.push_back(S[i]);
        used[i]=true;
        rep(j,n){
            if((not used[j]) and ut.is_sameset(i, j)){
                SS.push_back(S[j]);
                used[j]=true;
            }
        }
        ans[recognize(SS)]++;
    }
    
    rep(i,n)if(not used[i])assert(0);
    
    rep(i,9){
        cout << ans[i]<<" ";
    }
    cout <<ans.back()<<endl;
    
    return true;
}

int main()
{
    while(solve());
    return 0;
}
