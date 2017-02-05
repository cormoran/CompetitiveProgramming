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

using namespace std;

typedef long long int64;
typedef int int32;
typedef int32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) (v).begin(),(v).end()

class FoxConnection4 {
public:
   int howManyWays( vector <string> board, int k ) {

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
			string board[]            = {"....."}
;
			int k                     = 3;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = FoxConnection4().howManyWays(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {".#.#",
 "#.#.",
 ".#.#",
 "#.#."}
;
			int k                     = 2;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = FoxConnection4().howManyWays(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"##.",
 "...",
 ".##"}
;
			int k                     = 3;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = FoxConnection4().howManyWays(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"....",
 "....",
 "....",
 "...."};
			int k                     = 4;
			int expected__            = 113;

			std::clock_t start__      = std::clock();
			int received__            = FoxConnection4().howManyWays(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {".....#....",
 ".#........",
 "....#.##..",
 "#......#..",
 "....#.....",
 "..........",
 ".##....#..",
 "..##......",
 "........##",
 "......#.#."}
;
			int k                     = 8;
			int expected__            = 22369;

			std::clock_t start__      = std::clock();
			int received__            = FoxConnection4().howManyWays(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int k                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FoxConnection4().howManyWays(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int k                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FoxConnection4().howManyWays(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int k                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FoxConnection4().howManyWays(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
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
