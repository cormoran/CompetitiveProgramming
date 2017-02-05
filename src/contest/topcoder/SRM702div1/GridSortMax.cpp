#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pll;
#define rep(i,j) for(int i=0;i<j;i++)
#define repeat(i,j,k) for(int i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()

class GridSortMax {
public:
    string findMax( int n, int m, vector <int> grid ) {
       vector<int> ok_y(n, true), ok_x(m, true);
       repeat(i, 1, n * m + 1) {
           int ay = (i - 1) / m, ax = (i - 1) % m;
           int ty = -1, tx = -1;
           rep(y, n) rep(x, m) if(grid[y * m + x] == i) {
               ty = y;
               tx = x;
               break;               
           }
           assert(ty >= 0 and tx >= 0);

           //cerr << "flg" << endl;
           //rep(j, n) //cerr << ok_y[j] << " "; //cerr << endl;
           // rep(j, m) //cerr << ok_x[j] << " "; //cerr << endl;
           
           //cerr << i << endl;
           //cerr << "ax, ay = " << ax << " " << ay << endl;
           //cerr << "tx, ty = " << tx << " " << ty << endl;
           if(ty != ay and (!ok_y[ty] or !ok_y[ay])) continue;
           if(tx != ax and (!ok_x[tx] or !ok_x[ax])) continue;
           //cerr << "movable" << endl;
           ok_y[ay] = false;
           ok_x[ax] = false;
           
           if(tx != ax) rep(j, n) swap(grid[j * m + tx], grid[j * m + ax]);
           if(ty != ay) rep(j, m) swap(grid[ty * m + j], grid[ay * m + j]);
           
           // rep(j, n * m) //cerr << grid[j] << " "; //cerr <<endl;
        }
       string ans = "";
       rep(i, n * m) {
           ans += grid[i] == (i + 1) ? "1" : "0";
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
			int n                     = 2;
			int m                     = 2;
			int grid[]                = { 1,2, 3,4 };
			string expected__         = "1111";

			std::clock_t start__      = std::clock();
			string received__         = GridSortMax().findMax(n, m, vector <int>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 2;
			int m                     = 2;
			int grid[]                = { 2,1, 3,4 };
			string expected__         = "1100";

			std::clock_t start__      = std::clock();
			string received__         = GridSortMax().findMax(n, m, vector <int>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 2;
			int m                     = 2;
			int grid[]                = { 4,2, 3,1 };
			string expected__         = "1001";

			std::clock_t start__      = std::clock();
			string received__         = GridSortMax().findMax(n, m, vector <int>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 1;
			int m                     = 10;
			int grid[]                = {10,6,2,3,5,7,1,9,4,8};
			string expected__         = "1111111111";

			std::clock_t start__      = std::clock();
			string received__         = GridSortMax().findMax(n, m, vector <int>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 3;
			int m                     = 5;
			int grid[]                = { 5,2,10,7,9, 3,4,14,11,1, 15,12,6,8,13 };
			string expected__         = "101100100100000";

			std::clock_t start__      = std::clock();
			string received__         = GridSortMax().findMax(n, m, vector <int>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int n                     = 6;
			int m                     = 2;
			int grid[]                = { 3,9, 5,1, 10,6, 2,7, 8,11, 12,4 };
			string expected__         = "100000101010";

			std::clock_t start__      = std::clock();
			string received__         = GridSortMax().findMax(n, m, vector <int>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int n                     = ;
			int m                     = ;
			int grid[]                = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = GridSortMax().findMax(n, m, vector <int>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int m                     = ;
			int grid[]                = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = GridSortMax().findMax(n, m, vector <int>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int n                     = ;
			int m                     = ;
			int grid[]                = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = GridSortMax().findMax(n, m, vector <int>(grid, grid + (sizeof grid / sizeof grid[0])));
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
