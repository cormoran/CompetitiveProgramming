#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include<algorithm>
typedef long long  int64;
typedef long long  ll;
typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()

using namespace std;

class ChessFloor {
public:
   int minimumChanges( vector <string> floor ) {
     vector< pair<char,int> > alpha[2];
     rep(i,2)alpha[i].resize(27);
     rep(i,27){
       rep(j,2){
         alpha[j][i].second='a'+i;
         alpha[j][i].first=0;
       }
     }
     int N=floor.size();
     rep(i,N){
       rep(j,N){
         alpha[(i+j)%2][floor[i][j]-'a'].first++;
       }
     }
     rep(i,2){
       sort(all(alpha[i]));
       reverse(all(alpha[i]));
     }
     
     if(alpha[0][0].second==alpha[1][0].second){
       if(alpha[0][1].first<=alpha[1][1].first){
         alpha[0][0]=alpha[0][1];
       }
       else{
         alpha[1][0]=alpha[1][1];
       }
     }
     int ans=0;
     rep(i,N){
       rep(j,N){
         if(floor[i][j]!=alpha[(i+j)%2][0].second)ans++;
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
			string floor[]            = {"aba",
 "bbb",
 "aba"}
;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = ChessFloor().minimumChanges(vector <string>(floor, floor + (sizeof floor / sizeof floor[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string floor[]            = {"wbwbwbwb",
 "bwbwbwbw",
 "wbwbwbwb",
 "bwbwbwbw",
 "wbwbwbwb",
 "bwbwbwbw",
 "wbwbwbwb",
 "bwbwbwbw"}
 ;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = ChessFloor().minimumChanges(vector <string>(floor, floor + (sizeof floor / sizeof floor[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string floor[]            = {"zz",
 "zz"};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = ChessFloor().minimumChanges(vector <string>(floor, floor + (sizeof floor / sizeof floor[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string floor[]            = {"helloand",
 "welcomet",
 "osingler",
 "oundmatc",
 "hsixhund",
 "redandsi",
 "xtythree",
 "goodluck"};
			int expected__            = 56;

			std::clock_t start__      = std::clock();
			int received__            = ChessFloor().minimumChanges(vector <string>(floor, floor + (sizeof floor / sizeof floor[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string floor[]            = {"jecjxsengslsmeijrmcx",
 "tcfyhumjcvgkafhhffed",
 "icmgxrlalmhnwwdhqerc",
 "xzrhzbgjgabanfxgabed",
 "fpcooilmwqixfagfojjq",
 "xzrzztidmchxrvrsszii",
 "swnwnrchxujxsknuqdkg",
 "rnvzvcxrukeidojlakcy",
 "kbagitjdrxawtnykrivw",
 "towgkjctgelhpomvywyb",
 "ucgqrhqntqvncargnhhv",
 "mhvwsgvfqgfxktzobetn",
 "fabxcmzbbyblxxmjcaib",
 "wpiwnrdqdixharhjeqwt",
 "xfgulejzvfgvkkuyngdn",
 "kedsalkounuaudmyqggb",
 "gvleogefcsxfkyiraabn",
 "tssjsmhzozbcsqqbebqw",
 "ksbfjoirwlmnoyyqpbvm",
 "phzsdodppzfjjmzocnge"};
			int expected__            = 376;

			std::clock_t start__      = std::clock();
			int received__            = ChessFloor().minimumChanges(vector <string>(floor, floor + (sizeof floor / sizeof floor[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string floor[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChessFloor().minimumChanges(vector <string>(floor, floor + (sizeof floor / sizeof floor[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string floor[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChessFloor().minimumChanges(vector <string>(floor, floor + (sizeof floor / sizeof floor[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string floor[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChessFloor().minimumChanges(vector <string>(floor, floor + (sizeof floor / sizeof floor[0])));
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
