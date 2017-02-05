#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include<algorithm>
#include<cassert>

typedef long long  int64;
typedef long long  ll;
typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()

using namespace std;

class ABBA {
public:
   string canObtain( string initial, string target ) {
     while(target.length()>initial.size()){
       if(target[target.size()-1]=='A'){
         target.erase(target.size()-1);
       }
       else if(target[target.size()-1]=='B'){
         target.erase(target.size()-1);
         reverse(all(target));
       }
       else assert(0);
     }
     if(target==initial)return "Possible";
     else return "Impossible";
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
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string initial            = "B";
			string target             = "ABBA";
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = ABBA().canObtain(initial, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string initial            = "AB";
			string target             = "ABB";
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = ABBA().canObtain(initial, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string initial            = "BBAB";
			string target             = "ABABABABB";
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = ABBA().canObtain(initial, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string initial            = "BBBBABABBBBBBA";
			string target             = "BBBBABABBABBBBBBABABBBBBBBBABAABBBAA";
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = ABBA().canObtain(initial, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string initial            = "A";
			string target             = "BB";
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = ABBA().canObtain(initial, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string initial            = ;
			string target             = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ABBA().canObtain(initial, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string initial            = ;
			string target             = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ABBA().canObtain(initial, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string initial            = ;
			string target             = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ABBA().canObtain(initial, target);
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
