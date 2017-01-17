#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int n,i;
  cin>>n;
  vector<int> ans;
  for(i=0;i<n;i++){
    int temp;cin>>temp;
    if(ans.size()>0 && ans[ans.size()-1]<temp)ans.push_back(temp);
    else if (ans.size()==0)ans.push_back(temp);
    else for(int j=ans.size()-2;j>=0;j--)
	   if(j==0 && ans[j]>temp)ans[j]=temp;
	   else if(ans[j]<temp&&ans[j+1]>temp)ans[j+1]=temp;
  }
  cout<<ans.size()<<endl;
}
