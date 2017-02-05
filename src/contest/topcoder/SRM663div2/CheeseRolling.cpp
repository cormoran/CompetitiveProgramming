#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include<queue>
#include<cmath>
typedef long long  int64;
typedef long long  ll;
typedef int64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) v.begin(),v.end()

using namespace std;

class CheeseRolling {
public:
  ll MEMO[ (1<<16) + 1 ][16];
  vector<ll> ans;
  int N;
  ll TEMP[16];
  void rec(unsigned int state,vector<string> &wins){
    if(MEMO[state][0]>=0){
      rep(i,N){
        ans[i]+=MEMO[state][i];
        TEMP[i]=MEMO[state][i];
      }
      return;
    }
    if(__builtin_popcount(state)==1){
      rep(i,N){
        MEMO[state][i]=0;
        TEMP[i]=0;
        if(state&(1<<i)){
          MEMO[state][i]+=N;
          TEMP[i]=N;
          ans[i]+=N;
        }
      }
      return;
    }
    rep(i,N){
      if(state&(1<<i)){
        //i消す?
        rep(j,N){
          if((state&(1<<j)) && wins[j][i]=='Y'){
            rec(state & ~(1<<i),wins);
            rep(k,N){
              MEMO[state][k]=TEMP[k];
            }
          }
        }
      }
    }
  }
  
  vector<long long> waysToWin( vector <string> wins ) {
    N=wins.size();
    rep(i,(1<<16)+1)rep(j,16)MEMO[i][j]=-1;
    rep(i,16)TEMP[i]=0;
    ans.resize(N,0);
    
    unsigned int st=0;
    rep(i,wins.size())st|=1<<i;
    rec(st,wins);
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

	int verify_case(int casenum, const vector<long long> &expected, const vector<long long> &received, std::clock_t elapsed) { 
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
			string wins[]             = {"NN",
 "YN"};
			long long expected__[]    = {0, 2};

			std::clock_t start__      = std::clock();
			vector<long long> received__ = CheeseRolling().waysToWin(vector <string>(wins, wins + (sizeof wins / sizeof wins[0])));
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string wins[]             = {"NYNY",
 "NNYN",
 "YNNY",
 "NYNN"};
			long long expected__[]    = {8, 0, 16, 0};

			std::clock_t start__      = std::clock();
			vector<long long> received__ = CheeseRolling().waysToWin(vector <string>(wins, wins + (sizeof wins / sizeof wins[0])));
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string wins[]             = {"NYNYNYNY",
 "NNYNYNYY",
 "YNNNNNNN",
 "NYYNNYNY",
 "YNYYNYYY",
 "NYYNNNNN",
 "YNYYNYNN",
 "NNYNNYYN"};
			long long expected__[]    = {4096, 8960, 0, 2048, 23808, 0, 1408, 0};

			std::clock_t start__      = std::clock();
			vector<long long> received__ = CheeseRolling().waysToWin(vector <string>(wins, wins + (sizeof wins / sizeof wins[0])));
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string wins[]             = {"NYNNNNYYNYYNNYNN",
 "NNNNNNNNNYYNYYNY",
 "YYNYYNNNNYYYYYYN",
 "YYNNYYYNYNNYYYNY",
 "YYNNNYYNYYNNNNYY",
 "YYYNNNNYYNNYYNYN",
 "NYYNNYNYNYNYYYYN",
 "NYYYYNNNYYNYNYYY",
 "YYYNNNYNNYYYYNNN",
 "NNNYNYNNNNNNYYNY",
 "NNNYYYYYNYNYYYNN",
 "YYNNYNNNNYNNYNNY",
 "YNNNYNNYNNNNNYNN",
 "NNNNYYNNYNNYNNYY",
 "YYNYNNNNYYYYYNNN",
 "YNYNNYYNYNYNYNYN"};
			long long expected__[]    = {331616878592LL, 37267079168LL, 2426798866432LL, 2606831599616LL, 994941665280LL, 1162501849088LL, 1888166674432LL, 4632734203904LL, 832881524736LL, 84707409920LL, 3007127748608LL, 55490052096LL, 17818550272LL, 254672666624LL, 629921447936LL, 1959311671296LL};

			std::clock_t start__      = std::clock();
			vector<long long> received__ = CheeseRolling().waysToWin(vector <string>(wins, wins + (sizeof wins / sizeof wins[0])));
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string wins[]             = {"NYYYYYYYYYYYYYYY",
 "NNYYYYYYYYYYYYYY",
 "NNNYYYYYYYYYYYYY",
 "NNNNYYYYYYYYYYYY",
 "NNNNNYYYYYYYYYYY",
 "NNNNNNYYYYYYYYYY",
 "NNNNNNNYYYYYYYYY",
 "NNNNNNNNYYYYYYYY",
 "NNNNNNNNNYYYYYYY",
 "NNNNNNNNNNYYYYYY",
 "NNNNNNNNNNNYYYYY",
 "NNNNNNNNNNNNYYYY",
 "NNNNNNNNNNNNNYYY",
 "NNNNNNNNNNNNNNYY",
 "NNNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNNNNN"};
			long long expected__[]    = {20922789888000LL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

			std::clock_t start__      = std::clock();
			vector<long long> received__ = CheeseRolling().waysToWin(vector <string>(wins, wins + (sizeof wins / sizeof wins[0])));
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string wins[]             = ;
			long long expected__[]    = ;

			std::clock_t start__      = std::clock();
			vector<long long> received__ = CheeseRolling().waysToWin(vector <string>(wins, wins + (sizeof wins / sizeof wins[0])));
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string wins[]             = ;
			long long expected__[]    = ;

			std::clock_t start__      = std::clock();
			vector<long long> received__ = CheeseRolling().waysToWin(vector <string>(wins, wins + (sizeof wins / sizeof wins[0])));
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string wins[]             = ;
			long long expected__[]    = ;

			std::clock_t start__      = std::clock();
			vector<long long> received__ = CheeseRolling().waysToWin(vector <string>(wins, wins + (sizeof wins / sizeof wins[0])));
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
