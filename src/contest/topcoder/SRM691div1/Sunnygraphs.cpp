#include<vector>
#include<iostream>
#include<set>
#include<cmath>
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pll;
#define rep(i,j) for(ll i=0;i<j;i++)
#define repeat(i,j,k) for(ll i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()

class Sunnygraphs {
public:
    vector<int> E;
    set<int> visitable(int now) {
        set<int> ret;
        while(ret.count(now) == 0) {
            ret.insert(now);
            now = E[now];
        }
        return ret;
    }
    long long count( vector <int> a ) {
        E = a;
        int N = a.size();
        set<int> from_zero = visitable(0);
        set<int> from_one = visitable(1);
        from_zero.erase(0);
        from_one.erase(1);
        set<int> common;
        for(int v : from_zero) if(from_one.count(v)) common.insert(v);
        cerr << from_zero.size() << endl;
        cerr << from_one.size() << endl;
        cerr << common.size() << endl;
        ll ans = 0;
        ll gomi = N - from_zero.size() - from_one.size() + common.size();
        cerr << "gomi" << gomi << endl;
        if(from_zero.count(1) == 0 and from_one.count(0) == 0) {
            // {0, 1}
            ans += pow<ll>(2, N - 2);
            // {!0, !1}
            ans += pow<ll>(2, common.size());
            ll zero = from_zero.size() - common.size();
            ll one = from_one.size() - common.size();
            ans += (pow<ll>(2, zero) - 1) * (pow<ll>(2, one) - 1) * pow<ll>(2, common.size());
            // {1, !0}
            ans += pow<ll>(2, from_zero.size()) - 1;
            ans += pow<ll>(2, from_one.size()) - 1;            
        }
        cerr << ans << endl;
        cerr <<pow<ll>(2, gomi) << endl;
        
        return ans * pow<ll>(2, gomi);
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
			int a[]                   = {1,0};
			long long expected__      = 4;

			std::clock_t start__      = std::clock();
			long long received__      = Sunnygraphs().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a[]                   = {2,2,0};
			long long expected__      = 7;

			std::clock_t start__      = std::clock();
			long long received__      = Sunnygraphs().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a[]                   = {2,3,0,1};
			long long expected__      = 9;

			std::clock_t start__      = std::clock();
			long long received__      = Sunnygraphs().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a[]                   = {2,2,3,4,3};
			long long expected__      = 30;

			std::clock_t start__      = std::clock();
			long long received__      = Sunnygraphs().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a[]                   = {18,18,20,28,7,27,8,13,40,3,7,21,30,17,13,34,29,16,15,11,0,9,39,36,38,23,24,8,4,9,29,22,35,5,13,23,3,27,34,23,8};
			long long expected__      = 2198754820096LL;

			std::clock_t start__      = std::clock();
			long long received__      = Sunnygraphs().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int a[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = Sunnygraphs().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int a[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = Sunnygraphs().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = Sunnygraphs().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
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
