#include <bits/stdc++.h>
using namespace std;
typedef long long int64;typedef int int32;
typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) (v).begin(),(v).end()

class Similars {
public:
  
   int maxsim( int L, int R ) {
     int free=-1;

     int tmp=1;
     int d=R-L;
     while(true){
       if(d>=tmp)free++;
       else break;
       tmp*=10;
     }

     L/=tmp;
     R/=tmp;
     bool flg[10]={};
     int a=L%10;
     for(;a<=10;a++){
       flg[a%10]=true;
     }

     L/=10;
     R/=10;
     int ans=0;
     rep(i,min((int)log10(L),(int)log10(R))){
       if(L%10==R%10){
	 ans++;
	 flg[L%10]=false;	 
       }
       L/=10;
       R/=10;
     }
     rep(i,10){
       if(flg[i]){
	 ans++;
	 break;
       }
     }
     ans+=free;
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
			int L                     = 1;
			int R                     = 10;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = Similars().maxsim(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int L                     = 1;
			int R                     = 99;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = Similars().maxsim(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int L                     = 99;
			int R                     = 100;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = Similars().maxsim(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int L                     = 1000;
			int R                     = 1010;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = Similars().maxsim(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int L                     = 444;
			int R                     = 454;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = Similars().maxsim(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int L                     = ;
			int R                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Similars().maxsim(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int L                     = ;
			int R                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Similars().maxsim(L, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int L                     = ;
			int R                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Similars().maxsim(L, R);
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
