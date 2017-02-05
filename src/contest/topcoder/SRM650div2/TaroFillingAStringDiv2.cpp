// Paste me into the FileEdit configuration dialog

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
//#include<>
using namespace std;


#define rep(i,j) for(int i=0;i<j;i++)

class TaroFillingAStringDiv2 {
public:
  int mn=INT_MAX;
  
   int getNumber( string S ) {
     solve(s,0);return mn;
     /*
     rep(i,S.size()){
       if(i>0 && S[i-1]!='?' && S[i]=='?'){
	 S[i]= S[i-1]=='A' ? 'B' :'A';
       }
     }
     for(int i=S.size()-2;i>=0;i--){
       if(S[i+1]!='?' && S[i]=='?'){
	 S[i]= S[i+1]=='A' ? 'B' :'A';
       }
     }
     int ans=0;
     if(S[0]=='?')ans=0;
     else{
       rep(i,S.size()){
	 if(i>0 && S[i-1]==S[i])ans++;
       }
     }
     return ans;
     */
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
			string S                  = "ABAA";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv2().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "??";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv2().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "A?A";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv2().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "A??B???AAB?A???A";
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv2().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "?BB?BAAB???BAB?B?AAAA?ABBA????A?AAB?BBA?A?";
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv2().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string S                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv2().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string S                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv2().getNumber(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string S                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv2().getNumber(S);
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
