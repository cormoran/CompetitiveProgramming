/*P23 Ants from POJ1852
Sample
2
10 3
2 6 7
214 7
11 12 7 13 176 23 191

Answer
4 8 38 207

14/9/4 mem 4152K/time 579ms
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int m;
  cin>> m;
  for(int cnt=0;cnt<m;cnt++)
    {
      int l,n;
      cin>>l>>n;
      int x[1000000];
      int mx=0,mn=0;
      for(int i=0;i<n;i++){
	cin >> x[i];
	mx=max(mx,max(x[i],l-x[i]));
	mn=max(mn,min(x[i],l-x[i]));
      }
      printf("%d %d\n",mn,mx);
    }
  return 0;
}
