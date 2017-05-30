#include <message.h>
#include <cassert>
#include <cstdio>
#include <weird_editor.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
const ll MOD = 1000000000 + 7;

ll modpow(ll a,ll n){
  if(n==0)return 1;
  if(n%2==1)return a*modpow(a, n-1)%MOD;
  ll t=modpow(a, n/2);
  return t*t%MOD;
}

int main() {    
    ll N = GetNumberLength();
    ll Nodes = min<ll>(NumberOfNodes(), N);
    
    
    ll one = N / Nodes + 1;
    int id = MyNodeId();

    for(int i = 0;;i++) {
        ll s = one * i;
        if(s >= N) {
            Nodes = i;
            break;
        }
    }
    
    ll s = one * id, e = min(one * (id + 1), N);
    if(s >= N) return 0;

    vector<ll> digits, dec;
    for(int i = s; i < e; i++) {
        ll d = GetDigit(i);
        digits.push_back(d);
        while(dec.size() and digits[dec.back()] < d) dec.pop_back();
        dec.push_back(i-s);
    }
    PutLL(0, digits[dec.front()]);
    PutLL(0, digits[dec.back()]);
    Send(0);    

    //debug(digits);
    
    if(id == 0) {
        vector<ll> mxs(Nodes), mns(Nodes);
        rep(i, Nodes) {
            Receive(i);
            mxs[i] = GetLL(i);
            mns[i] = GetLL(i);
        }
        //debug(mxs);
        //debug(mns);
        int mx_id = 0;
        vector<ll> best_seq;
        rep(i, Nodes) {
            vector<ll> seq;
            repeat(j, i, Nodes) if(seq.size() == 0 or seq.back() >= mxs[j]) seq.push_back(mxs[j]);
            rep(j, min(seq.size(), best_seq.size())) {
                if(seq[j] > best_seq[j]) {
                    mx_id = i;
                    best_seq = seq;
                    break;
                }
                if(seq[j] < best_seq[j]) break;
            }
        }
        vector<ll> nxt_mx(Nodes);
        {
            ll mmx = -1;
            int i = (mx_id - 1 + Nodes) % Nodes;
            rep(ii, Nodes) {
                nxt_mx[i] = mmx;
                if(mmx < mxs[i]) mmx = mxs[i];
                i = (i - 1 + Nodes) % Nodes;
            }
        }
        //debug(mx_id);
        rep(i, Nodes) {
            PutLL(i, mx_id);
            PutLL(i, nxt_mx[i]);
            Send(i);
        }
    }
    
    Receive(0);
    int mx_id = GetLL(0), nxt_mx = GetLL(0);
    
    if(mx_id <= id) {
        ll beg = 0, zeros = 0;        
        if(mx_id == id) {
            beg = dec.front();
            zeros = dec.front();
        }
        ll ans = 0, now_mx = 1LL<<60;
        for(int i = beg; i < digits.size(); i++) {
            if(digits[i] == 0) zeros++;
            else {
                if(now_mx >= digits[i] and digits[i] >= nxt_mx) {
                    ans = (ans * 10 + digits[i]) % MOD;
                } else zeros++;
                if(now_mx < digits[i]) now_mx = digits[i];
            }
        }
        //cerr << ans << " " << zeros << endl;
        PutLL(0, ans);
        PutLL(0, zeros);
        PutLL(0, digits.size() - zeros);
    } else if(mx_id > id) {
        PutLL(0, 0);
        PutLL(0, e - s);
        PutLL(0, 0);
        // cerr << 0 << " " << e-s << endl;
    } else assert(0);
    
    Send(0);

    if(id == 0) {
        ll ans = 0, sum_zeros = 0, sum_mults = 0;
        int i = (mx_id - 1 + Nodes) % Nodes;
        rep(ii, Nodes) {            
            Receive(i);
            ll sub = GetLL(i);
            ll zeros = GetLL(i);
            ll mults = GetLL(i);
            sum_zeros += zeros;            
            ans += sub * modpow(10, sum_mults) % MOD;
            ans %= MOD;
            sum_mults += mults;
            i = (i - 1 + Nodes) % Nodes;
        }
        ans *= modpow(10, sum_zeros) % MOD;
        ans %= MOD;
        cout << ans << endl;
    }

    return 0;
}
