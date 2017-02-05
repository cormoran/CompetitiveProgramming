#include <bits/stdc++.h>
using namespace std;
typedef long long int64;typedef int int32;
typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) (v).begin(),(v).end()

class Nine {
public:
   int count( int N, vector <int> d ) {

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
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
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
			int N                     = 2;
			int d[]                   = {1,2};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = Nine().count(N, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 2;
			int d[]                   = {1,2,3};
			int expected__            = 16;

			std::clock_t start__      = std::clock();
			int received__            = Nine().count(N, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 1;
			int d[]                   = {0,0,1};
			int expected__            = 200;

			std::clock_t start__      = std::clock();
			int received__            = Nine().count(N, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 5;
			int d[]                   = {1,3,5,8,24,22,25,21,30,2,4,0,6,7,9,11,14,13,12,15,18,17,16,19,26,29,31,28,27,10,20,23};
			int expected__            = 450877328;

			std::clock_t start__      = std::clock();
			int received__            = Nine().count(N, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 5;
			int d[]                   = {31,31,31,31,31};
			int expected__            = 11112;

			std::clock_t start__      = std::clock();
			int received__            = Nine().count(N, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int d[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Nine().count(N, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int d[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Nine().count(N, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int d[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Nine().count(N, vector <int>(d, d + (sizeof d / sizeof d[0])));
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
