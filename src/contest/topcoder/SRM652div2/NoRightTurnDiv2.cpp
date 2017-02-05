#include <bits/stdc++.h>
using namespace std;
typedef long long int64;typedef int int32;
typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) (v).begin(),(v).end()

class NoRightTurnDiv2 {
public:

  
  vector <int> findPath( vector <int> x, vector <int> y ) {

    //couterclockwise : 反時計回り
    auto is_counterclockwise = [&](int a,int b,int c)->bool{
      int v1_x=x[c]-x[b],v1_y=y[c]-y[b];
      int v2_x=x[a]-x[b],v2_y=y[a]-y[b];
      int crossproduct = v1_x*v2_y-v1_y*v2_x;
      return crossproduct >0 ;
    };

    int now=-1;
    //一番外側の点を探す
    rep(i,x.size()){
      if(now<0 or x[now]<x[i] or (x[now]==x[i] && y[now]<y[i] ))now=i;
    }

    vector<int> ans;
    vector<int> used(x.size(),false);

    ans.push_back(now);
    used[now]=true;
    while(ans.size()<x.size()){
      int nxt=-1;
      rep(j,x.size()){
	//a,と残った任意のcに対してa-b-cが反時計回りになるようなbを探す
	if(!used[j] and ( nxt<0 or is_counterclockwise(now,j,nxt) ))nxt=j;
      }
      ans.push_back(nxt);
      used[nxt]=true;
      now=nxt;
    }
    return ans;
    
   }
};

// BEGIN CUT HERE
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<map>

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
			int x[]                   = {-10, 0, 10};
			int y[]                   = {10, -10, 10};
			int expected__[]          = {0, 1, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = NoRightTurnDiv2().findPath(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {0,0,-3,-3,3,3};
			int y[]                   = {-1,1,-3,3,-3,3};
			int expected__[]          = {0, 4, 5, 3, 2, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = NoRightTurnDiv2().findPath(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {10,9,8,7,6,5,4,3,2,1};
			int y[]                   = {1,4,9,16,25,36,49,64,81,100};
			int expected__[]          = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = NoRightTurnDiv2().findPath(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {0, 2,-2, 4,-4, 2,-2, 0};
			int y[]                   = {1, 2, 2, 4, 4, 6, 6, 5};
			int expected__[]          = {4, 2, 0, 1, 3, 5, 6, 7 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = NoRightTurnDiv2().findPath(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {-76,98,83,58,-15,94,21,55,80,84,-39,-90,-46,100,-80,-49,-2,-70,36,48,88,10, 55,-56,22,67,31,81,100,-39,64,-62,-7,45,-82,-24,51,-33,53,11,20,-74,-83,47, 9,39,42,63,-97,94};
			int y[]                   = {-90,68,91,-92,-6,88,99,10,39,-69,-61,-4,71,-5,90,-51,21,-53,-21,-86,41,-9, 42,-23,-4,12,94,-59,55,18,70,-88,-86,-17,-97,-33,87,80,91,-80,-79,-79,-78, -99,57,67,-52,-46,61,-10};
			int expected__[]          = {39, 32, 40, 31, 19, 27, 47, 46, 0, 34, 43, 3, 9, 13, 28, 1, 5, 2, 6, 14, 48, 42, 41, 49, 20, 38, 26, 37, 12, 11, 17, 10, 33, 25, 8, 30, 36, 44, 29, 23, 15, 18, 7, 22, 45, 16, 4, 35, 24, 21 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = NoRightTurnDiv2().findPath(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = NoRightTurnDiv2().findPath(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = NoRightTurnDiv2().findPath(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = NoRightTurnDiv2().findPath(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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
