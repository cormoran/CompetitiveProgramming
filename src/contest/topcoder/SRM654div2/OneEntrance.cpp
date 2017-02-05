#include <bits/stdc++.h>
using namespace std;
typedef long long int64;typedef int int32;
typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) (v).begin(),(v).end()

class OneEntrance {
public:

  vector< vector<int> > G;
  int N;
  
  inline bool can_do(vector<int> &v){
    vector< vector<int> > g(N);
    rep(i,N)g[i]=G[i];


    rep(i,v.size()){
      int cnt=0;
      rep(j,N){cnt+=g[v[i]][j];g[v[i]][j]=0;g[j][v[i]]=0;}
      if(cnt>1)return false;
    }
    return true;
  }
  
  int count( vector <int> a, vector <int> b, int s ) {
    N=a.size()+1;
    G.resize(N,vector<int>(N,0));
    rep(i,a.size()){
      G[a[i]][b[i]]=1;
      G[b[i]][a[i]]=1;
    }
    /*
    rep(i,N){
      rep(j,N)cout<<G[i][j]<<" ";
      puts("");
    }
    */
    vector<int> v ;
    rep(i,N){
      if(i!=s)
	v.push_back(i);
    }

    int ans=0;
    do{
      if(can_do(v))ans++;
    }while(next_permutation(all(v)));
    
    return ans;
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
			int a[]                   = {0, 1, 2};
			int b[]                   = {1, 2, 3};
			int s                     = 0;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = OneEntrance().count(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a[]                   = {0, 1, 2};
			int b[]                   = {1, 2, 3};
			int s                     = 2;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = OneEntrance().count(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a[]                   = {0, 0, 0, 0};
			int b[]                   = {1, 2, 3, 4};
			int s                     = 0;
			int expected__            = 24;

			std::clock_t start__      = std::clock();
			int received__            = OneEntrance().count(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a[]                   = {7, 4, 1, 0, 1, 1, 6, 0};
			int b[]                   = {6, 6, 2, 5, 0, 3, 8, 4};
			int s                     = 4;
			int expected__            = 896;

			std::clock_t start__      = std::clock();
			int received__            = OneEntrance().count(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a[]                   = {};
			int b[]                   = {};
			int s                     = 0;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = OneEntrance().count(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int a[]                   = ;
			int b[]                   = ;
			int s                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = OneEntrance().count(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int a[]                   = ;
			int b[]                   = ;
			int s                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = OneEntrance().count(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a[]                   = ;
			int b[]                   = ;
			int s                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = OneEntrance().count(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), s);
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
