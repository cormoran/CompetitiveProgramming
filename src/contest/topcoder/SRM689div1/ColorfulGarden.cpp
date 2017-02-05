#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pll;
#define rep(i,j) for(ll i=0;i<j;i++)
#define repeat(i,j,k) for(ll i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()

class ColorfulGarden {
public:
    vector <string> rearrange( vector <string> garden ) {
        int n = garden[0].size();
        vector<pair<int,char>> cnt('z' - 'a' + 1);
        rep(i, cnt.size()) cnt[i].second = 'a' + i;
        rep(j, garden.size()) {
            rep(i, garden[j].size()) {
                cnt[garden[j][i] - 'a'].first++;
                garden[j][i] = '0';
            }
        }
        sort(all(cnt), greater<pair<int,char>>());
        vector<char> cs;
        rep(i, cnt.size()) {
            rep(j, cnt[i].first) {
                cs.push_back(cnt[i].second);
            }
        }

        rep(i, n) {
            garden[i % 2][i] = cs[i];
            if(garden[(i+1) % 2][i] == cs[i] or
               (i > 0 and garden[i % 2][i-1] == cs[i]) or
               (i < n -1 and garden[i % 2][i+1] == cs[i]) ) {
                return {};
            }
        }        
        rep(i, n) {
            garden[(i+1) % 2][i] = cs[i + n];
            if(garden[i % 2][i] == cs[i + n] or
               (i > 0 and garden[(i+1) % 2][i-1] == cs[i + n]) or
               (i < n -1 and garden[(i+1) % 2][i+1] == cs[i + n]) ) {
                return {};
            }
        }        
        return garden;
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
	template<> std::ostream& operator<<(std::ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, std::clock_t elapsed) { 
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
			string garden[]           = {"aa",
 "bb"};
			string expected__[]       = {"ab", "ba" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = ColorfulGarden().rearrange(vector <string>(garden, garden + (sizeof garden / sizeof garden[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string garden[]           = {"xxxx",
 "xxxx"};
			string expected__[]       = { };

			std::clock_t start__      = std::clock();
			vector <string> received__ = ColorfulGarden().rearrange(vector <string>(garden, garden + (sizeof garden / sizeof garden[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string garden[]           = {"abcd",
 "abcd"};
			string expected__[]       = {"abcd", "dcba" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = ColorfulGarden().rearrange(vector <string>(garden, garden + (sizeof garden / sizeof garden[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string garden[]           = {"abcdefghijklm",
 "nopqrstuvwxyz"};
			string expected__[]       = {"abcdefghijklm", "nopqrstuvwxyz" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = ColorfulGarden().rearrange(vector <string>(garden, garden + (sizeof garden / sizeof garden[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string garden[]           = {"aaa",
 "aab"};
			string expected__[]       = { };

			std::clock_t start__      = std::clock();
			vector <string> received__ = ColorfulGarden().rearrange(vector <string>(garden, garden + (sizeof garden / sizeof garden[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string garden[]           = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = ColorfulGarden().rearrange(vector <string>(garden, garden + (sizeof garden / sizeof garden[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string garden[]           = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = ColorfulGarden().rearrange(vector <string>(garden, garden + (sizeof garden / sizeof garden[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string garden[]           = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = ColorfulGarden().rearrange(vector <string>(garden, garden + (sizeof garden / sizeof garden[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
