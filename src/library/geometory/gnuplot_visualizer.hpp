#pragma once
#include "common/simple_header.hpp"
#include "./type.hpp"

struct GnuplotVisualizer {
    fstream f;
    stringstream sh, sc; // head, content
    GnuplotVisualizer(string path = "data.gnuplot") {
        f.open(path, fstream::out);
        f << "set xrange [-20:20]" << endl;
        f << "set yrange [-20:20]" << endl;
        f << "set size ratio 1 1" << endl;
        _init();
    }
    ~GnuplotVisualizer() { f.close(); }
    void _init() {
        sh = stringstream();
        sc = stringstream();
        sh << "plot ";
    }
    void next_frame() {
        f << sh.str() << "'-' \n" << sc.str() << "e" << endl;
        f << "pause -1" << endl;
        _init();
    }
    void point_head()   { sh << " '-' ,"; }
    void segment_head() { sh << " '-' w l lw 3 ,"; }
    void circle_head()  { sh << " '-' with circles ,"; }
    void end() { sc << "e\n"; }
};

GnuplotVisualizer gv; // グローバルにおいておく
// show しすぎるとメモリ確保できなくてエラーを吐く
void show_point__(const Point &p) { gv.sc << X(p) << " " << Y(p) << endl; }
void show_segment__(const Segment &s) { show_point__(s.a); show_point__(s.b); }
void show(Point p)    { gv.point_head();   show_point__(p);   gv.end(); }
void show(Segment s)  { gv.segment_head(); show_segment__(s); gv.end(); }
void show(Circle &c)  { gv.circle_head(); gv.sc << X(c.c) << " " << Y(c.c) << " " << c.r << endl; gv.end(); }
void show(Polygon po) {
    gv.segment_head();
    for(auto &p : po.p) show_point__(p);
    if(po.p.size() > 0) show_point__(po.p.front());
    gv.end();
}
void show(const FanCircle &fc) {
    gv.circle_head();
    gv.sc << X(fc.c) << " " << Y(fc.c) << " " << fc.r << " " << fc.a * 180 / M_PI << " " << fc.b * 180 / M_PI << endl;
    gv.end();
}