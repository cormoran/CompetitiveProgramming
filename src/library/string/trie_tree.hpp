/// codeforces 338 div2 TLE MLE
/// 注意 : 操作未検証!!

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

#endif
