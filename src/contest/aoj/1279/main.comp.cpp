//  aoj-1279  / 2015-11-21
#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<tuple>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

// const
const double INF = 1e10;
const double EPS = 1e-8;

// vector
template<typename T>ostream& operator << (ostream &os , const vector<T> &v){ rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os; }
template<typename T>istream& operator >> (istream &is , vector<T> &v){ rep(i,v.size()) is >> v[i]; return is; }

// debug
#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R> void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}

// Point
struct Point{
    double x,y;
    Point():x(0),y(0){}
    Point(double x,double y):x(x),y(y){};
    bool operator < (const Point &a) const { return x!=a.x ? x < a.x : y < a.y; }
    bool operator == (const Point &a) const { return x == a.x && y == a.y; }
    bool operator != (const Point &a) const { return x != a.x && y != a.y; }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
};
istream &operator >> (istream& is, Point& p){ return is >> p.x >> p.y;}
ostream &operator << (ostream& os, const Point& p){ return os << p.x << " " << p.y;}
template<typename T> int len(T t){ return t.size();}
double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
double norm(const Point& a) { return dot(a, a); }
double distance(const Point& a, const Point& b) { return sqrt(norm(a - b)); }

const int COUNTER_CLOCK_WISE = 1, CLOCK_WISE = -1;
const int STRAIGHT_C_A_B = 2, STRAIGHT_A_B_C = -2, STRAIGHT_A_C_B = 0;
int ccw(Point a,Point b,Point c){
    Point ab = b - a, ac = c - a;
    if( cross(ab,ac) > 0 ) return COUNTER_CLOCK_WISE;//a-b-c 反時計回り
    if( cross(ab,ac) < 0 ) return CLOCK_WISE;        //a-b-c 時計回り
    if( dot(ab,ac) < 0 ) return STRAIGHT_C_A_B;      //c-a-b
    if( norm(ab) < norm(ac) )return STRAIGHT_A_B_C;  //a-b-c or a==b
    return STRAIGHT_A_C_B;                           //a-c-b or b==c or a==c
}

// Segment
struct Segment{
    Point a, b;
    Segment(){}
    Segment(const Point& a, const Point& b):a(a), b(b){}
    bool operator == (const Segment & s)const { return a == s.a &&b == s.b;}  
};
istream &operator >> (istream& is, Segment& s){ return is >> s.a >> s.b;}
ostream &operator << (ostream& os, const Segment& s){ return os << s.a << "->" << s.b;}
bool does_intersect(const Segment &a, const Segment &b){
    return ccw(a.a, a.b, b.a) * ccw(a.a, a.b, b.b) <= 0 &&
            ccw(b.a, b.b, a.a) * ccw(b.a, b.b, a.b) <= 0;
}
double length(Segment &s){ return distance(s.a, s.b); }
bool does_include(Segment &s,Point &p){
    Point a = p - s.a , b = s.b - s.a;
    return ( abs(cross(a,b)) < EPS and dot(a,b) > -EPS and length(s)  > dot(a,b)/length(s) - EPS);
}


// // // // // // // // // // // // // // // // //


struct state{
    int idx,pre;
    double w;
    bool operator<(const state &r)const{return w > r.w;}
};

vector<int> dijkstra_route(vector<vector<int>> &E,int start,int goal,map<int,Point> &ridx){
    priority_queue<state> que;
    vector<double> dist(E.size(),INF);
    map<int,int> prev;
    
    que.push((state){start,-1,0});
    while(not que.empty()){
        state now = que.top(); que.pop();
        if(now.w > dist[now.idx]) continue;
        dist[now.idx] = now.w;
        prev[now.idx] = now.pre;

        //if(now.idx == goal) break;
        for(int to : E[now.idx]){
            double new_dist = now.w + distance(ridx[now.idx],ridx[to]);
            if(new_dist < dist[to]){
                que.push((state){to, now.idx, new_dist});
            }
        }
    }
    //経路復元
    if( not prev.count(goal) )return {};
    vector<int> ret;
    int now = goal;
    while(now != -1){
        ret.push_back(now);
        now = prev[now];
    }
    reverse(all(ret));
    return ret;
}

