// Paste me into the FileEdit configuration dialog

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

typedef long long int64;
typedef int int32;
typedef int32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define all(v) (v).begin(),(v).end()
class FoxAndSouvenirTheNext {
public:
   string ableToSplit( vector <int> value ) {
     if(value.size()%2!=0)return "Impossible";
     int hsum=0;
     rep(i,value.size())hsum+=value[i];
     if(hsum%2!=0)return "Impossible";
     hsum/=2;
     vector<int> fs(value.size()/2+1);
     int tsum=0;
     rep(i,fs.size()){fs[i]=i;tsum+=value[i];}
     tsum-=value[fs.size()-1];
     fs[fs.size()-1]=value.size();
     
     int i=fs.size()-2;
     while(true){
       if(fs[i]+1==fs[i+1])i--;
       if(i>=0)fs[i]++;
       else return "Impossible";
       
       tsum+=value[fs[i]]-value[fs[i]-1];
       if(tsum==hsum)return "Possible";
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
			int value[]               = {1,2,3,4};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = FoxAndSouvenirTheNext().ableToSplit(vector <int>(value, value + (sizeof value / sizeof value[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int value[]               = {1,1,1,3};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = FoxAndSouvenirTheNext().ableToSplit(vector <int>(value, value + (sizeof value / sizeof value[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int value[]               = {1,1,2,3,5,8};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = FoxAndSouvenirTheNext().ableToSplit(vector <int>(value, value + (sizeof value / sizeof value[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int value[]               = {2,3,5,7,11,13};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = FoxAndSouvenirTheNext().ableToSplit(vector <int>(value, value + (sizeof value / sizeof value[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int value[]               = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = FoxAndSouvenirTheNext().ableToSplit(vector <int>(value, value + (sizeof value / sizeof value[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int value[]               = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = FoxAndSouvenirTheNext().ableToSplit(vector <int>(value, value + (sizeof value / sizeof value[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int value[]               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = FoxAndSouvenirTheNext().ableToSplit(vector <int>(value, value + (sizeof value / sizeof value[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int value[]               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = FoxAndSouvenirTheNext().ableToSplit(vector <int>(value, value + (sizeof value / sizeof value[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int value[]               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = FoxAndSouvenirTheNext().ableToSplit(vector <int>(value, value + (sizeof value / sizeof value[0])));
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
