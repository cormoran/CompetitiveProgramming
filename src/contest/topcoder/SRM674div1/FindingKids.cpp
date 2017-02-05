#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pll;
#define rep(i,j) for(ll i=0;i<j;i++)
#define repeat(i,j,k) for(ll i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()

class FindingKids {
public:
   long long getSum( int n, int q, int A, int B, int C ) {

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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
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
			int n                     = 5;
			int q                     = 2;
			int A                     = 0;
			int B                     = 1;
			int C                     = 1;
			long long expected__      = 15;

			std::clock_t start__      = std::clock();
			long long received__      = FindingKids().getSum(n, q, A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 5;
			int q                     = 4;
			int A                     = 3;
			int B                     = 2;
			int C                     = 1;
			long long expected__      = 43376;

			std::clock_t start__      = std::clock();
			long long received__      = FindingKids().getSum(n, q, A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 200000;
			int q                     = 200000;
			int A                     = 12345;
			int B                     = 67890;
			int C                     = 111213141;
			long long expected__      = 133378408428237LL;

			std::clock_t start__      = std::clock();
			long long received__      = FindingKids().getSum(n, q, A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int n                     = ;
			int q                     = ;
			int A                     = ;
			int B                     = ;
			int C                     = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = FindingKids().getSum(n, q, A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int n                     = ;
			int q                     = ;
			int A                     = ;
			int B                     = ;
			int C                     = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = FindingKids().getSum(n, q, A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			int q                     = ;
			int A                     = ;
			int B                     = ;
			int C                     = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = FindingKids().getSum(n, q, A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
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
