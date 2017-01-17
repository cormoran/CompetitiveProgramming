//  codeforces - 338div2 - C  / 2016-01-08
#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

class TrieTree{
  public:
    struct Data{ int l,r; };
    struct Node{
        Data* data;
        map<char,Node*> children;
        Node():data(nullptr){ data = nullptr; }
    };
    Node root;
    Node* insert(Node* node, char c, const Data &data){
        if(node->children[c] == nullptr){
            node->children[c] = new Node();
            node->children[c]->data = new Data(data);
        }
        return node->children[c];
    }
};


class TrieTreeExt : public TrieTree{
  public:
    Data* goDown(Node* node, const string &s, int &i){
        Node* nxt = node->children[s[i++]];
        if( nxt == nullptr ) return nullptr;
        
        while(nxt != nullptr and i < (int)s.size()){
            int idx = s[i++];
            node = nxt;
            nxt = node->children[idx];
        }
        if(nxt == nullptr) i--;
        return ( nxt != nullptr ? nxt->data : node->data);
    }
    
    void resister(const string &s){
        rep(i,s.size()){
            Node* node = &root;
            Data data;
            data.l = i;
            for(int j=i;j<(int)s.size();j++){
                data.r = j;
                node = insert(node,s[j],data);
            }
        }
        rep(i,s.size()){
            Node* node = &root;
            Data data;
            data.l = s.size()-1-i;
            for(int j=(int)s.size()-1-i;j>=0;j--){
                data.r = j;
                node = insert(node,s[j],data);
            }
        }
    }

    int count1(const string &t){
        int i = 0, cnt = 0;
        while(i<(int)t.size()){
            Data* d = goDown(&root, t, i);
            if( d == nullptr ) return -1;
            cnt++;
        }
        return cnt;
    }
    
    void count2(const string &t){
        int i = 0;
        while(i<(int)t.size()){
            Data* d = goDown(&root, t, i);
            cout << d->l + 1 << " " << d->r +1 <<endl;
        }
    }
};


bool solve(){
    string s,t; cin >> s >> t;
    TrieTreeExt tree;
    tree.resister(s);
    int cnt = tree.count1(t);
    cout << cnt <<endl;
    if(cnt >=0) tree.count2(t);    
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