// signとedgeを分ける
// -> edge , sign
tuple<vector<Segment>,vector<Segment>> classify(vector<Segment> &S){
    vector<Segment> edge,sign;
    for(auto s : S){
        bool a = false,b = false;
        for(auto ss : S){
            if(s == ss)continue;
            if(does_intersect(s,ss)){
                if(does_include(ss,s.a)) a = true;
                if(does_include(ss,s.b)) b = true;
            }
        }
        (a and b ? edge : sign ).push_back(s);
    }
    // debug(edge);
    // debug(sign);
    return make_tuple(edge, sign);
}

// 辺上にある点で辺を分割
vector<Segment> divide(vector<Segment> &S){
    vector<Segment> ret;
    for(Segment s : S){
        vector<Point> ps = {s.a,s.b};
        for(Segment ss : S){
            if(s == ss)continue;
            if(does_include(s, ss.a)) ps.push_back(ss.a);
            else if(does_include(s, ss.b)) ps.push_back(ss.b);
        }
        sort(all(ps));
        ps.erase(unique(all(ps)), ps.end());
        rep(i,ps.size()-1){
            ret.push_back(Segment(ps[i], ps[i+1]));
        }        
    }
    return ret;
}

const int STOP = 0, GO = 1, BACK = -1;
int sign_type(Segment edge,Segment sign){
    //e.a -> sign.a > sign.b にする
    if(not does_include(edge, sign.a)) swap(sign.a, sign.b);    
    Point a = edge.a - sign.a , b = sign.b - sign.a;
    double dir = dot(a, b);
    if(abs(dir) < EPS) return STOP;
    else if(dir > 0) return GO;
    else return BACK;
}

vector<vector<int>> create_graph(
    map<Point,int> &idx,const vector<Segment> &edges, const vector<Segment> &signs){
    int n = idx.size();
    vector<vector<int>> G(n);
    for(Segment e : edges){
        bool flg1 = true, flg2 = true;
        for(Segment s : signs){
            if(does_include(e, s.a) or does_include(e, s.b)){
                int dir = sign_type(e,s);
                if(dir == GO) flg2 = false;
                else if(dir == BACK) flg1 = false;
                else flg1 = flg2 = false;
            }
        }
        if(flg1) G[idx[e.a]].push_back(idx[e.b]);
        if(flg2) G[idx[e.b]].push_back(idx[e.a]);

    }
    return G;
}


bool solve(){
    int n; cin >> n;
    if(n==0) return false;
    Point start,goal; cin >> start >> goal;
    vector<Segment> S(n); cin >> S;
    
    vector<Segment> edges,signs;
    tie(edges,signs)  = classify(S);
    edges = divide(edges);
    
    map<Point,int> idx;
    map<int,Point> ridx;
    int cnt = 0;
    for(Segment s : edges){
        if(not idx.count(s.a)) idx[s.a] = cnt, ridx[cnt++] = s.a;
        if(not idx.count(s.b)) idx[s.b] = cnt, ridx[cnt++] = s.b;
    }
    
    vector<vector<int>> G = create_graph(idx, edges, signs);

    // rep(i,len(G)){
    //     cout << ridx[i] << endl;
    //     cout << "\t>> ";
    //     for(int j : G[i]){
    //         cout << ridx[j] <<" ";
    //     }
    //     cout << endl;
    // }
    
    vector<int> ans = dijkstra_route(G, idx[start], idx[goal],ridx);

    if(ans.size() == 0 )cout << -1 << endl;
    else {
        rep(i,ans.size()) cout << ridx[ans[i]] <<endl;
        cout << 0 << endl;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
