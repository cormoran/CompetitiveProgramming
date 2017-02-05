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
class TheKingsRoadsDiv2 {
public:
  string getAnswer( int h, vector <int> a, vector <int> b ) {
    vector< vector<int> > G(a.size(),vector<int>(a.size(),0));
    bool mult=false;
    bool inc=false;
    rep(i,a.size()){
      if(a[i]==b[i] || G[a[i]-1][b[i]-1]>0){
	if(mult==true)inc=true;
	mult=true;
      }
      else{
	G[a[i]-1][b[i]-1]=1;
	G[b[i]-1][a[i]-1]=1;
      }
    }
    /*
    rep(i,a.size()){
      rep(j,a.size()){
	cout<<G[i][j]<<" ";
      }
      puts("");
    }
    */
    vector<char> visited(a.size(),false);
    int loopcnt=0;
    stack<pair<int ,int > > stk;
    stk.push(make_pair(0,-1));
    while(!stk.empty()){
      int now=stk.top().first;
      int prev=stk.top().second;stk.pop();
      printf("pre %d : now %d : visited %d \n",prev+1,now+1,visited[now]);
      if(visited[now]==1){
	loopcnt++;
	continue;
      }
      visited[now]=1;
      rep(nxt,a.size()){
	if(nxt!=prev && G[now][nxt]>0)
	  stk.push(make_pair(nxt,now));
      }
    }
    loopcnt/=2;
    cout<<loopcnt<<endl;
    if(!inc){
    if(!mult and loopcnt==1)inc=false;
    else if(mult and loopcnt==0)inc=false;
    else inc=true;
    }
    
    string ans;
    if(!inc)
      ans="Correct";
    else
      ans="Incorrect";
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
			int h                     = 3;
			int a[]                   = {1, 2, 3, 7, 1, 5, 4};
			int b[]                   = {6, 7, 4, 3, 3, 1, 7};
			string expected__         = "Correct";

			std::clock_t start__      = std::clock();
			string received__         = TheKingsRoadsDiv2().getAnswer(h, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int h                     = 2;
			int a[]                   = {1, 2, 3};
			int b[]                   = {2, 1, 3};
			string expected__         = "Incorrect";

			std::clock_t start__      = std::clock();
			string received__         = TheKingsRoadsDiv2().getAnswer(h, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int h                     = 3;
			int a[]                   = {7, 1, 1, 2, 2, 3, 1};
			int b[]                   = {7, 1, 7, 4, 5, 2, 6};
			string expected__         = "Incorrect";

			std::clock_t start__      = std::clock();
			string received__         = TheKingsRoadsDiv2().getAnswer(h, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int h                     = 2;
			int a[]                   = {1, 3, 3};
			int b[]                   = {2, 1, 2};
			string expected__         = "Correct";

			std::clock_t start__      = std::clock();
			string received__         = TheKingsRoadsDiv2().getAnswer(h, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int h                     = 3;
			int a[]                   = {6, 5, 3, 3, 5, 5, 6};
			int b[]                   = {1, 5, 5, 6, 4, 7, 2};
			string expected__         = "Correct";

			std::clock_t start__      = std::clock();
			string received__         = TheKingsRoadsDiv2().getAnswer(h, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int h                     = ;
			int a[]                   = ;
			int b[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TheKingsRoadsDiv2().getAnswer(h, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int h                     = ;
			int a[]                   = ;
			int b[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TheKingsRoadsDiv2().getAnswer(h, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int h                     = ;
			int a[]                   = ;
			int b[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TheKingsRoadsDiv2().getAnswer(h, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
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
