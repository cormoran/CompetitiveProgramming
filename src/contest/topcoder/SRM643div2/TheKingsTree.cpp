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

typedef long long int64;
typedef int int32;
typedef char int8;
typedef int32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) (v).begin(),(v).end()
typedef pair<int,int> pii;

const int INF=1<<30;//=10E10

class TheKingsTree {
public:
   int getNumber( vector <int> parent ) {
     vector<pii> col(parent.size()+1);//(red,green)
     col.resize(parent.size()+1);
     vector< vector<int> > child(parent.size()+1);
     rep(i,parent.size())
       child[parent[i]].push_back(i+1);
     int  ans=0;
     for(int i=parent.size();i>=0;i--){
       pii sumcol=pii(0,0);
       if(child[i].size()==0)
	 col[i]=pii(0,0);
       else{
	 for(int j : child[i]){
	   int s1f,s1s,s2f,s2s;
	   s1f=sumcol.first+col[j].first;
	   s2f=sumcol.first+col[j].second;

	   s2s=sumcol.second+col[j].first;
	   s1s=sumcol.second+col[j].second;
	   
	   int mins=min(min(s1f,s1s),min(s2f,s2f));

	   if(mins==s1f||mins==s1s){
	     sumcol.first+=col[j].first;
	     sumcol.second+=col[j].second;
	   }
	   else {
	     sumcol.first+=col[j].second;
	     sumcol.second+=col[j].first;
	   }
	 }
	 col[i]=sumcol;
       }
       if(col[i].first<=col[i].second){
	 ans+=col[i].first+1;
	 col[i].first++;
       }
       else{
	 ans+=col[i].second+1;
	 col[i].second++;
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
			int parent[]              = {0, 0, 0};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = TheKingsTree().getNumber(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int parent[]              = {0, 1, 2, 3, 4};
			int expected__            = 12;

			std::clock_t start__      = std::clock();
			int received__            = TheKingsTree().getNumber(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int parent[]              = {0, 1, 2, 3, 1};
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = TheKingsTree().getNumber(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int parent[]              = {0, 0, 1, 0, 4, 3, 5, 2, 0, 7, 9, 2, 4, 5, 3, 1};
			int expected__            = 26;

			std::clock_t start__      = std::clock();
			int received__            = TheKingsTree().getNumber(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int parent[]              = {};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = TheKingsTree().getNumber(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int parent[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TheKingsTree().getNumber(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int parent[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TheKingsTree().getNumber(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int parent[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TheKingsTree().getNumber(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
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
