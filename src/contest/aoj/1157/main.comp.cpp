#include <bits/stdc++.h>
using namespace std;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
const int INF = 1 << 30;
const double EPS = 1e-8;

template<class T> bool eq(T a, T b) { return abs(a - b) < EPS; }
using Point = complex<double>;
#define X(a) real(a)
#define Y(a) imag(a)
istream &operator >> (istream& is, Point& p) { double a, b; is >> a >> b; p.X(a); p.Y(b); return is; }

double dot(Point a, Point b) { return a.X() * b.X() + a.Y() * b.Y(); }
double cross(Point a, Point b) { return a.X() * b.Y() - a.Y() * b.X(); }
double length2(Point p) { return p.X() * p.X() + p.Y() * p.Y(); }
double length(Point p) { return sqrt(length2(p)); }
double distance(Point a, Point b) { return length(a - b); }
Point unit(Point p) { return p / length(p); }

enum ccw_t {
    COUNTER_CLOCK_WISE = 1,
    CLOCK_WISE = -1,
    STRAIGHT_C_A_B = 2,
    STRAIGHT_A_B_C = -2,
    STRAIGHT_A_C_B = 0
};

ccw_t ccw(Point a, Point b, Point c){
    Point ab = b - a, ac = c - a;
    if( cross(ab,ac) > EPS ) return COUNTER_CLOCK_WISE; // +1 a-b-c 反時計回り
    if( cross(ab,ac) < -EPS ) return CLOCK_WISE;        // -1 a-b-c 時計回り
    if( dot(ab,ac) < -EPS ) return STRAIGHT_C_A_B;      // +2 c-a-b
    if( length2(ab) < length2(ac) )return STRAIGHT_A_B_C;     // -2 a-b-c or a==b
    return STRAIGHT_A_C_B;                              //  0 a-c-b or b==c or a==c
}

struct Segment {
    Point a, b;
    Segment(){}
    Segment(const Point& a, const Point& b):a(a), b(b){}
    pair<Point,Point> to_pair() const { return make_pair(a,b); }
    bool operator == (Segment s) const { return to_pair() == s.to_pair();}
    bool operator != (Segment s) const { return !(*this == s); }
    friend istream &operator >> (istream& is, Segment &s){ return is >> s.a >> s.b;}
    friend ostream &operator << (ostream& os, Segment s) { return os << s.a << "->" << s.b;}
};
double length(Segment s) { return distance(s.a, s.b); }
bool contain(Segment s, Point p) {
    return ccw(s.a, s.b, p) == 0; // STRAIGHT_A_C_B;
}
Point projection(Segment s, Point p) {
    Point v = s.b - s.a;
    double t = dot(p - s.a, v) / length2(v); // 長さ
    return v * t + s.a;
}
Point closest_point(Segment s, Point p) {
    Point pp = projection(s, p);
    return contain(s, pp) ? pp : distance(s.a, p) < distance(s.b, p) ? s.a : s.b;
}
double distance(Segment s, Point p) {
    if( dot(s.b - s.a ,p - s.a) < EPS ) return distance(p, s.a);
    if( dot(s.a - s.b ,p - s.b) < EPS ) return distance(p, s.b);
    return abs(cross(s.b - s.a, p - s.a) / length(s));
}
bool intersect(Segment s, Segment t) { // 交差判定
    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 and ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}


struct Rectangle {
    array<Point, 4> p;
    // order:
    //     3 2
    //     0 1
    Rectangle(const array<Point, 4> &pp):p(pp) {
        // 上の順になるように並べる
        rep(i, 3) repeat(j, i + 1, 4) {
            int cnt = 0;
            rep(k, 4) if(k != i and k != j){
                cnt += ccw(p[i], p[j], p[k]) == COUNTER_CLOCK_WISE;
            }
            if(cnt == 2) {
                swap(p[i + 1], p[j]);
                break;
            }
        } 
    }
    bool intersect(Segment s) {
        bool res = false;
        rep(i, 4) res |= ::intersect(s, Segment(p[i], p[(i + 1) % 4]));
        return res;
    }
    bool contain(Point pp) {
        bool flg = true;
        rep(i, 4) flg &= ccw(p[i], p[(i + 1) % 4], pp) == COUNTER_CLOCK_WISE;
        return flg;
    }
    bool contain(Segment s) {
        return contain(s.a) and contain(s.b);
    }
    Point closest_point(Point pp) {
        Point res = p[0];
        rep(i, 4) {
            Point ppp = ::closest_point(Segment(p[i], p[(i+1)%4]), pp);
            if(distance(res, pp) > distance(ppp, pp)) res = ppp;
        }
        return res;
    }
    Point closest_point(Segment s) {
        Point res = p[0];
        repeat(i, 1, 4) if(distance(s, res) > distance(s, p[i])) res = p[i];
        for(Point pp : {s.a, s.b}) {
            Point ppp = closest_point(pp);
            if(distance(s, res) > distance(s, ppp)) res = ppp;
        }
        return res;
    }
};


class Solver {
  public:
    Segment S;
    vector<Point> minP, maxP;
    vector<double> H;
    bool solve() {

        int N; cin >> N;
        if(not N) return false;
        cin >> S;
        minP.resize(N);
        maxP.resize(N);
        H.resize(N);
        rep(i, N) cin >> minP[i] >> maxP[i] >> H[i];
        
        double max_r = INF;

        rep(i, N) {            
            Rectangle rect({minP[i], maxP[i], Point(minP[i].X(), maxP[i].Y()), Point(maxP[i].X(), minP[i].Y())});

            if(rect.intersect(S) or rect.contain(S)) {
                cout << 0 << endl;
                return true;
            }

            double d = distance(S, rect.closest_point(S));
            double r = (d * d + H[i] * H[i]) / (2 * H[i]);
            if(r < H[i]) r = d;
            set_min(max_r, r);
        }

        cout << max_r << endl;
        return true;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(1) {
        Solver s;
        if(not s.solve()) break;
    }
    return 0;
}
