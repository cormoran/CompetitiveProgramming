#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include<ctime>


using namespace std;

string query(string url) {

  FILE *f = popen(("curl -s \"" + url + "\"").c_str(), "r");

    if (f == NULL) {
        perror("error!");
    }
    char buf[1024];
    string res;
    while (!feof(f)) {
        if (fgets(buf, 1024, f) == NULL) break;
        res += (string)(buf);
    }
    fclose(f);
    return res;
}

int main() {

  srand(time(NULL));
  string token  = "CDO1V37RNSLDXXYPF37KIK4L7LCT43BP";//ここにトークンを入れる


  string ans="";
  
  int i;
  while(true){
    ans="";
    for(i=0;i<50;i++){
      char c[2];
      c[0]='A'+rand()%4;
      c[1]=0;
      ans.insert(ans.size(),c);
    }
    cout<<ans<<endl;
    string url    = "https://game.coderunner.jp/q?str="+ans +"&token=" +token;
    string result = query(url);
    cout << result << endl;
    sleep(2);
  }
  return 0;
}
