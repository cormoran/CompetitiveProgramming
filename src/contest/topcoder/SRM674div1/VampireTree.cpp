#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include<algorithm>
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pll;
#define rep(i,j) for(ll i=0;i<(ll)j;i++)
#define repeat(i,j,k) for(ll i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()

class VampireTree {
public:
   int maxDistance( vector <int> num ) {
       int n = num.size();
       rep(i,num.size())num[i]--;
       sort(all(num),greater<int>());
       int sum = accumulate(all(num),0);
       if(sum + 1 != n - 1) return -1;
       if(n == 2)return 1;
       int none_zeros = 0;
       rep(i,n)if(num[i]>0)none_zeros++;
       return none_zeros +1;
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
			int num[]                 = {1, 2, 1};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = VampireTree().maxDistance(vector <int>(num, num + (sizeof num / sizeof num[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int num[]                 = {2, 2, 2};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = VampireTree().maxDistance(vector <int>(num, num + (sizeof num / sizeof num[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int num[]                 = {1, 1, 1, 1, 4};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = VampireTree().maxDistance(vector <int>(num, num + (sizeof num / sizeof num[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int num[]                 = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = VampireTree().maxDistance(vector <int>(num, num + (sizeof num / sizeof num[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int num[]                 = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = VampireTree().maxDistance(vector <int>(num, num + (sizeof num / sizeof num[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int num[]                 = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = VampireTree().maxDistance(vector <int>(num, num + (sizeof num / sizeof num[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int num[]                 = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = VampireTree().maxDistance(vector <int>(num, num + (sizeof num / sizeof num[0])));
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
