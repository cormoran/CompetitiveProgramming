#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct people
{
  long long num;
  long long old;
  bool operator<(const people& one)const
  {
    return old<one.old;
  }
  bool operator>(const people& one)const
  {
    return old>one.old;
  }  
}people;
  
int main()
{
  long long  n,k;
  cin >>n>>k;
  people x[n];
  long long i;
  priority_queue<people> box;
  for(i=0;i<n;i++)
    {
      cin>>x[i].old;
      x[i].num=i;
      box.push(x[i]);
      if(i>=k)
	{
	  box.pop();
	  cout<<box.top().num+1<<endl;
	}
      else if(i==k-1)cout<<box.top().num+1<<endl;
    }
  return 0;
}
