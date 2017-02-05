#include <bits/stdc++.h>
using namespace std;
typedef long long int64;typedef int int32;
typedef int int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) (v).begin(),(v).end()

class TheShuttles {
public:
   int getLeastCost( vector <int> cnt, int baseCost, int seatCost ) {
     int max_n=-1;
     max_n=*max_element(all(cnt));

     int min_c=1<<30;
     double EPS=0.0001;
     repeat(k,1,max_n+1){
       int X=ceil((double)max_n/k);

       int newc_uni=baseCost + X*seatCost;
       int newc=0;
       rep(i,cnt.size())newc+=ceil(cnt[i]/(double)X)*newc_uni;

       min_c=min(min_c,newc);
     }
     return min_c;
   }
};

// BEGIN CUT HERE
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
			int cnt[]                 = {9};
			int baseCost              = 30;
			int seatCost              = 5;
			int expected__            = 75;

			std::clock_t start__      = std::clock();
			int received__            = TheShuttles().getLeastCost(vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])), baseCost, seatCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int cnt[]                 = {9, 4};
			int baseCost              = 30;
			int seatCost              = 5;
			int expected__            = 150;

			std::clock_t start__      = std::clock();
			int received__            = TheShuttles().getLeastCost(vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])), baseCost, seatCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int cnt[]                 = {9, 4};
			int baseCost              = 10;
			int seatCost              = 5;
			int expected__            = 105;

			std::clock_t start__      = std::clock();
			int received__            = TheShuttles().getLeastCost(vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])), baseCost, seatCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int cnt[]                 = {51, 1, 77, 14, 17, 10, 80};
			int baseCost              = 32;
			int seatCost              = 40;
			int expected__            = 12096;

			std::clock_t start__      = std::clock();
			int received__            = TheShuttles().getLeastCost(vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])), baseCost, seatCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int cnt[]                 = ;
			int baseCost              = ;
			int seatCost              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TheShuttles().getLeastCost(vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])), baseCost, seatCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int cnt[]                 = ;
			int baseCost              = ;
			int seatCost              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TheShuttles().getLeastCost(vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])), baseCost, seatCost);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int cnt[]                 = ;
			int baseCost              = ;
			int seatCost              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TheShuttles().getLeastCost(vector <int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])), baseCost, seatCost);
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
