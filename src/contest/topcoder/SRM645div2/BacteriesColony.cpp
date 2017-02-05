// Paste me into the FileEdit configuration dialog

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
//#include<>
using namespace std;

typedef int int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) (v).begin(),(v).end()


class BacteriesColony {
public:
   vector <int> performTheExperiment( vector <int> colonies ) {
     bool update=false;
     while(true){
       vector<int> col(colonies.size(),0);
       update=false;
       repeat(i,1,colonies.size()-1){
	 if(colonies[i-1]>colonies[i] && colonies[i]<colonies[i+1]){
	   col[i]++;
	   update=true;
	 }
	 else if(colonies[i-1]<colonies[i] && colonies[i]>colonies[i+1]){
	   col[i]--;
	   update=true;
	 }
       }

       if(update){
	 rep(i,colonies.size())colonies[i]+=col[i];
       }
       else break;
       
     }
     return colonies;
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
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
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
			int colonies[]            = {5, 3, 4, 6, 1 };
			int expected__[]          = {5, 4, 4, 4, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = BacteriesColony().performTheExperiment(vector <int>(colonies, colonies + (sizeof colonies / sizeof colonies[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int colonies[]            = {1, 5, 4, 9 };
			int expected__[]          = {1, 4, 5, 9 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = BacteriesColony().performTheExperiment(vector <int>(colonies, colonies + (sizeof colonies / sizeof colonies[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int colonies[]            = {78, 34, 3, 54, 44, 99 };
			int expected__[]          = {78, 34, 34, 49, 49, 99 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = BacteriesColony().performTheExperiment(vector <int>(colonies, colonies + (sizeof colonies / sizeof colonies[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int colonies[]            = {32, 68, 50, 89, 34, 56, 47, 30, 82, 7, 21, 16, 82, 24, 91 };
			int expected__[]          = {32, 59, 59, 59, 47, 47, 47, 47, 47, 18, 18, 19, 53, 53, 91 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = BacteriesColony().performTheExperiment(vector <int>(colonies, colonies + (sizeof colonies / sizeof colonies[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int colonies[]            = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = BacteriesColony().performTheExperiment(vector <int>(colonies, colonies + (sizeof colonies / sizeof colonies[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int colonies[]            = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = BacteriesColony().performTheExperiment(vector <int>(colonies, colonies + (sizeof colonies / sizeof colonies[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int colonies[]            = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = BacteriesColony().performTheExperiment(vector <int>(colonies, colonies + (sizeof colonies / sizeof colonies[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
