#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <queue>
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pll;
#define rep(i,j) for(ll i=0;i<j;i++)
#define repeat(i,j,k) for(ll i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()

const int UP = 150000 + 1;

class HardProof {
  public:
    int N;
    vector<vector<int>> G;
    int calc(int tail)  {
        int ans = 0;
        set<int> visited;
        set<int> nv;
        repeat(i, 1, N) nv.insert(i);
        visited.insert(0);
        rep(i, N - 1) {
            auto cand = nv.begin();
            int tmp = UP;
            for(auto now = nv.begin(); now != nv.end(); now++) {
                int g = UP, r = UP;
                for(int v : visited) {
                    if(tail <= G[*now][v]) g = min(g, G[*now][v]);
                    if(tail <= G[v][*now]) r = min(r, G[v][*now]);
                }
                if(max(g, r) < ans) {
                    cand = now;
                    tmp = max(g, r);
                    cerr << "update" << endl;
                }
            }
            if(tmp == UP) return UP;
            visited.insert(*cand);
            nv.erase(cand);
            ans = max(tmp, ans);
        }
        cerr << tail << " " << ans << endl;
        return ans - tail;
    }
    
    int minimumCost( vector <int> D ) {
        N = sqrt(D.size());
        if(N * N < D.size()) N++;
        G.resize(N, vector<int>(N));
        rep(i, N) rep(j, N) {
            G[i][j] = D[i * N + j];
        }
        int ans = 1 << 30;
        rep(i, D.size()) {
            ans = min(ans, calc(D[i]));
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
			int D[]                   = {0,11,13,13, 10,0,12,13, 10,10,0,11, 12,10,10,0};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = HardProof().minimumCost(vector <int>(D, D + (sizeof D / sizeof D[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int D[]                   = {0,1000,1000,1000,1000, 1,0,1000,1000,1000, 1,1,0,1000,1000, 1,1,1,0,1000, 1,1,1,1,0};
			int expected__            = 999;

			std::clock_t start__      = std::clock();
			int received__            = HardProof().minimumCost(vector <int>(D, D + (sizeof D / sizeof D[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int D[]                   = {0,95,1,10, 95,0,76,33, 1,76,0,49, 10,33,49,0};
			int expected__            = 32;

			std::clock_t start__      = std::clock();
			int received__            = HardProof().minimumCost(vector <int>(D, D + (sizeof D / sizeof D[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int D[]                   = {0,136946,89305,28946, 40152,0,150000,85407, 122920,110420,0,32811, 2092,79717,53028,0} ;
			int expected__            = 50771;

			std::clock_t start__      = std::clock();
			int received__            = HardProof().minimumCost(vector <int>(D, D + (sizeof D / sizeof D[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int D[]                   = {0,2159,2234,2720,2029,2853,2187, 2564,0,2409,2519,2441,2665,2654, 2666,2575,0,2215,2978,2588,2582, 2067,2743,2156,0,2840,2970,2480, 2724,2057,2136,2044,0,2030,2424, 2860,2512,2026,2867,2594,0,2401, 2893,2194,2802,2892,2151,2554,0} ;
			int expected__            = 206;

			std::clock_t start__      = std::clock();
			int received__            = HardProof().minimumCost(vector <int>(D, D + (sizeof D / sizeof D[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int D[]                   = {0,44,47,42,44,45,47,42,47,43,46,46,42,47,47,45,44,46,43,47,44,43,43,47,47,44,46,47,44,44,46,43,44,42,42,44,43,43,46,44,45,44,43,43,42,47,47,45,45,42, 44,0,44,43,43,46,44,47,43,46,44,42,42,46,44,44,45,44,43,46,46,46,47,47,44,47,42,44,45,44,42,42,43,46,46,44,43,44,42,45,44,45,44,45,46,44,42,47,43,43, 42,46,0,42,44,43,42,42,43,46,45,45,45,45,46,46,47,46,42,42,43,45,44,43,45,47,47,47,45,47,46,44,43,46,42,47,42,47,43,43,47,45,44,42,44,44,47,47,42,45, 45,43,47,0,47,42,43,47,47,45,43,43,46,46,43,43,43,45,42,45,42,45,47,45,42,47,45,44,42,44,42,43,45,45,42,47,45,42,45,47,43,44,42,42,45,47,44,42,47,45, 43,43,46,47,0,44,47,42,45,45,46,46,42,45,43,47,42,45,42,47,44,43,43,45,47,46,47,44,43,42,42,47,44,42,45,47,44,44,44,47,43,42,46,47,46,47,44,43,45,45, 42,43,44,45,43,0,43,43,43,44,42,47,42,44,47,45,46,43,47,46,47,43,44,45,43,47,44,44,46,43,43,43,44,43,43,46,47,47,43,44,44,44,44,47,43,43,43,47,45,47, 46,45,46,43,47,42,0,43,42,46,42,42,42,44,47,46,46,43,46,44,42,45,45,46,47,47,47,47,42,47,46,45,42,47,45,45,44,44,47,42,47,43,43,44,47,46,47,44,43,45, 46,43,45,47,44,47,45,0,44,43,45,47,44,45,44,47,45,42,47,46,44,46,44,44,45,45,43,47,44,44,45,45,42,42,42,42,45,46,42,43,43,42,44,45,47,46,47,47,45,42, 46,46,47,44,43,46,44,42,0,43,44,45,43,46,43,42,45,43,43,42,46,47,43,44,44,42,44,47,45,46,42,45,43,45,44,42,45,45,42,43,46,47,43,46,47,46,43,47,46,45, 43,46,45,44,43,45,42,42,46,0,44,47,43,42,46,42,45,45,46,45,47,44,45,44,46,47,45,43,45,46,46,45,47,44,46,42,44,46,44,44,46,43,42,45,42,43,42,45,44,44, 42,45,46,42,46,42,42,45,44,47,0,45,43,44,44,46,43,42,42,42,45,47,44,44,44,47,44,43,43,47,42,45,47,42,45,45,43,42,45,42,47,44,44,44,44,45,42,45,43,42, 47,47,46,43,44,45,45,42,42,43,44,0,43,43,43,46,42,43,42,43,43,46,47,47,42,43,46,47,43,42,43,42,45,45,42,47,45,42,42,44,46,44,43,42,47,47,46,47,47,46, 42,43,42,43,43,46,43,47,47,44,44,45,0,47,44,42,44,44,42,46,44,44,46,42,46,47,43,45,46,42,43,46,43,45,42,47,47,47,45,47,47,45,47,45,42,47,43,42,45,44, 43,47,47,46,46,43,42,45,47,47,44,44,47,0,44,45,47,45,44,43,46,43,42,43,44,43,42,43,47,42,42,47,44,46,44,47,44,47,47,42,42,42,45,46,45,47,45,44,43,47, 43,47,47,42,44,42,45,43,44,47,43,42,46,42,0,43,46,44,42,43,47,45,47,46,46,42,47,42,42,44,44,47,42,43,44,42,42,44,43,45,46,45,42,45,43,47,47,46,45,47, 42,42,43,47,46,46,43,42,46,43,43,43,42,45,47,0,42,43,46,47,46,46,44,42,47,46,42,46,44,45,47,46,45,45,42,44,43,46,42,45,45,45,42,47,42,47,42,46,44,44, 42,44,45,46,42,45,44,45,47,43,44,45,44,45,46,42,0,43,44,44,46,45,45,43,42,43,47,46,46,43,46,47,46,45,43,47,44,42,42,47,45,46,46,47,43,42,44,43,47,47, 45,42,45,46,43,43,42,46,44,46,47,46,47,44,46,42,43,0,44,44,47,45,45,42,43,42,44,46,43,45,45,43,46,47,45,45,46,43,44,47,45,47,45,46,45,47,46,43,45,47, 42,45,47,47,46,42,42,43,43,47,46,42,43,47,46,43,42,45,0,42,45,46,42,47,43,47,42,47,44,44,42,44,45,44,46,44,43,46,42,47,46,43,44,47,42,42,44,47,42,45, 47,42,45,42,44,47,44,44,43,46,45,46,46,42,45,45,42,42,43,0,45,43,44,42,47,43,43,45,47,42,42,43,46,42,44,47,47,46,44,43,47,43,43,46,47,47,45,45,45,46, 42,42,46,46,45,44,42,43,43,45,44,44,46,42,44,46,47,42,43,45,0,43,42,42,46,46,42,45,45,45,44,46,45,43,43,47,42,47,47,43,44,43,44,44,46,45,44,43,43,46, 44,44,47,42,46,42,45,47,46,44,43,42,42,44,46,47,46,45,42,47,46,0,43,43,47,42,44,44,42,44,45,45,46,44,46,44,47,46,44,46,46,47,45,42,45,44,43,42,42,42, 43,42,44,44,42,44,44,42,47,42,47,47,47,45,45,43,43,45,47,47,46,42,0,42,45,42,47,42,44,43,46,46,42,46,43,43,45,43,46,47,44,42,47,45,43,46,46,47,44,45, 44,46,44,43,44,47,46,42,47,47,47,46,43,47,42,47,42,44,44,42,47,46,44,0,44,45,44,42,43,43,42,43,42,46,45,43,44,42,46,43,46,47,43,45,44,46,45,42,42,42, 47,46,44,44,42,47,43,47,47,46,42,45,44,43,44,43,45,42,43,43,42,42,45,46,0,46,43,45,43,47,44,42,47,43,42,43,46,45,45,43,43,42,45,45,44,45,42,42,45,45, 43,44,47,46,43,43,44,42,44,46,45,45,42,42,44,46,47,44,47,44,46,44,47,47,43,0,43,42,45,42,45,45,44,44,45,46,45,47,45,45,47,47,46,47,46,45,45,43,45,44, 46,42,46,42,44,44,45,45,44,44,46,45,43,43,47,43,44,44,43,46,46,43,47,47,45,44,0,44,42,43,47,42,42,47,44,43,45,47,44,43,44,47,43,45,47,42,43,45,46,42, 44,47,43,43,45,44,46,42,47,45,46,45,45,42,45,42,44,45,45,47,47,42,47,46,44,42,42,0,44,43,47,47,47,42,44,45,44,42,44,44,47,46,42,45,46,47,42,43,44,43, 42,43,42,44,45,45,47,42,42,45,43,47,45,46,46,44,42,46,43,42,47,42,43,47,47,44,45,42,0,42,43,46,46,44,44,45,42,45,43,45,44,42,45,43,44,45,47,47,44,45, 47,42,42,46,44,44,46,44,42,47,45,44,43,45,42,44,46,43,44,42,43,42,46,43,44,45,46,47,42,0,45,43,45,43,44,45,46,47,46,45,47,43,44,42,42,46,47,42,43,44, 44,44,45,46,47,42,42,45,44,42,44,47,47,44,45,45,45,43,46,42,45,47,43,43,42,44,43,47,47,42,0,47,43,45,45,44,46,43,42,42,44,42,45,43,46,43,42,47,43,42, 42,45,43,47,45,46,46,42,43,44,42,47,44,47,45,44,44,45,42,46,47,45,44,46,42,47,42,46,45,42,46,0,44,44,43,45,44,44,44,44,43,44,42,42,44,47,47,45,45,42, 43,43,43,46,44,43,43,46,45,45,44,43,42,45,47,42,45,45,46,42,44,42,46,47,43,44,42,44,42,46,43,47,0,42,42,42,45,47,46,45,43,46,45,45,46,47,45,44,45,46, 43,47,45,42,46,47,43,46,44,45,45,42,44,47,44,44,46,47,46,46,42,46,43,45,43,45,46,42,46,42,47,46,42,0,43,47,43,42,43,44,47,44,45,42,46,46,47,43,46,43, 42,42,44,45,43,45,45,47,47,45,45,43,42,45,42,45,45,43,43,43,46,42,44,47,43,43,42,43,46,42,47,46,47,43,0,44,45,46,42,47,45,44,46,45,46,44,47,46,42,44, 43,44,45,45,47,44,44,45,42,45,45,47,46,47,43,46,45,47,44,47,42,44,44,42,45,42,42,43,47,43,42,47,43,47,42,0,43,42,46,46,43,46,45,46,44,45,42,42,47,46, 45,47,42,45,45,42,42,44,42,44,42,42,47,47,43,46,47,47,42,43,42,44,42,46,45,44,47,43,45,42,44,44,47,43,43,46,0,45,46,42,43,47,46,44,45,43,47,42,43,46, 45,45,44,43,43,45,45,42,42,43,44,47,46,44,42,47,46,45,42,44,43,45,44,46,46,44,47,42,47,44,45,47,47,47,46,42,47,0,46,46,44,44,46,45,47,45,45,44,45,44, 47,42,45,46,43,47,42,43,47,42,42,42,46,42,44,42,42,46,45,43,44,46,47,47,43,47,45,44,45,42,46,47,44,44,43,47,42,42,0,46,46,45,47,42,45,46,44,43,44,42, 46,42,46,44,44,44,44,46,42,44,44,45,42,44,47,45,44,47,44,42,46,43,45,45,45,43,46,44,44,47,43,42,46,45,47,43,42,46,45,0,43,45,43,42,43,45,43,47,47,42, 43,44,46,43,45,42,42,43,43,45,42,46,42,47,45,44,43,42,47,44,42,42,42,44,42,42,46,44,45,42,47,42,42,44,42,46,47,42,44,44,0,45,44,43,45,44,42,47,43,47, 45,43,45,45,42,47,42,46,43,45,43,46,43,42,47,45,45,44,47,47,47,43,44,42,47,47,44,45,44,42,43,47,47,45,46,46,43,45,47,44,45,0,47,47,45,42,45,47,42,42, 46,42,45,45,47,46,47,46,45,43,43,43,46,45,46,46,47,44,45,44,46,47,45,42,45,45,45,42,44,43,45,42,47,47,46,44,43,45,46,45,44,43,0,44,45,46,47,45,46,43, 44,43,43,42,47,45,46,46,43,42,43,45,42,42,42,42,45,46,47,47,45,46,45,43,47,47,45,47,45,42,46,45,46,45,45,44,47,47,45,44,44,47,42,0,44,47,47,43,47,42, 46,46,45,47,42,42,47,42,47,45,44,47,46,46,45,43,44,42,44,43,43,47,43,43,47,44,42,42,46,42,46,44,47,47,45,45,44,42,45,47,44,45,46,43,0,44,45,45,46,47, 46,46,44,42,42,44,46,45,45,46,44,43,46,45,43,47,47,47,42,42,42,42,45,44,45,45,42,45,44,42,46,43,43,43,44,42,43,43,45,43,47,47,43,43,45,0,43,44,44,46, 43,43,42,42,45,47,42,46,44,45,45,45,45,42,44,45,42,43,45,43,43,43,47,43,44,45,47,43,47,45,43,43,45,42,46,47,43,47,44,43,43,42,42,42,43,45,0,44,42,42, 47,43,46,42,45,43,47,44,47,45,44,45,43,42,42,46,46,44,46,42,46,43,44,43,42,42,47,45,47,46,45,42,42,47,45,45,46,47,43,43,44,44,42,43,43,42,47,0,42,43, 45,45,46,47,42,47,46,46,43,44,46,47,43,46,46,42,47,45,42,45,47,42,42,45,47,43,42,43,43,42,45,47,45,43,43,45,43,43,47,42,46,43,45,46,47,45,47,46,0,45, 46,46,42,47,47,47,42,44,43,46,43,47,43,43,46,45,42,45,47,42,47,42,44,42,43,47,43,45,42,44,45,46,43,46,46,44,46,43,42,44,45,42,42,47,43,47,45,46,42,0};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = HardProof().minimumCost(vector <int>(D, D + (sizeof D / sizeof D[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int D[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = HardProof().minimumCost(vector <int>(D, D + (sizeof D / sizeof D[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int D[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = HardProof().minimumCost(vector <int>(D, D + (sizeof D / sizeof D[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int D[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = HardProof().minimumCost(vector <int>(D, D + (sizeof D / sizeof D[0])));
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
