---
title        : atcoder-CodeFestival-2015-Thanks-D
date         : 2015-12-05
contests     : atcoder
status        : AC
problemtypes :

---

# D.暴露

<!--more-->

## 問題概要

  テストをした。各生徒は自分の成績と全員の総合得点を知っている。２種類のクエリバラバラにが与えられる。

- 情報クエリ　：　生徒 b が 生徒 c の得点を知る

- 質問クエリ　：　生徒 b が 今までに得た情報をもとに生徒 c の得点の取りうる範囲（何点以上何点以下か）を判定する

各質問クエリの答えを出力せよ

## 解法

  各生徒で知っている人と知っている総合点を覚えておき、計算する。取りうる点数の範囲は0から100点である。
  


~~~
typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}
template<typename T>istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R> void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}

struct Student{
    int p;
    int knowsum;
    set<int> knows;
};

bool solve(){
    int n; cin >> n;
    int sum = 0;
    vector<Student> s(n);
    rep(i,n){
        cin >> s[i].p;
        sum += s[i].p;
        s[i].knowsum = s[i].p;
        s[i].knows.insert(i);
    }
    int m; cin >> m;
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        b--;c--;
        if(a == 0){
            s[b].knows.insert(c);
            s[b].knowsum += s[c].p;
        } else {
            if(s[b].knows.count(c)){
                printf("%d %d\n",s[c].p,s[c].p);
            } else {
                int left = sum - s[b].knowsum;
                int unknown = n - s[b].knows.size() -1;
                printf("%d %d\n",
                       max(0, left - 100 * unknown),
                       min(100, left));
            }
        }
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~