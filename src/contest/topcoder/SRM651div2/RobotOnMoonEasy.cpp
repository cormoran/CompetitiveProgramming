// Paste me into the FileEdit configuration dialog

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
//#include<>
using namespace std;

typedef int int__;
#define rep(i,j) for(int__ i=0;i<j;i++)

class RobotOnMoonEasy {
public:
   string isSafeCommand( vector <string> board, string S ) {
     int x,y;
     rep(i,board.size())rep(j,board[i].size()){
       if(board[i][j]=='S'){
	 x=j;y=i;break;
       }
     }
     int dx[]={0,0,1,-1};
     int dy[]={-1,1,0,0};
     rep(i,S.size()){
       int dir=-1;
       int nx,ny;
       if(S[i]=='U')dir=0;
       else if(S[i]=='D')dir=1;
       else if(S[i]=='R')dir=2;
       else if(S[i]=='L')dir=3;

       
       nx=x+dx[dir];
       ny=y+dy[dir];
       if(0<=nx and nx<board[0].size() and 0<=ny and ny<board.size()){
	 if(board[ny][nx]!='#'){
	   x=nx;
	   y=ny;
	 }
       }
       else{
	 string ret ="Dead";
	 return ret;
       }
     }
     string ret ="Alive";
     return ret;
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
			string board[]            = {".....",
 ".###.",
 "..S#.",
 "...#."};
			string S                  = "URURURURUR";
			string expected__         = "Alive";

			std::clock_t start__      = std::clock();
			string received__         = RobotOnMoonEasy().isSafeCommand(vector <string>(board, board + (sizeof board / sizeof board[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {".....",
 ".###.",
 "..S..",
 "...#."};
			string S                  = "URURURURUR";
			string expected__         = "Dead";

			std::clock_t start__      = std::clock();
			string received__         = RobotOnMoonEasy().isSafeCommand(vector <string>(board, board + (sizeof board / sizeof board[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {".....",
 ".###.",
 "..S..",
 "...#."};
			string S                  = "URURU";
			string expected__         = "Alive";

			std::clock_t start__      = std::clock();
			string received__         = RobotOnMoonEasy().isSafeCommand(vector <string>(board, board + (sizeof board / sizeof board[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#####"};
			string S                  = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD";
			string expected__         = "Alive";

			std::clock_t start__      = std::clock();
			string received__         = RobotOnMoonEasy().isSafeCommand(vector <string>(board, board + (sizeof board / sizeof board[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#.###"};
			string S                  = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD";
			string expected__         = "Dead";

			std::clock_t start__      = std::clock();
			string received__         = RobotOnMoonEasy().isSafeCommand(vector <string>(board, board + (sizeof board / sizeof board[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string board[]            = {"S"};
			string S                  = "R";
			string expected__         = "Dead";

			std::clock_t start__      = std::clock();
			string received__         = RobotOnMoonEasy().isSafeCommand(vector <string>(board, board + (sizeof board / sizeof board[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string board[]            = ;
			string S                  = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = RobotOnMoonEasy().isSafeCommand(vector <string>(board, board + (sizeof board / sizeof board[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			string S                  = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = RobotOnMoonEasy().isSafeCommand(vector <string>(board, board + (sizeof board / sizeof board[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string board[]            = ;
			string S                  = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = RobotOnMoonEasy().isSafeCommand(vector <string>(board, board + (sizeof board / sizeof board[0])), S);
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
