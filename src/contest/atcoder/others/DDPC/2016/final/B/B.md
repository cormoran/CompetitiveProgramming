---
title        : DDPC2016-Final-B
date         : 2016-02-22T21:18:00+09:00
contests     : atcoder
problemtypes :

---

# [DDPC特別ビュッフェⅡ](http://discovery2016-final.contest.atcoder.jp/tasks/discovery_2016_final_b)

最初、二分探索とか、貪欲とかいろいろ考えたけどよくわからなくていろいろ苦しんだ。
解けてる人が以外と少なかったようで、解けてよかった。

<!--more-->

## 問題概要

N種類の料理がある。料理i(1<=i<=N)には美味しさAiと、なくなる時刻Tiが決まっている。

時刻０から始める。１秒に１種の料理が取れる時、とった料理の美味しさの総和をX以上にするのに必要な時刻の最小値を求めよ。

各種類の料理は一度ずつしか取れない。

## 解法

いろいろな解法があるが、求める時刻をtとしてtを二分探索するのが簡単らしい。

### 二分探索の解法

tが決まれば、後ろから取る料理を決めていくことができる。

各時間i(<t)では、i以降の時刻でなくなる料理で、まだ取っていないものの内、美味しさ最大のものを取ることにすれば良い。


### 自分の解法

美味しいものから取っていく貪欲。

そのまま順に取ると、遅い時間になくなる美味しいものを最初の方で取ってしまう場合に無駄ができる可能性があるので、どの料理も、できるだけ遅い時刻に取ることにする方針で行った。

1. まず、料理を美味しさの大きい順、なくなる時刻の早い順でソートする（前者優先）

2. ソートした列を前から見て、各料理を取る時刻を決めていく。料理iをとる時刻は、Tiより早い時刻のうち、Tiにできるだけ近く、まだ空いている時刻に仮決定する。そのような時刻が存在しなければ料理iをとるのを諦める。

3. 美味しさの総和がXを超えたら、それまでに取った料理の数Mが答え。

仮決定した時刻と実際にその料理をとる時刻は違う可能性があるが、空いている時刻に前倒ししていくことでMより前に、取ることにしたすべての料理を埋められる。

 料理iをとる時刻を決めるのに、愚直にやるとO(N)かかるので全体で最悪O(N^2)になって間に合わない。
 
 そこで、tiに入れようとして、空きを探した結果,tjに入れた、という結果を記録しておく。

 それを$jumpto[ti] = tj$とすると、tkに入れようとするときに実際に入れられる場所tlは、

<div>$$  tl < \min \{ jumpto[t] , t \in [tk,Tmax) \} $$</div>

となる。

RMQを使えば上のminはO(logN)で求められ、これを利用すると配列全体の線形走査は全体合わせて１回になるので、O(NlogN)で答えが出る。



~~~

#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<cmath>
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()
 
template<typename T>
ostream& operator << (ostream &os , const vector<T> &v){ rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os; }
template<typename T>
istream& operator >> (istream &is , vector<T> &v){ rep(i,v.size()) is >> v[i]; return is; }
 
 
#include<functional>
using Index = int;
template<typename Data>
class SegmentTree{
  public:
    int n;
    vector<Data> data;
    function< Data(Data,Data) > selector;
    Data default_val;
    SegmentTree(int n, function< Data(Data,Data) > selector,Data default_val)
            :selector(selector),default_val(default_val){
        this->n = 1;
        while(this->n < n) this->n *= 2;
        data.resize(2*(this->n)-1, default_val);
    }
    void update(Index k,Data val){
        k += n-1;
        data[k] = val;
        while( k > 0 ){
            k = (k-1)/2;
            data[k] = selector(data[k*2+1], data[k*2+2]);
        }
    }
    int query(Index a,Index b){
        return search(a,b+1,0,0,n);
    }
  private:
    Data search(Index a,Index b,Index k,Index l,Index r){
        if( r <= a or b <= l ) return default_val;
        if( a <= l and r <= b ) return data[k];
        else {
            Data vl = search(a, b, k*2+1, l, (l+r)/2);
            Data vr = search(a, b, k*2+2, (l+r)/2, r);
            return selector(vl, vr);
        }
    }
};


const int INF = 1 << 30; 

bool solve(){
    int n,x; cin >> n >> x;
    vector<pair<pair<int,int>,int>> A(n);
    rep(i, n){
        cin >> A[i].first.second;
        A[i].first.second = -1 * min(A[i].first.second, n);
    }
    rep(i,n){
        cin >> A[i].first.first;
        A[i].second = i;
    }
    sort( all(A) ,greater<pair<pair<int,int>,int>>()); // 美味しい順、時間早い順
    vector<bool> used_time(n);
    SegmentTree<int> jump_to(n,[](const int a,const int b){return min(a,b);}, INF); // RMQ
    ll sum = 0;
    ll ans = 0;
    rep(i,n){ // 各料理について
        int t = A[i].first.second * -1 - 1;
        while(t >= 0){ // 取る時刻を後ろから探す
            if(not used_time[t]){
                sum += A[i].first.first;
                ans++;
                if(sum >= x){
                    cout << ans << endl;
                    return 0;
                }
                used_time[t] = true;
                break;
            } else {
                int k = t;
                while( t >= 0 and used_time[t]){
                    int nxt = jump_to.query(t,n-1);
                    if(nxt != INF and nxt < t) t = nxt;
                    else t--;
                }
                jump_to.update(k, t);
            }
        }
    }
    cout << -1 << endl;
    return false;
}
 
int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}

~~~