#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include<vector>


using namespace std;

typedef struct
{
  string id,name,token,prfile;
  int room,score;
  vector< pair<int,int> > history;//<ダメージ,技ID>
}info;

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

info get_info()
{
  string filter="all"
  sting style="text"
  string url="https://game.coderunner.jp/info?token="+token+"&filter="+filter+"&style="+style;
  string ans=query(url);
  string temp="";
  int i=0;
  info ret;
  while(ture)
    {
      while(ans[i]!='\n');
      i++;
      while(ans[i]!='\n')
	  temp+=ans[i++];
      ret.id=temp;
      i++;
      temp="";
      while(ans[i]!='\n')
	  temp+=ans[i++];
      ret.name=temp;
      i++;
      temp="";
      while(ans[i]!='\n');//token
      i++;
      while(ans[i]!='\n');
      i++;
      while(ans[i]!='\n')
	  temp+=ans[i++];
      ret.room=stoi(temp);
      i++;
      temp="";
      while(ans[i]!='\n')
	  temp+=ans[i++];
      ret.score=stoi(temp);
      i++;
      temp="";
      while(ans[i]!='\n')
	  temp+=ans[i++];
      i++;
      while(ans.substr(
      while(ans[i]!='\n')
	{
	  temp="";
	  while(ans[i]!=' ')
	    temp+=ans[i++];
	  i++;
	  
	}
	  temp+=ans[i++];
    }

}



int main() {

	int skill=0;
        string url    = "https://game.coderunner.jp/attack?skill="+std::to_string(skill)+"&token=" + token;
        string result = query(url);
        cout << result << endl;
        sleep(1);
    return 0;
}
