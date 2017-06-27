#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, j) for(int i=0; i < (int)(j); i++)
#define repeat(i, j, k) for(int i = (j); i < (int)(k); i++)
#define all(v) v.begin(),v.end()
#define debug(x) cerr << #x << " : " << x << endl
template<class T> bool set_min(T &a, const T &b) { return a > b  ? a = b, true : false; }
template<class T> bool set_max(T &a, const T &b) { return a < b  ? a = b, true : false; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "t" << t; return os << endl; }

const int INF = 1 << 30;
const ll INFL = 1LL << 60;

class ConstructLCS {
    public:
    string ret(array<string, 3> a) {
        return a[0] + " " + a[1] + " " + a[2];
    }
    // ab <= bc <= ca
    array<string, 3> construct2(int ab, int bc, int ca) {
        string A = string(ab, '0');
        string B = string(bc, '0');
        string C = B + string(ca - ab, '1');
        A += string(ca - ab, '1');
        return {A, B, C};
    }
    string construct(int ab, int bc, int ca) {
        if(ab <= bc and bc <= ca) {
            auto a = construct2(ab, bc, ca);
            return ret(a);
        }
        if(ca <= bc and bc <= ab) {
            auto a = construct2(ca, bc, ab);
            swap(a[1], a[2]);
            return ret(a);
        }
        if(ab <= ca and ca <= bc) {
            auto a = construct2(ab, ca, bc);
            swap(a[0], a[1]);
            return ret(a);
        }
        if(bc <= ca and ca <= ab) {
            auto a = construct2(bc, ca, ab);
            return ret({a[2], a[0], a[1]});
        }
        if(bc <= ab and ab <= ca) {
            auto a = construct2(bc, ab, ca);
            reverse(all(a));
            return ret(a);
        }
        if(ca <= ab and ab <= bc) {
            auto a = construct2(ca, ab, bc);
            return ret({a[1], a[2], a[0]});
        }
        assert(0);
    }
};

// CUT begin
ifstream data("ConstructLCS.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int ab, int bc, int ca, string __expected) {
    time_t startClock = clock();
    ConstructLCS *instance = new ConstructLCS();
    string __result = instance->construct(ab, bc, ca);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int ab;
        from_stream(ab);
        int bc;
        from_stream(bc);
        int ca;
        from_stream(ca);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(ab, bc, ca, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1498525216;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "ConstructLCS (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
