#include <string>
#include <vector>

using namespace std;

#define rep(i,j) for(int i=0;i<(j);i++)

class DevuAndPlantingTrees {
	public:
	int maximumTreesDevuCanGrow(vector <string> garden) {
          if(garden[0].size()==1)return 1;

          vector<bool> v(garden[0].size(),false);
          rep(i,v.size()){
            if(garden[0][i]=='*' or garden[1][i]=='*')v[i]=true;
          }
          
          rep(i,v.size()-1){
            if(i==0 and v[1]==false)v[0]=true;
            if(i>0 and v[i-1]==false and v[i+1]==false)v[i]=true;
          }
          if(v[v.size()-2]==false)v.back()=true;

          int ans=0;
          rep(i,v.size())if(v[i])ans++;
          return ans;
	}
};
