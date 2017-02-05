#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pll;
#define rep(i,j) for(ll i=0;i<j;i++)
#define repeat(i,j,k) for(ll i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()

class ParenthesesDiv1Easy {
public:
   vector <int> correct( string s ) {
       if(s.size() % 2 == 1) return {-1};
       stack<pair<char,int>> stk;
       int l = 0, r = 0;
       rep(i, s.size()) {
           if(stk.size() and stk.top().first == '(' and s[i] == ')') stk.pop();
           else {
               if(s[i] == '(') l++;
               else r++;
               stk.push(make_pair(s[i],i));
           }
       }
       vector<int> ans;
       int change_l = stk.size() / 2;
       if(stk.size() and stk.top().first == '('){

           int e = stk.top().second;
           int s = e;
           rep(i, change_l){
               if(stk.top().first == ')') break;
               s = stk.top().second; stk.pop();
           }
           ans.push_back(s);
           ans.push_back(e);
           while(stk.size() and stk.top().first == '(') stk.pop();
       }
       int change_r = change_l;
       if(stk.size() and stk.top().first == ')'){
           while(stk.size() > change_r or stk.top().first == '(') stk.pop();
           int e = stk.top().second;
           while(stk.size() > 1) stk.pop();
           int s = stk.top().second;
           ans.push_back(s);
           ans.push_back(e);
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
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
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
			string s                  = ")(";
			int expected__[]          = {0, 0, 1, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ParenthesesDiv1Easy().correct(s);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string s                  = "))))))((((((";
			int expected__[]          = {0, 5, 6, 11 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ParenthesesDiv1Easy().correct(s);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string s                  = "))()())()";
			int expected__[]          = {-1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ParenthesesDiv1Easy().correct(s);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string s                  = ")()(((";
			int expected__[]          = {0, 0, 3, 3, 5, 5 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ParenthesesDiv1Easy().correct(s);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string s                  = "()";
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ParenthesesDiv1Easy().correct(s);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string s                  = "(()()()()()())";
			int expected__[]          = {};

			std::clock_t start__      = std::clock();
			vector <int> received__   = ParenthesesDiv1Easy().correct(s);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
      case 6: {
			string s                  = "";
			int expected__[]          = {};

			std::clock_t start__      = std::clock();
			vector <int> received__   = ParenthesesDiv1Easy().correct(s);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
      case 7: {
			string s                  = "))()()()())()))))))  )))((((((((()()()()()()))(()()())";
			int expected__[]          = {0, 1};

			std::clock_t start__      = std::clock();
			vector <int> received__   = ParenthesesDiv1Easy().correct(s);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
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
