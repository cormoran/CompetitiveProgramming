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

class ThePermutationGameDiv2 {
public:
   long long findMin( int N ) {
     int primes[] = {2,3,5,7,11,13,17,19,23,29,31};
     int pnum[11]={};
     rep(i,11){
       int64 k=primes[i];
       int cnt=1;
       while(k<=N){
	 cnt++;k*=primes[i];
       }
       pnum[i]=cnt-1;
     }
     int64 ans=1;
     rep(i,11){
       while(pnum[i]-->0){
	 ans*=primes[i];
       }
     }
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
			int N                     = 2;
			long long expected__      = 2;

			std::clock_t start__      = std::clock();
			long long received__      = ThePermutationGameDiv2().findMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 3;
			long long expected__      = 6;

			std::clock_t start__      = std::clock();
			long long received__      = ThePermutationGameDiv2().findMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 6;
			long long expected__      = 60;

			std::clock_t start__      = std::clock();
			long long received__      = ThePermutationGameDiv2().findMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 11;
			long long expected__      = 27720;

			std::clock_t start__      = std::clock();
			long long received__      = ThePermutationGameDiv2().findMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 25;
			long long expected__      = 26771144400LL;

			std::clock_t start__      = std::clock();
			long long received__      = ThePermutationGameDiv2().findMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int N                     =35 ;
			long long expected__      =0 ;

			std::clock_t start__      = std::clock();
			long long received__      = ThePermutationGameDiv2().findMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int N                     = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = ThePermutationGameDiv2().findMin(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = ThePermutationGameDiv2().findMin(N);
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
