

vector<string> split(const string &s, char delim) {
    vector<int> pos;
    pos.push_back(-1);
    rep(i, s.size()) if(s[i] == delim) pos.push_back(i);
    pos.push_back(s.size());
    vector<string> res;
    rep(i, pos.size() - 1) res.push_back(s.substr(pos[i] + 1, pos[i + 1] - pos[i] - 1));
    return res;
}
