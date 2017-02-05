#include<cmath>
#include<vector>
#include<iostream>
#include<cassert>
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pll;
#define rep(i,j) for(ll i=0;i<j;i++)
#define repeat(i,j,k) for(ll i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()

class TreeAndPathLength3 {
public:

    vector <int> construct2( int s ,int k) {
        int n = s, m = 1;
        while( n + (k>0 ? m-1 : m) + 3 + k > 500 or (k > 0 and m == 1)){
            bool flg = false;
            for(int i = 2;i<=sqrt(n);i++){
                if( n % i == 0){
                    n /= i;
                    m *= i;
                    flg = true;
                    break;
                }
            }
            if(not flg) return {};
        }
        if(k>0)m--;
        
        vector<int> v;
        v.reserve(2*(n+m+2));
        v.push_back(0);
        v.push_back(1);
        int ii = 2;
        rep(i,m){
            v.push_back(1);
            v.push_back(ii++);
        }
        rep(i,n){
            v.push_back(0);
            v.push_back(ii++);
        }
        if(k > 0){
            int kk =  ii++;
            v.push_back(kk-1);
            v.push_back(kk);
            rep(i,k){
                v.push_back(kk);
                v.push_back(ii++);
            }
        }   
        
        return v;
    }
    
    vector <int> construct( int s ) {
        vector<int> ans;
        rep(k,s){
            ans = construct2(s-k,k);
            if(ans.size() > 0) return ans;
        }
        assert(0);
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
			int s                     = 1;
			int expected__[]          = {0, 1, 1, 2, 2, 3 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeAndPathLength3().construct(s);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int s                     = 2;
			int expected__[]          = {0, 1, 1, 2, 2, 3, 3, 4 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeAndPathLength3().construct(s);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int s                     = 6;
			int expected__[]          = {0, 1, 1, 2, 0, 3, 3, 4, 0, 5, 5, 6 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeAndPathLength3().construct(s);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int s                     = 8;
			int expected__[]          = {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeAndPathLength3().construct(s);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int s                     = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeAndPathLength3().construct(s);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int s                     = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeAndPathLength3().construct(s);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int s                     = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = TreeAndPathLength3().construct(s);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
    TreeAndPathLength3 a;
    cout << a.construct(498).size() << endl;
    rep(i,10000){
        cout << a.construct(i+1).size() << endl;
    }
    
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
