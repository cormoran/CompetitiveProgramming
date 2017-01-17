#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
  bool flg=false,bflg;
int i;
  while(!flg){
    /*行ループ*/
    string s;
    stack<char> box;
    char ch;
    getline(cin,s);

    if(s==".")flg=true;
    else {
      /*区画ループ*/
      bflg=true;
      box.push('s');
      
      for(i=0;i<s.size();i++){
	ch=s.at(i);
	if(ch=='('||ch=='[')box.push(ch);
	else if(ch==')'){
	  if(box.top()=='(')box.pop();
	  else{
	    bflg=false;
	    break;
	  }
	}
	else if(ch==']'){
	  if(box.top()=='[')box.pop();
	  else{
	    bflg=false;
	    break;
	  }
	}
	else if(ch=='.'){
	  break;
	}	  
      }
      if(bflg==true && box.top()=='s')cout<<"yes"<<endl;
      else cout<<"no"<<endl;
    }
  }
}
