#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include<ctime>

using namespace std;

string token  = "CDO1V37RNSLDXXYPF37KIK4L7LCT43BP";


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

int main() {
  srand(time(NULL));
  int max=0;
  string maxurl= "https://game.coderunner.jp/attack?skill=0&token=" + token;
  while(1)
    {
	int skill=rand()%100;
        string url    = "https://game.coderunner.jp/attack?skill="+std::to_string(skill)+"&token=" + token;
        string result = query(url);
        cout << result << endl;
        sleep(1);
	if(stoi(result)>max)
	  {
	    maxurl=url;
	    max=stoi(result);
	    result=query(maxurl);
	    cout << result << endl;
	    if(max!=stoi(result))
	      {
		max=0;
		continue;
	      }
	    sleep(1);
	    result=query(maxurl);
	    cout << result << endl;
	    if(max!=stoi(result))
	      {
		max=0;
		continue;
	      }
	    sleep(1);
	  }
    }
    return 0;
}
