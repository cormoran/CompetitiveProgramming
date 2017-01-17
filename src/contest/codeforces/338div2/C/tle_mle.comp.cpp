//  codeforces - 338div2 - C  / 2016-01-08
#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<tuple>
#include<array>
#include<memory>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

template<typename T>ostream& operator << (ostream &os , const vector<T> &v){
    rep(i,v.size()) os << v[i] << (i!=v.size()-1 ? " " : "\n"); return os;
}
template<typename T>istream& operator >> (istream &is , vector<T> &v){
    rep(i,v.size()) is >> v[i]; return is;
}

#ifdef DEBUG
void debug(){ cerr << endl; }
#endif
template<class F,class...R> void debug(const F &car,const R&... cdr){
#ifdef DEBUG
    cerr << car << " "; debug(cdr...);
#endif
}

// TrieTree を使った文字列をキーとした連想配列
class TrieTree{
  public:
    struct Data{
        int l,r;
    };
    using Data_p = shared_ptr<Data>;

    struct Node{
        shared_ptr<Data> data;
        array<shared_ptr<Node>,'z'-'a'+1> children;
        Node():data(nullptr){ fill(all(children),nullptr); }
    };
    using Node_p = shared_ptr<Node>;
    
    Node_p root;
    TrieTree(){ root = make_shared<Node>(); }
    Data& operator [] (const string &s) const {
        Node_p node = get(s);
        return *node->data;
    }

    // insert :  nodeをrootとして s に data を登録 すでに存在する場合は更新しない
    Node_p insert(Node_p node, char c, const Data &data){
        assert( node != nullptr );
        int idx = c-'a';
        if(node->children[idx] == nullptr){
            node->children[idx] = make_shared<Node>();
            node->children[idx]->data = make_shared<Data>(data);
        }
        return node->children[idx];
    }
    Node_p insert(const string &s, const Data &data){
        return insert(root, s, data);
    }
    Node_p insert(Node_p node, const string &s, const Data &data){
        assert( node != nullptr );
        for(char c : s){
            int idx = c-'a';
            if( node->children[idx] == nullptr ){
                node->children[idx] = make_shared<Node>();
            }
            node = node->children[idx];
        }
        node->data = make_shared<Data>(data);
        return node;
    }
    // get : keyがsのノードを返す、存在しない場合はnullptr
    Node_p get(const string &s) const {
        return get(root, s);
    }
    Node_p get(Node_p node, const string &s) const {
        assert( node != nullptr );
        for(char c : s){
            int idx = c - 'a';
            if( node->children[idx] == nullptr ) return nullptr;
            node = node->children[idx];
        }
        return node;
    }
};


class TrieTreeExt : public TrieTree{
  public:
    Data_p goDown(Node_p node, const string &s, int &i){
        assert( node != nullptr );
        // data == nullptr のnodeがないと仮定
        Node_p nxt = node->children[s[i++]-'a'];
        if( nxt == nullptr ) return nullptr;
        
        while(nxt != nullptr and i < (int)s.size()){
            int idx = s[i++] - 'a';
            node = nxt;
            nxt = node->children[idx];
        }
        if(nxt == nullptr) i--;
        return ( nxt != nullptr ? nxt->data : node->data);
    }
    
    void resister(const string &s){
        rep(i,s.size()){
            Node_p node = root;
            Data data;
            data.l = i;
            for(int j=i;j<(int)s.size();j++){
                data.r = j;
                node = insert(node,s[j],data);
            }
        }
        rep(i,s.size()){
            Node_p node = root;
            Data data;
            data.l = s.size()-1-i;
            for(int j=(int)s.size()-1-i;j>=0;j--){
                data.r = j;
                node = insert(node,s[j],data);
            }
        }
    }
    
    vector<Data> count(const string &t){
        int i = 0;
        vector<Data> data;
        while(i<(int)t.size()){
                 Data_p d = goDown(root, t, i);
            if( d == nullptr ) return {};
            data.push_back(*d);
        }
        return data;
    }
};


bool solve(){
    string s,t; cin >> s >> t;
    TrieTreeExt tree;
    tree.resister(s);
    vector<TrieTree::Data> ans = tree.count(t);
    if( ans.size() == 0 ) cout << -1 <<endl;
    else {
        cout << ans.size() <<endl;
        for(auto& d : ans){
            cout << d.l+1 << " " << d.r+1 <<endl;
        }
    }    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(solve());
    return 0;
}
