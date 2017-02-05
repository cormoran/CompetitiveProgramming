#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pll;
#define rep(i,j) for(ll i=0;i<(ll)j;i++)
#define repeat(i,j,k) for(ll i=(j);i<(k);i++)

class BearCavalry {
public:
    const ll MOD = 1000000007LL;
    vector<int> horse,people;

    ll  bikkuri(ll n){
        if(n<=1)return 1;
        return (n*bikkuri(n-1))%MOD;
    }
    
    int rec(int top_power , vector<bool> &used ,int pos ) {
        if(pos >= people.size())return 0;
        int p = people[pos];
        int flg = -1;
        rep(i,horse.size()){
            if(not used[i]){
                int power = p * horse[i];
                if(power >= top_power){
                    flg = i;
                    break;
                }
            }
        }
        if(flg == -1) {
            //cout <<"bikkuri "<<pos<<endl;
            return bikkuri(people.size()-pos);
        }
        ll ret = 0;
        repeat(i,flg,horse.size()){
            if(not used[i]){
                int power = p * horse[i];
                if(power < top_power){
                    used[i]=true;
                    ret += rec(top_power,used,pos+1);
                    ret %= MOD;
                    used[i]=false;
                }
            }
        }
        return ret;
    }
    
    int countAssignments( vector <int> warriors, vector <int> horses ) {
        int top = warriors[0];
        warriors.erase(warriors.begin());
        sort(warriors.begin(),warriors.end(),greater<int>());
        people = move(warriors);
        sort(horses.begin(),horses.end(),greater<int>());
        horse = horses;
        
        ll ret = 0;
        vector<bool> used(horses.size(),false);
        rep(i,horses.size()){
            used[i]=true;
            ret += rec(top * horse[i], used, 0);
            ret %= MOD;
            used[i]=false;
        }
        return ret;
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
			int warriors[]            = {5,8,4,8};
			int horses[]              = {19,40,25,20};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = BearCavalry().countAssignments(vector <int>(warriors, warriors + (sizeof warriors / sizeof warriors[0])), vector <int>(horses, horses + (sizeof horses / sizeof horses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int warriors[]            = {1,1};
			int horses[]              = {1,1};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = BearCavalry().countAssignments(vector <int>(warriors, warriors + (sizeof warriors / sizeof warriors[0])), vector <int>(horses, horses + (sizeof horses / sizeof horses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int warriors[]            = {10,2,10};
			int horses[]              = {100,150,200};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = BearCavalry().countAssignments(vector <int>(warriors, warriors + (sizeof warriors / sizeof warriors[0])), vector <int>(horses, horses + (sizeof horses / sizeof horses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int warriors[]            = {10,20};
			int horses[]              = {1,3};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = BearCavalry().countAssignments(vector <int>(warriors, warriors + (sizeof warriors / sizeof warriors[0])), vector <int>(horses, horses + (sizeof horses / sizeof horses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int warriors[]            = {20,20,25,23,24,24,21};
			int horses[]              = {20,25,25,20,25,23,20};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = BearCavalry().countAssignments(vector <int>(warriors, warriors + (sizeof warriors / sizeof warriors[0])), vector <int>(horses, horses + (sizeof horses / sizeof horses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int warriors[]            = {970,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800, 800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800};
			int horses[]              = {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000, 1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000, 1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
			int expected__            = 318608048;

			std::clock_t start__      = std::clock();
			int received__            = BearCavalry().countAssignments(vector <int>(warriors, warriors + (sizeof warriors / sizeof warriors[0])), vector <int>(horses, horses + (sizeof horses / sizeof horses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
                    case 6: {
			int warriors[]            = {970,100,200,300,400,500,600,700,110,120,130,140,150,160,170,180,190,210,220,230,240,250,260,270,280, 800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800};
			int horses[]              = {1000,100,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000, 1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,10,1,2,400, 5000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
			int expected__            = 318608048;

			std::clock_t start__      = std::clock();
			int received__            = BearCavalry().countAssignments(vector <int>(warriors, warriors + (sizeof warriors / sizeof warriors[0])), vector <int>(horses, horses + (sizeof horses / sizeof horses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int warriors[]            = ;
			int horses[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearCavalry().countAssignments(vector <int>(warriors, warriors + (sizeof warriors / sizeof warriors[0])), vector <int>(horses, horses + (sizeof horses / sizeof horses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int warriors[]            = ;
			int horses[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearCavalry().countAssignments(vector <int>(warriors, warriors + (sizeof warriors / sizeof warriors[0])), vector <int>(horses, horses + (sizeof horses / sizeof horses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int warriors[]            = ;
			int horses[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearCavalry().countAssignments(vector <int>(warriors, warriors + (sizeof warriors / sizeof warriors[0])), vector <int>(horses, horses + (sizeof horses / sizeof horses[0])));
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
