#include<iostream>
#include<vector>
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pll;
#define rep(i,j) for(ll i=0;i<j;i++)
#define repeat(i,j,k) for(ll i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()

class MoveStones {
  public:
    long long get( vector <int> a, vector <int> b ) {
        int n = a.size();
        ll ans = 1LL << 60;
        rep(i,n){
            ll d = 0;
            ll cnt = 0;
            rep(j,n){
                int k = (i+j) % n;
                d += b[k] - a[k];
                cnt += abs(d);
            }
            if(d != 0) return -1;
            ans = min(cnt, ans);
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
			int a[]                   = {12};
			int b[]                   = {12};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = MoveStones().get(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a[]                   = {10};
			int b[]                   = {9};
			long long expected__      = -1;

			std::clock_t start__      = std::clock();
			long long received__      = MoveStones().get(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a[]                   = {0, 5};
			int b[]                   = {5, 0};
			long long expected__      = 5;

			std::clock_t start__      = std::clock();
			long long received__      = MoveStones().get(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a[]                   = {1, 2, 3};
			int b[]                   = {3, 1, 2};
			long long expected__      = 2;

			std::clock_t start__      = std::clock();
			long long received__      = MoveStones().get(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a[]                   = {1, 0, 1, 1, 0} ;
			int b[]                   = {0, 3, 0, 0, 0};
			long long expected__      = 4;

			std::clock_t start__      = std::clock();
			long long received__      = MoveStones().get(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int a[]                   = {1000000000, 0, 0, 0, 0, 0};
			int b[]                   = {0, 0, 0, 1000000000, 0, 0};
			long long expected__      = 3000000000LL;

			std::clock_t start__      = std::clock();
			long long received__      = MoveStones().get(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int a[]                   = ;
			int b[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = MoveStones().get(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a[]                   = ;
			int b[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = MoveStones().get(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int a[]                   = ;
			int b[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = MoveStones().get(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
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
