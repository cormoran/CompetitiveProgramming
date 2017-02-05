#include<vector>
#include<iostream>
#include<cassert>
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pll;
#define rep(i,j) for(ll i=0;i<j;i++)
#define repeat(i,j,k) for(ll i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()

class BearCries {
public:
    bool check_col(string &m){
        int sum =0;
        if(m[0]!=';' or m.back()!=';')return false;
        rep(i,(int)m.size()){
            if(m[i]==';')sum++;
        }
        return sum%2 == 0 ;
    }
    
   int count( string message ) {
       if(!check_col(message))return 0;

       
       
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
			string message            = ";_;;_____;";
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = BearCries().count(message);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string message            = ";;;___;;;";
			int expected__            = 36;

			std::clock_t start__      = std::clock();
			int received__            = BearCries().count(message);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string message            = "_;__;";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = BearCries().count(message);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string message            = ";_____________________________________;";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = BearCries().count(message);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string message            = ";__;____;";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = BearCries().count(message);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string message            = ";_;;__;_;;";
			int expected__            = 52;

			std::clock_t start__      = std::clock();
			int received__            = BearCries().count(message);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string message            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearCries().count(message);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string message            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearCries().count(message);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string message            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearCries().count(message);
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
