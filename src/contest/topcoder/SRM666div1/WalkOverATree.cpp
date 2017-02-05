#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef pair<int,int> pii;
typedef map<int,int> mii;
#define rep(i,j) for(ll i=0;i<j;i++)
#define repeat(i,j,k) for(ll i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()
const int INF=1<<30;
class WalkOverATree {
public:
  vector<vector<int>> edge;
  int get_depth(int now,int pre){
    int dep=0;
    for(nxt : edge[now]){
      if(nxt==pre)continue;
      dep=max(dep,get_depth(nxt,now)+1);
    }
    return dep;
  }
  
  int maxNodesVisited( vector <int> parent, int L ) {
    int n=parent.size()+1;
    edge.resize(n);
    rep(i,parent.size()){
      edge[i+1].push_back(parent[i]);
      edge[parent[i]].push_back(i+1);
    }
    //最後以外は往復
    int max_dep=get_depth(0,-1);
    if(L-max_dep>=0){
      return min(n,min(L+1,max_dep + (L-max_dep)/2 +1));
    }
    else{
      return min(L+1,n);
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
			int parent[]              = {0, 0};
			int L                     = 2;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int parent[]              = {0, 0};
			int L                     = 3;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int parent[]              = {0, 1, 2, 3};
			int L                     = 2;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int parent[]              = {0,0,0,0,2,4,2,3,1};
			int L                     = 1;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int parent[]              = {0,0,1,2,3,2,3,1,3,0,1,8,6,8,0,5,15,0,9};
			int L                     = 4;
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int parent[]              = {0,0,0,1,1,3,5,1,4,5,2,2,10,5,10,10,11,13,8,3,18,15,20,20,23,8,11,26,4};
			int L                     = 26;
			int expected__            = 17;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int parent[]              = {0, 0, 2, 0} ;
			int L                     = 100;
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int parent[]              = {0, 0, 2};
			int L                     = 4;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int parent[]              = ;
			int L                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int parent[]              = ;
			int L                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int parent[]              = ;
			int L                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = WalkOverATree().maxNodesVisited(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), L);
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
