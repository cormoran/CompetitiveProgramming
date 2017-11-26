const int alpha_size = 'z' - 'a' + 1;
//const int alpha_size = 256;

int calc_index(char c){ return c; }

struct Node{
    vector<int> accept;
    array<Node*, alpha_size> next;
    Node * fail;
    Node(){
        fill( all(next), nullptr);
        fail = nullptr;
    }
};

class AhoCorasick{
    Node *root;
    int pattern_num;
  public:
    AhoCorasick(const vector<string> &patterns){
        root = new Node();
        pattern_num = patterns.size();
        assign(patterns);
        build_fail();
    }

    ~AhoCorasick(){
        function<void(Node*)> delete_child = [&](Node* node){
            if(node == nullptr or node == root) return;
            for(Node* nxt : node->next) delete_child(nxt);
            delete node;
        };
        delete_child(root);
    }

    vector<int> search(const string &s){
        int n = s.size();
        vector<int> result(pattern_num);
        Node* node = root;
        rep(i, n){
            int idx = calc_index(s[i]);
            while(node->next[idx] == nullptr) node = node->fail;
            node = node->next[idx];
            for(int a : node->accept) result[a]++;
        }
        return result;
    }

  private:
    void assign(const vector<string> &patterns){
        rep(i, patterns.size()){
            Node *node = root;
            for(char c : patterns[i]){
                int idx = calc_index(c);
                if( node->next[idx] == nullptr ){
                    node->next[idx] = new Node();
                }
                node = node->next[idx];
            }
            node->accept.push_back(i);
        }
    }

    void build_fail(){
        queue<Node*> que;
        for(Node* &nxt : root->next){
            if(nxt != nullptr){
                nxt->fail = root;
                que.push(nxt);
            }
            else nxt = root;
        }

        while(not que.empty()){
            Node* node = que.front(); que.pop();
            rep(i, node->next.size()){
                Node* nxt = node->next[i];
                if(nxt != nullptr){
                    que.push(nxt);
                    Node* r = node->fail;
                    while(r->next[i] == nullptr) r = r->fail;
                    nxt->fail = r->next[i];
                }
            }
        }
    }

};
// （UVA10679 alpha size を変える必要あり)
bool solve(){
    string s; cin >> s;
    int n; cin >> n;
    vector<string> pattern(n);
    rep(i, n) cin >> pattern[i];
    AhoCorasick ac(pattern);
    vector<int> result = ac.search(s);
    rep(i, n) cout << (result[i] >= 1 ? "y" : "n") << endl;
    return false;
}