#include <bits/stdc++.h>
using namespace std;
typedef long long int64;typedef int int32;
typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) (v).begin(),(v).end()

class BichromePainting {
public:

  bool check1( vector <string> &board, int k ) {
    rep(i,board.size()){
      int sx=0,sy=0;
      char prex=0,prey=0;
      bool flgx=false,flgy=false;
      rep(j,board.size()){
	//横
	if(prex!=board[i][j]){sx=0;prex=board[i][j];}
	sx++;
	if(sx>=k)flgx=true;
	//縦
	if(prey!=board[j][i]){sy=0;prey=board[j][i];}
	sy++;
	if(sy>=k)flgy=true;
      }
      if(!flgx or !flgy)return false;
    }
    return true;
  }

  bool check2( vector <string> &board, int k ) {
    char c;
    rep(y,board.size()-k+1){
      rep(x,board.size()-k+1){
	bool flg=true;
	c=board[y][x];
	rep(yy,k){
	  rep(xx,k){
	    if(c!=board[y+yy][x+xx]){
	      flg=false;
	    }
	  }
	}

	if(flg==true){
	  return true;
	}
	
      }
    }
    return false;
  }
   string isThatPossible( vector <string> board, int k ) {
     int n=board[0].size();
     bool one=check1(board,k);
     bool two=check2(board,k);
     cout<<one<<" "<<two<<endl;
     if(one and two)return "Possible";
     else return "Impossible";
     
     
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
			string board[]            = {"BBBW",
 "BWWW",
 "BWWW",
 "WWWW"};
			int k                     = 3;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = BichromePainting().isThatPossible(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"BW",
 "WB"}
;
			int k                     = 2;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = BichromePainting().isThatPossible(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"BWBWBB",
 "WBWBBB",
 "BWBWBB",
 "WBWBBB",
 "BBBBBB",
 "BBBBBB"}
;
			int k                     = 2;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = BichromePainting().isThatPossible(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "BBBBBB"}
;
			int k                     = 2;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = BichromePainting().isThatPossible(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "BBBBBB"}
;
			int k                     = 1;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = BichromePainting().isThatPossible(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string board[]            = {"BB",
 "BB"};
			int k                     = 2;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = BichromePainting().isThatPossible(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string board[]            = ;
			int k                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = BichromePainting().isThatPossible(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int k                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = BichromePainting().isThatPossible(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string board[]            = ;
			int k                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = BichromePainting().isThatPossible(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
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
