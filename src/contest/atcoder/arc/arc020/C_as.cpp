#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
typedef long long ll;typedef unsigned long long ull;
template <typename T>class irange {public:class iterator {public:iterator(T value) : value(value), step(1) {}iterator(T value, T step) : value(value), step(step) {}bool operator != (const iterator & other) const {return value != other.value;}T const & operator * () const {return value;}iterator & operator ++ () {value += step;return *this;}private:T value;T step;};public:irange(T last) : first(0), last(last), step(1) {}irange(T first, T last) : first(first), last(last), step(1) {}irange(T first, T last, T step) : first(first), last(last), step(step) {}iterator begin() const {return iterator(first, step);}iterator end() const {if (step == 0) return iterator(last, step);if (0 < step and last < first) return iterator(first, step);if (step < 0 and first < last) return iterator(first, step);return iterator(first + ((last - first + (0 < step ? -1 : 1)) / step + 1) * step, step);}typedef T value_type;private:T const first;T const last;T const step;};typedef irange<long long> lrange;inline lrange range(lrange::value_type last) { return lrange(last); }inline lrange range(lrange::value_type first, lrange::value_type last) { return lrange(first, last); }inline lrange range(lrange::value_type first, lrange::value_type last, lrange::value_type step) { return lrange(first, last, step); }template <typename T> lrange index_of(const T & a) { return range(a.size()); }inline lrange range(std::istream & input) { lrange::value_type i; input >> i; return range(i); }inline lrange reverse_range(lrange::value_type last) { return range(last-1,-1,-1); }inline lrange reverse_range(lrange::value_type first, lrange::value_type last) { return range(last-1,first-1,-1); }inline lrange inclusive_range(lrange::value_type last) { return range(last+1); }inline lrange inclusive_range(lrange::value_type first, lrange::value_type last) { return range(first,last+1); }template <typename T> lrange reverse_index_of(const T & a) { return range(a.size()-1,-1,-1); }
using namespace std;
int flog10i(ll x) {
    int n = 0;
    ll y = 1;
    while (10 * y <= x) {
        n += 1;
        y *= 10;
    }
    assert (n == floor(log10(x)));
    return n;
}
ll powi(ll x, ll y) {
    ll z = 1;
    for (int i = 0; i < y; ++i) {
        z *= x;
    }
    return z;
}
int main() {
    assert (flog10i(1) == 0);
    assert (flog10i(9) == 0);
    assert (flog10i(10) == 1);
    assert (flog10i(99) == 1);
    assert (flog10i(100) == 2);
    assert (powi(10,0) == 1);
    assert (powi(10,1) == 10);
    assert (powi(10,2) == 100);
    assert (powi(10,flog10i(999)) == 100);
    assert (powi(10,flog10i(1000)) == 1000);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> a(n), l(n); for (int i : range(n)) cin >> a[i] >> l[i];
    ll b; cin >> b;
    reverse(a.begin(), a.end());
    reverse(l.begin(), l.end());
    ll result = 0;
    ll e = 1;
    for (int i : range(n)) {
        int m = ceil(log2(l[i])) + 7;
        vector<ll> xs(m);
        vector<ll> es(m);
        xs[0] = a[i] % b;
        es[0] = (powi(10,flog10i(a[i])) * 10) % b;
        for (int j : range(1,m)) {
            xs[j] = ((xs[j-1] * es[j-1]) % b + xs[j-1]) % b;
            es[j] = (es[j-1] * es[j-1]) % b;
	    printf("xs[%d] = %lld\n",j,xs[j]);
        }
        ll acc = 0;
        ll f = 1;
        assert (m < 60);
        for (int j : range(m)) {
            if (l[i] & (1ll << j)) {
                acc = ((xs[j] * f) % b + acc) % b;
                f = (f * es[j]) % b;
            }
        }
        result = (result + (acc * e) % b) % b;
        e = (e * f) % b;
    }
    cout << result << endl;
    return 0;
}
