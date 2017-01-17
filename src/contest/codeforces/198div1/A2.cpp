#include<cstdlib>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
	std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  static ll a[128 * 1024];
  ll molecule = 0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    molecule += a[i];
  }
  sort(a, a + n);
  
  ll last = 0;
  for (int i = 1; i < n; ++i) {
    last += (a[i] - a[i - 1]) * i;
    molecule += 2 * last;
  }

  ll denominator = n;
  ll g = gcd(molecule, denominator);
  molecule /= g;
  denominator /= g;
  cout << molecule << " " << denominator << endl;
}
