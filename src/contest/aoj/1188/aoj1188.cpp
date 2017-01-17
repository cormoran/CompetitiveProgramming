#include<iostream>
#include<string>
#include<queue>

using namespace std;

string line;

typedef struct{
  int ans;
  int s;
}orig;


/*一つの選挙の最小人数を求める
来るデータ~~~~~~]~~~~]~~~]
頭の[は取ってある
関数内で]を取ってかえす
*/
orig rec(int s){
  priority_queue<int,vector<int>,greater<int> > box;
  int ans=0,i=0;
  orig val;
  while(s<line.size() && line.at(s)=='['){
    s++;
    val=rec(s);
    box.push(val.ans);
    s=val.s;
  }

  if(s<line.size() && line.at(s)==']'){
    /*第一弾以外のとき*/
    //cout<< box.size()<<"size ";
    for(i=0;(i<=(box.size())/2+1);i++){
      ans+=box.top();
      //            cout << box.top()<<"top ";
      box.pop();
    }
    s++;     
  }
  else {
    /*[でも]でもない　つまり数字　つまり第一段 line = 122121][~~~ で来る
     条件よりboxは今empty*/
    int i=0;
    while(line.at(s+i)!=']')i++;
    ans=(stoi(line.substr(s,i))+1)/2;//iはat(i)で]の位置、at(i)はsubstrでi+1番目
    //        cout<<ans<<"&  ";
    s+=i+1;
  }
  orig a;
  a.ans=ans;a.s=s;
  return a;
  
}

int main(){
  int n,i;
  orig ans;
  cin >>n;
  for(i=0;i<n;i++){
    //string line;
    line="";
    cin >> line;
    //getline(cin,line);
    ans=rec(1);
    cout <<ans.ans<<endl;
  }
}
