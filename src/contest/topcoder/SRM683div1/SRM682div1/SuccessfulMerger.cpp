#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pll;
#define rep(i,j) for(ll i=0;i<j;i++)
#define repeat(i,j,k) for(ll i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()

class SuccessfulMerger {
public:
    vector<vector<int>> E;
    vector<vector<int>> L;
    int loop_root = -1;
    bool loop_dfs(int now, int pre, vector<bool> &visited){
        visited[now] = true;
        for(int nxt : E[now]){
            if(nxt != pre){
                if(visited[nxt] or loop_dfs(nxt, now, visited)){
                    if(visited[nxt]) loop_root = nxt;
                    L[now].push_back(nxt);
                    L[nxt].push_back(now);
                    if(loop_root == now) loop_root = -1;
                    visited[now] = false;
                    return loop_root >=0;
                }
            }
        }
        visited[now] = false;
        return false;
    }
    
    
    int dfs(int now, int pre, vector<bool> &visited, bool loop){
        int ret = 0;
        bool flg = false;
        vector<bool> visited2(E.size());
        visited[now] = true;
        
        if(not loop and L[now].size() > 0){
            int ret2 = 1<<30;
            for(int nxt : L[now]){
                visited2[nxt] = true;
                ret2 = min(ret2,dfs(nxt, now, visited, true));
            }
            ret = ret2;
            flg = true;
        }
        
        for(int nxt : E[now]){
            if(nxt == pre) continue;
            if(not visited[nxt] and not visited2[nxt]){
                ret += dfs(nxt, now, visited, loop);
                flg = true;
            }
        }
        visited[now] = false;
        if(flg){
            ret += 1;
            // cerr << "+ now " << now << endl;
        } else {
            //cerr << "0 now " << now << endl;
        }
        return ret;
    }
    
    int minimumMergers( vector <int> road ) {
        E.resize(road.size());
        L.resize(road.size());
        rep(i,road.size()){
            bool flg = false;
            rep(j,E[i].size()){
                if(E[i][j] == road[i]) flg = true;
            }
            if(flg) continue;
            E[i].push_back(road[i]);
            E[road[i]].push_back(i);
        }
        vector<bool> visited(E.size());
        loop_dfs(0, -1, visited);

        // rep(i,L.size()){
        //     rep(j,L[i].size()){
        //         cerr << "L " << i << " to " << L[i][j] << endl;
        //     }
        // }
        
        int ans = 1 << 30;
        visited.resize(E.size(), false);
        rep(i,E.size()){
            //cerr << endl << "start " << i << endl;
            ans = min(ans, dfs(i, -1, visited, false));
        }
        return max(0,ans-1);
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
			int road[]                = {2, 2, 1, 1, 1};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = SuccessfulMerger().minimumMergers(vector <int>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int road[]                = {3, 4, 5, 4, 5, 3};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = SuccessfulMerger().minimumMergers(vector <int>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int road[]                = {1, 0, 1, 0, 0, 0, 1, 0, 1, 1};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = SuccessfulMerger().minimumMergers(vector <int>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int road[]                = {1, 2, 3, 0};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = SuccessfulMerger().minimumMergers(vector <int>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int road[]                = {31, 19, 0, 15, 30, 32, 15, 24, 0, 20, 40, 1, 22, 21, 39, 28, 0, 23, 15, 5, 19, 22, 6, 32, 8, 38, 35, 30, 4, 28, 32, 18, 18, 9, 22, 41, 20, 18, 6, 25, 41, 34, 4};
			int expected__            = 25;

			std::clock_t start__      = std::clock();
			int received__            = SuccessfulMerger().minimumMergers(vector <int>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int road[]                = {1, 0};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = SuccessfulMerger().minimumMergers(vector <int>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int road[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SuccessfulMerger().minimumMergers(vector <int>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int road[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SuccessfulMerger().minimumMergers(vector <int>(road, road + (sizeof road / sizeof road[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int road[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SuccessfulMerger().minimumMergers(vector <int>(road, road + (sizeof road / sizeof road[0])));
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
