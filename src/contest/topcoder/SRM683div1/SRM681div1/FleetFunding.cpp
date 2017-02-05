#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pll;
#define rep(i,j) for(ll i=0;i<j;i++)
#define repeat(i,j,k) for(ll i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()

class FleetFunding {
  public:
    struct Item{ int k,a,b; };
    struct ItemComp{
        int m;
        ItemComp(int m):m(m) {}
        bool operator ()(const Item &s,const Item &t){
            int sa = max(m,s.a), ta = max(m,ta);
            return sa != ta ? sa < ta : s.b < t.b;
        }
    };
    bool C(int m, int num, vector<Item> shop){
        int pos = 0;
        cerr << "mid = " << num << endl;
        repeat(i,1,m+1){
            sort(shop.begin() + pos, shop.end(), cmp(i));
            while(shop[pos].b < i) if(++pos >= shop.size()) return false;
            if(i < shop[pos].a) return false;
            int need = num;
            while( need > 0){
                int dec = min(shop[pos].k, need);
                shop[pos].k -= dec;
                need -= dec;
                if(shop[pos].k == 0){
                    if(i == m and need == 0) return true;
                    do{
                        pos++;
                        if(pos >= shop.size()) return false;
                    }while(shop[pos].b < i);
                    if(i < shop[pos].a) return false;
                }
            }
            //cerr << "clear " << i << endl;
        }
        return true;
    }

    void viz(int m,const vector<Item> &shop){
        rep(i,shop.size()){
            repeat(j,1,m+1){
                if(j > shop[i].b){
                    break;
                }
                else if(j < shop[i].a) putchar(' ');
                else putchar('*');
            }
            cout << endl;
        }
    }
    
    int maxItemhips( int m, vector <int> k, vector <int> a, vector <int> b ) {
        vector<S> shop(k.size());
        rep(i,shop.size()){
            shop[i].k = k[i];
            shop[i].a = a[i];
            shop[i].b = b[i];
        }
        
        sort(all(shop));
        //viz(m,shop);
        int h = 5000000;
        int l = 0;
        while(l+1 < h){
            int mid = (h+l) / 2;
            if( C(m,mid,shop) ){
                l = mid;
            } else {
                h = mid;
            }
        }
        return l;
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
			int m                     = 3;
			int k[]                   = {2,2,2};
			int a[]                   = {1,2,1};
			int b[]                   = {3,3,2};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = FleetFunding().maxShips(m, vector <int>(k, k + (sizeof k / sizeof k[0])), vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int m                     = 1;
			int k[]                   = {10,9,8,7,6,5,4,3,2,1};
			int a[]                   = {1,1,1,1,1,1,1,1,1,1};
			int b[]                   = {1,1,1,1,1,1,1,1,1,1};
			int expected__            = 55;

			std::clock_t start__      = std::clock();
			int received__            = FleetFunding().maxShips(m, vector <int>(k, k + (sizeof k / sizeof k[0])), vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int m                     = 10;
			int k[]                   = {2,4,6,8,10,1,3,5,7,9};
			int a[]                   = {1,2,3,4,5,6,7,8,9,10};
			int b[]                   = {1,2,3,4,5,6,7,8,9,10};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = FleetFunding().maxShips(m, vector <int>(k, k + (sizeof k / sizeof k[0])), vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int m                     = 84457;
			int k[]                   = {374778,169109,529984,498638,29462,465769,29285,394948,307944,459189, 349316,766627,686851,404285,850199,359378,3014,248257,558856,27393,32370, 574862,337134,965567,32223,935678,389898,973497,990575,483190,122899, 857994,991217,149619,415870};
			int a[]                   = {92,4997,11,28545,933,210,2,124,114,4513,32959,1,57,17,13,133,1843,41851, 3,9296,9757,28,3,769,10,11102,683,6173,11821,3982,214,2,4304,439,1998};
			int b[]                   = {81034,54474,70239,79597,47317,82938,83883,74652,84033,84422,84456,84457, 81095,83743,79210,84255,84455,45596,84456,82959,67062,80330,44090,84445, 84454,84450,45931,77190,83025,83567,83639,84333,83355,70982,84456};
			int expected__            = 186;

			std::clock_t start__      = std::clock();
			int received__            = FleetFunding().maxShips(m, vector <int>(k, k + (sizeof k / sizeof k[0])), vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int m                     = 2;
			int k[]                   = {1000000,1000000,1000000,1000000,1000000};
			int a[]                   = {1,1,1,2,2};
			int b[]                   = {1,1,2,2,2};
			int expected__            = 2500000;

			std::clock_t start__      = std::clock();
			int received__            = FleetFunding().maxShips(m, vector <int>(k, k + (sizeof k / sizeof k[0])), vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int m                     = ;
			int k[]                   = ;
			int a[]                   = ;
			int b[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FleetFunding().maxShips(m, vector <int>(k, k + (sizeof k / sizeof k[0])), vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int m                     = ;
			int k[]                   = ;
			int a[]                   = ;
			int b[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FleetFunding().maxShips(m, vector <int>(k, k + (sizeof k / sizeof k[0])), vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int m                     = ;
			int k[]                   = ;
			int a[]                   = ;
			int b[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FleetFunding().maxShips(m, vector <int>(k, k + (sizeof k / sizeof k[0])), vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
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
