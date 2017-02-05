#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include<stack>
typedef long long  int64;
typedef long long  ll;
typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()
using namespace std;

class LuckyCycle {
public:
  struct Ret{
    int f,s,len;
  };
  int node_num;
  
  
  Ret get_road(vector<vector<int>> &G,int goal,int now ,int pre){
    rep(i,node_num){
      if(i!=pre){
        if(G[now][i]>0){
          if(i==goal){
            Ret tmp = (Ret){0,0,1};
            if(G[now][i]==4)tmp.f++;
            else if(G[now][i]==7)tmp.s++;
            return tmp;
          }
          else{
            Ret tmp = get_road(G, goal, i, now);
            if(tmp.len>0){
              tmp.len++;
              if(G[now][i]==4)tmp.f++;
              else if(G[now][i]==7)tmp.s++;
              return tmp;
            }
          }
        }
      }
    }
    return (Ret){-1,-1,-1};
  }

  
   vector <int> getEdge( vector <int> edge1, vector <int> edge2, vector <int> weight ) {
     vector<vector<int>> G(edge1.size()+1,vector<int>(edge1.size()+1,-1));
     rep(i,edge1.size()){
       G[edge1[i]-1][edge2[i]-1]=weight[i];
       G[edge2[i]-1][edge1[i]-1]=weight[i];
     }

     node_num=edge1.size()+1;

     rep(i,node_num){
       rep(j,i){
         if(G[i][j]>0)continue;
         Ret tmp =get_road(G, j, i, -1);
         if(tmp.len%2!=0 && abs(tmp.f-tmp.s)==1){
           vector<int> ans;
           ans.push_back(min(i+1,j+1));
           ans.push_back(max(i+1,j+1));
           ans.push_back((tmp.f>tmp.s ? 7 : 4));
           return ans;
         }
       }
     }
     vector<int> ans;
     return ans;
   }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int edge1[]               = {1};
			int edge2[]               = {2};
			int weight[]              = {4};
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = LuckyCycle().getEdge(vector <int>(edge1, edge1 + (sizeof edge1 / sizeof edge1[0])), vector <int>(edge2, edge2 + (sizeof edge2 / sizeof edge2[0])), vector <int>(weight, weight + (sizeof weight / sizeof weight[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int edge1[]               = {1, 3, 2, 4};
			int edge2[]               = {2, 2, 4, 5};
			int weight[]              = {4, 7, 4, 7};
			int expected__[]          = {1, 5, 7 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = LuckyCycle().getEdge(vector <int>(edge1, edge1 + (sizeof edge1 / sizeof edge1[0])), vector <int>(edge2, edge2 + (sizeof edge2 / sizeof edge2[0])), vector <int>(weight, weight + (sizeof weight / sizeof weight[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int edge1[]               = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
			int edge2[]               = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
			int weight[]              = {4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7};
			int expected__[]          = {1, 12, 7 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = LuckyCycle().getEdge(vector <int>(edge1, edge1 + (sizeof edge1 / sizeof edge1[0])), vector <int>(edge2, edge2 + (sizeof edge2 / sizeof edge2[0])), vector <int>(weight, weight + (sizeof weight / sizeof weight[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int edge1[]               = {1, 2, 3, 5, 6};
			int edge2[]               = {2, 3, 4, 3, 5};
			int weight[]              = {4, 7, 7, 7, 7};
			int expected__[]          = {1, 4, 4 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = LuckyCycle().getEdge(vector <int>(edge1, edge1 + (sizeof edge1 / sizeof edge1[0])), vector <int>(edge2, edge2 + (sizeof edge2 / sizeof edge2[0])), vector <int>(weight, weight + (sizeof weight / sizeof weight[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int edge1[]               = ;
			int edge2[]               = ;
			int weight[]              = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = LuckyCycle().getEdge(vector <int>(edge1, edge1 + (sizeof edge1 / sizeof edge1[0])), vector <int>(edge2, edge2 + (sizeof edge2 / sizeof edge2[0])), vector <int>(weight, weight + (sizeof weight / sizeof weight[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int edge1[]               = ;
			int edge2[]               = ;
			int weight[]              = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = LuckyCycle().getEdge(vector <int>(edge1, edge1 + (sizeof edge1 / sizeof edge1[0])), vector <int>(edge2, edge2 + (sizeof edge2 / sizeof edge2[0])), vector <int>(weight, weight + (sizeof weight / sizeof weight[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int edge1[]               = ;
			int edge2[]               = ;
			int weight[]              = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = LuckyCycle().getEdge(vector <int>(edge1, edge1 + (sizeof edge1 / sizeof edge1[0])), vector <int>(edge2, edge2 + (sizeof edge2 / sizeof edge2[0])), vector <int>(weight, weight + (sizeof weight / sizeof weight[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
