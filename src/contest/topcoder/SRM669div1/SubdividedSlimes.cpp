#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#include<queue>
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pll;
#define rep(i,j) for(ll i=0;i<j;i++)
#define repeat(i,j,k) for(ll i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()

class SubdividedSlimes {
public:
   int needCut( int S, int M ) {
       priority_queue<int> que;
       que.push(S);
       ll sum =0;
       ll num =0;
       while(!que.empty()){
           int N = que.top();que.pop();
           int l = N/2;
           int r = N - l;
           sum += l*r;
           if(l>1)que.push(l);
           if(r>1)que.push(r);
           ++num;
           if(sum>=M)return num;
       }

       return -1;
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
			int S                     = 3;
			int M                     = 2;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = SubdividedSlimes().needCut(S, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int S                     = 3;
			int M                     = 3;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = SubdividedSlimes().needCut(S, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int S                     = 3;
			int M                     = 4;
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = SubdividedSlimes().needCut(S, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int S                     = 765;
			int M                     = 271828;
			int expected__            = 14;

			std::clock_t start__      = std::clock();
			int received__            = SubdividedSlimes().needCut(S, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int S                     = 1000;
			int M                     = 1000000000;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = SubdividedSlimes().needCut(S, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int S                     = ;
			int M                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SubdividedSlimes().needCut(S, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int S                     = ;
			int M                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SubdividedSlimes().needCut(S, M);
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
