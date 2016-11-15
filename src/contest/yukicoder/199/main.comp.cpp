#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }

const int INF = 1 << 30;

using Coordinate = double;
bool eq(Coordinate a, Coordinate b) {
    return abs(a - b) < 1e-6;
}
struct Point {
    Coordinate x, y;
    Point():x(0),y(0){}
    Point(Coordinate x,Coordinate y):x(x),y(y){}
    pair<Coordinate,Coordinate> to_pair() const { return make_pair(x,y); }
    bool operator == (const Point &a) const { return eq(x, a.x) && eq(y, a.y); }
    bool operator != (const Point &a) const { return !(*this == a); }
    Point operator + (const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator - (const Point& p) const { return Point(x - p.x, y - p.y); }
};
double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
istream &operator >> (istream& is, Point& p){ return is >> p.x >> p.y;}

class Solver {
  public:
    bool solve() {
        vector<Point> P(5); cin >> P;

        rep(i, 5) {
            int in = 0, out = 0;
            rep(j, 5) {
                if(i == j) continue;
                int a = 0, b = 0;
                Point v1 = P[j] - P[i];
                rep(k, 5) {
                    if(k == i or k == j) continue;
                    Point v2 = P[k] - P[i];
                    int sign = cross(v1, v2);
                    if(sign > 0) a++;
                    if(sign < 0) b++;
                }
                if(a > b) swap(a, b);
                in += (a == 1 and b == 2);
                out += (b == 3);
            }
            if(in != 2 or out != 2) {
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Solver s;
    s.solve();
    return 0;
}
