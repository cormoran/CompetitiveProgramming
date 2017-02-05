#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include<ctime>
#include<vector>
#include<algorithm>

using namespace std;

string query(string url) {

#ifdef _MSC_VER
// Windowsは同梱のcurl.exeを適当なフォルダに配置してcurlコマンドを使えるようにしておくこと。
    FILE *f = _popen(("C:\\bin\\curl.exe -s \"" + url + "\"").c_str(), "r");
#else
// Linux,MacOS,Cygwinはパッケージ管理システムなどでインストールしてcurlコマンドを使えるようにしておくこと。
    FILE *f = popen(("curl -s \"" + url + "\"").c_str(), "r");
#endif

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
  vector< pair<int,string> > box;  
  int i;
  for(i=0;i<100;i++){
    string ans="";
    int j;
    for(j=0;j<50;j++){
      char c[2];
      c[0]='A'+rand()%4;
      c[1]='\0';
      ans.insert(ans.size(),c);
    }
    cout<<ans<<endl;
    string token  = "CDO1V37RNSLDXXYPF37KIK4L7LCT43BP";//ここにトークンを入れる
    string url    = "http://game.coderunner.jp/q?str="+ans+"&token=" +token;
    //cout<<url<<endl;
    string result = query(url);
    cout << result << endl;
    pair<int,string> item;
    item.first=stoi(result);
    item.second=ans;
    box.push_back(item);
    sleep(2);
  }
  cout<<"result"<<endl<<endl;
  sort(box.begin(),box.end());
  for(i=0;i<100;i++)
    {
      cout<<box[i].first<<" "<<box[i].second<<endl;
    }
  return 0;
}
