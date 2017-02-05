#include <bits/stdc++.h>
using namespace std;
typedef long long int64;typedef int int32;
typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) (v).begin(),(v).end()
const int INF=1<<30;
class SuccessiveSubtraction2 {
public:
     vector <int> calc( vector <int> a, vector <int> p, vector <int> v ) {
     vector<int > answers;
     rep(i,p.size()){
       a[p[i]]=v[i];

       int DP[2000][5];
       rep(j,2000)rep(k,5)DP[j][k]=-INF;
       DP[0][0]=a[0];
       DP[1][0]=a[0]-a[1];
       
       repeat(j,2,a.size()){
	 //out of parenthes
	 DP[j][0]=DP[j-1][0]-a[j];
	 //in first parenthes (except first one)
	 DP[j][1]=max(DP[j-1][1]+a[j],DP[j-1][0]+a[j]);
	 //out of parenthes after first parenthes 
	 DP[j][2]=max(DP[j-1][2]-a[j],DP[j-1][1]-a[j]);
	 //in second parenthes (except first one)
	 DP[j][3]=max(DP[j-1][3]+a[j],DP[j-1][2]+a[j]);
	 //out of parenthes after second parenthes 
	 DP[j][4]=max(DP[j-1][4]-a[j],DP[j-1][3]-a[j]);
       }

       int ans=-INF;
       rep(i,5)ans=max(DP[a.size()-1][i],ans);
       answers.push_back(ans);
       
     }

     return answers;
     
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
			int a[]                   = {1, 2, 3, 4, 5};
			int p[]                   = {1, 2, 0, 4, 3};
			int v[]                   = {3, 9, -10, 5, 1};
			int expected__[]          = {10, 16, 5, 5, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = SuccessiveSubtraction2().calc(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(v, v + (sizeof v / sizeof v[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int a[]                   = {-100, -100, -100, -100, -100};
			int p[]                   = {0, 1, 2, 3, 4};
			int v[]                   = {0, 0, 0, 0, 0};
			int expected__[]          = {400, 300, 200, 100, 0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = SuccessiveSubtraction2().calc(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(v, v + (sizeof v / sizeof v[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int a[]                   = {83, 0, 25, 21};
			int p[]                   = {0, 3, 2, 1, 3, 1, 2};
			int v[]                   = {10, -90, 33, 52, -100, 0, 45};
			int expected__[]          = {56, 125, 133, 81, 91, 143, 155 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = SuccessiveSubtraction2().calc(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(v, v + (sizeof v / sizeof v[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int a[]                   = {1};
			int p[]                   = {0, 0, 0, 0};
			int v[]                   = {10, -10, 100, -100};
			int expected__[]          = {10, -10, 100, -100 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = SuccessiveSubtraction2().calc(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(v, v + (sizeof v / sizeof v[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int a[]                   = {-11, -4, 28, 38, 21, -29, -45, 11, -58, -39, 92, 35, -56, -6, 29, -2, 61, 10, -29, -63};
			int p[]                   = {19, 5, 3, 10, 4, 18, 5, 2, 0, 15};
			int v[]                   = {-19, 21, 7, -66, 38, -39, -22, 24, -32, 13};
			int expected__[]          = {451, 443, 412, 440, 457, 467, 468, 464, 443, 458 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = SuccessiveSubtraction2().calc(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(v, v + (sizeof v / sizeof v[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int a[]                   = ;
			int p[]                   = ;
			int v[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = SuccessiveSubtraction2().calc(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(v, v + (sizeof v / sizeof v[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int a[]                   = ;
			int p[]                   = ;
			int v[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = SuccessiveSubtraction2().calc(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(v, v + (sizeof v / sizeof v[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int a[]                   = ;
			int p[]                   = ;
			int v[]                   = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = SuccessiveSubtraction2().calc(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(v, v + (sizeof v / sizeof v[0])));
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
