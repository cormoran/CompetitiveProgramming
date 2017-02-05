#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include<boost/format.hpp>
#include<chrono>

using namespace std;

string query(string url) {
    FILE *f = popen(("curl -s -k \"" + url + "\"").c_str(), "r");
    if (f == NULL) {
        perror("error!");
    }
    char buf[1024];
    string res;
    while (!feof(f)) {
        if (fgets(buf, 1024, f) == NULL) break;
        res += (string)(buf);
    }
    pclose(f);
    return res;
}


const string token  = "uPzze7i8edUrWFXgGCleucAKlXTWm2VL";
const string url_base = "http://sample.coderunner.jp/q?str=%1%&token=%2%";


string generate(){
    string s;
    s.resize(8);
    for(int i=0;i<8;i++){
        s[i]=rand()%4 + 'A';
    }
    return s;
}

int main() {
    srand(time(NULL));
    for (int itr = 0; itr < 10; itr++) {
        string s = generate();
        string url = str(boost::format(url_base) % s % token);
        string result = query(url);
        cout << s <<" "<< result << endl;
        sleep(1);
    }
    return 0;
}
