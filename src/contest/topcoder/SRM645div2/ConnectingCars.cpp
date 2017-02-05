// Paste me into the FileEdit configuration dialog

#include<algorithm>
#include<vector>
#include<cmath>
//#include<>
using namespace std;

typedef long long int64;
typedef int int32;
typedef char int8;
typedef int32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) (v).begin(),(v).end()

const int64 INF=1L<<60;//=10E10

class ConnectingCars {
public:
   long long minimizeCost( vector <int> positions, vector <int> lengths ) {
     int64 ans=INF;
     vector<pair<int64,int64> > pl(positions.size());
     rep(i,positions.size()){
       pl[i].first=positions[i];
       pl[i].second=lengths[i];
     }
     sort(all(pl));
     
     rep(i,positions.size()){
       //i番目動かさない
       int64 prev=0,t_ans=0;;
       for(int64 j=i-1;j>=0;j--){
	 prev+=pl[j+1].first-(pl[j].first+pl[j].second);
	 t_ans+=prev;
       }
       prev=0;
       for(int64 j=i+1;j<positions.size();j++){
	 prev+=pl[j].first-(pl[j-1].first+pl[j-1].second);
	 t_ans+=prev;
       }
       ans=min(ans,t_ans);
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
			int positions[]           = {1, 3, 10, 20};
			int lengths[]             = {2, 2, 5, 3};
			long long expected__      = 15;

			std::clock_t start__      = std::clock();
			long long received__      = ConnectingCars().minimizeCost(vector <int>(positions, positions + (sizeof positions / sizeof positions[0])), vector <int>(lengths, lengths + (sizeof lengths / sizeof lengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int positions[]           = {100, 50, 1} ;
			int lengths[]             = {10, 2, 1};
			long long expected__      = 96;

			std::clock_t start__      = std::clock();
			long long received__      = ConnectingCars().minimizeCost(vector <int>(positions, positions + (sizeof positions / sizeof positions[0])), vector <int>(lengths, lengths + (sizeof lengths / sizeof lengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int positions[]           = {4, 10, 100, 13, 80};
			int lengths[]             = {5, 3, 42, 40, 9};
			long long expected__      = 66;

			std::clock_t start__      = std::clock();
			long long received__      = ConnectingCars().minimizeCost(vector <int>(positions, positions + (sizeof positions / sizeof positions[0])), vector <int>(lengths, lengths + (sizeof lengths / sizeof lengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int positions[]           = {5606451, 63581020, 81615191, 190991272, 352848147, 413795385, 468408016, 615921162, 760622952, 791438427};
			int lengths[]             = {42643329, 9909484, 58137134, 99547272, 39849232, 15146704, 144630245, 604149, 15591965, 107856540};
			long long expected__      = 1009957100;

			std::clock_t start__      = std::clock();
			long long received__      = ConnectingCars().minimizeCost(vector <int>(positions, positions + (sizeof positions / sizeof positions[0])), vector <int>(lengths, lengths + (sizeof lengths / sizeof lengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int positions[]           = ;
			int lengths[]             = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = ConnectingCars().minimizeCost(vector <int>(positions, positions + (sizeof positions / sizeof positions[0])), vector <int>(lengths, lengths + (sizeof lengths / sizeof lengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int positions[]           = ;
			int lengths[]             = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = ConnectingCars().minimizeCost(vector <int>(positions, positions + (sizeof positions / sizeof positions[0])), vector <int>(lengths, lengths + (sizeof lengths / sizeof lengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int positions[]           = ;
			int lengths[]             = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = ConnectingCars().minimizeCost(vector <int>(positions, positions + (sizeof positions / sizeof positions[0])), vector <int>(lengths, lengths + (sizeof lengths / sizeof lengths[0])));
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
