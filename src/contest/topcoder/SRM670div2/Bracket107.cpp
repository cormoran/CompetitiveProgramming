#include<map>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<cassert>
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pll;
#define rep(i,j) for(ll i=0;i<j;i++)
#define repeat(i,j,k) for(ll i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()

class Bracket107 {
public:
    map<string,bool> memo;

    bool test(const string &str){
        int o=0,c=0;
        rep(i,(int)str.size()){
            (str[i]=='(' ? o : c) +=1;
            if(o<c)return false;
        }
        return o == c;
    }
    
   int yetanother( string s ) {
       int ans=0;
       memo[s]=true;
       rep(i,(int)s.size()){
           rep(j,(int)s.size()){
               string ns = s;
               ns.erase(i,1);
               int jj = (i<j ? j-1 : j);
               ns.insert(jj,s.substr(i,1));
               
               if(!memo[ns]){
                   memo[ns]=true;
                   if(test(ns)){
                       ans++;
                       //cerr << ns <<endl;
                   }
               }
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
			string s                  = "(())";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = Bracket107().yetanother(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "(())()";
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = Bracket107().yetanother(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = "()()()";
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = Bracket107().yetanother(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "(((())))";
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = Bracket107().yetanother(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string s                  = "((())())";
			int expected__            = 9;

			std::clock_t start__      = std::clock();
			int received__            = Bracket107().yetanother(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string s                  = "()()()()()()()()()()()()()()()()()()()()()()()()()";
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = Bracket107().yetanother(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string s                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Bracket107().yetanother(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string s                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Bracket107().yetanother(s);
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
