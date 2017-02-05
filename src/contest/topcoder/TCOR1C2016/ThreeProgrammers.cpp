#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pll;
#define rep(i,j) for(ll i=0;i<j;i++)
#define repeat(i,j,k) for(ll i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()

class ThreeProgrammers {
public:
   string validCodeHistory( string code ) {
       int N = code.size();
       int A = 0; rep(i, code.size()) A += code[i] == 'A';
       int B = 0; rep(i, code.size()) B += code[i] == 'B';
       int C = 0; rep(i, code.size()) C += code[i] == 'C';
       
       if(ceil(N / 3.0) < C or ceil(N / 2.0) < B) return "impossible";
       
       {           
           vector<char> ans(code.size(), 'A');
           int CC = C;
           for(int i = 0; i < N and CC > 0; i+= 3) {
               ans[i] = 'C';
               CC--;
           }
           if(CC != 0) goto TWO;
           int pre = -2;
           int BB = B;
           for(int i = 0; i < N and BB > 0; i++) {
               if(ans[i] == 'A' and i > pre + 1) {
                   BB--;
                   ans[i] = 'B';
                   pre = i;
               }
           }
           if(BB != 0) goto TWO;
           string ret;
           rep(i, ans.size()) ret.push_back(ans[i]);
           return ret;
       }
 TWO:
       {           
           vector<char> ans(code.size(), 'A');
           int CC = C;
           for(int i = 1; i < N and CC > 0; i+= 3) {
               ans[i] = 'C';
               CC--;
           }
           if(CC != 0) return "impossible";
           int pre = -2;
           int BB = B;
           for(int i = 0; i < N and BB > 0; i++) {
               if(ans[i] == 'A' and i > pre + 1) {
                   BB--;
                   ans[i] = 'B';
                   pre = i;
               }
           }
           if(BB != 0) return "impossible";
           string ret;
           rep(i, ans.size()) ret.push_back(ans[i]);
           return ret;
       }
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
			string code               = "CAB";
			string expected__         = "BCA";

			std::clock_t start__      = std::clock();
			string received__         = ThreeProgrammers().validCodeHistory(code);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string code               = "CBB";
			string expected__         = "BCB";

			std::clock_t start__      = std::clock();
			string received__         = ThreeProgrammers().validCodeHistory(code);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string code               = "BB";
			string expected__         = "impossible";

			std::clock_t start__      = std::clock();
			string received__         = ThreeProgrammers().validCodeHistory(code);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string code               = "BBA";
			string expected__         = "BAB";

			std::clock_t start__      = std::clock();
			string received__         = ThreeProgrammers().validCodeHistory(code);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string code               = "CAC";
			string expected__         = "impossible";

			std::clock_t start__      = std::clock();
			string received__         = ThreeProgrammers().validCodeHistory(code);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string code               = "ACAC";
			string expected__         = "CAAC";

			std::clock_t start__      = std::clock();
			string received__         = ThreeProgrammers().validCodeHistory(code);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string code               = "ACABC";
			string expected__         = "ACABC";

			std::clock_t start__      = std::clock();
			string received__         = ThreeProgrammers().validCodeHistory(code);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			string code               = "BAABCABBCCACBAACABAABABBCCAACABCCAACCABCACACCBABAB";
			string expected__         = "BACBABCAACBACABCBACBACABCBACBACABCABCAACBACAACABCA";

			std::clock_t start__      = std::clock();
			string received__         = ThreeProgrammers().validCodeHistory(code);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			string code               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ThreeProgrammers().validCodeHistory(code);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string code               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ThreeProgrammers().validCodeHistory(code);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			string code               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ThreeProgrammers().validCodeHistory(code);
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
