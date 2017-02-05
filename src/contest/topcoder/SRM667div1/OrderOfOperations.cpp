#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long  ll;
#define rep(i,j) for(ll i=0;i<j;i++)
#define all(v) v.begin(),v.end()

  string state;
  int calc(const string &s){
    int sp=0;
    rep(i,s.size()){
      if(s[i]=='1'&&state[i]!='1')sp++;
    }
    return sp;
  }
int calc_update(const string &s){
  int sp=0;
  rep(i,s.size()){
    if(s[i]=='1'&&state[i]!='1'){
      sp++;
      state[i]='1';
    }
  }
  return sp;
}


class OrderOfOperations {
public:

  
  static bool comp(const string &s1,const string &s2){
    return calc(s1)>calc(s2);
  }
  
   int minTime( vector <string> s ) {
     state.resize(s[0].size());
     rep(i,state.size())state[i]='0';
     int ans=0;
     while(s.size()>0){
       sort(all(s),comp);

       rep(i,s.size()){
         cout<<s[i]<<" ";
       }
       putchar('\n');

       int k=calc_update(s.back());
       cout<<"k :"<<k<<endl;
       ans+=k*k;
       s.pop_back();
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
			string s[]                = {
 "111",
 "001",
 "010"
};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = OrderOfOperations().minTime(vector <string>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string s[]                = {
 "11101",
 "00111",
 "10101",
 "00000",
 "11000"
};
			int expected__            = 9;

			std::clock_t start__      = std::clock();
			int received__            = OrderOfOperations().minTime(vector <string>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string s[]                = {
  "11111111111111111111"
};
			int expected__            = 400;

			std::clock_t start__      = std::clock();
			int received__            = OrderOfOperations().minTime(vector <string>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string s[]                = {
  "1000",
  "1100",
  "1110"
};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = OrderOfOperations().minTime(vector <string>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string s[]                = {
  "111",
  "111",
  "110",
  "100"
};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = OrderOfOperations().minTime(vector <string>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
        string s[]                = {"1011","0010","0110","1001","0001","0000"};
			int expected__            = 16;

			std::clock_t start__      = std::clock();
			int received__            = OrderOfOperations().minTime(vector <string>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
        /*      case 6: {
			string s[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = OrderOfOperations().minTime(vector <string>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string s[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = OrderOfOperations().minTime(vector <string>(s, s + (sizeof s / sizeof s[0])));
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
