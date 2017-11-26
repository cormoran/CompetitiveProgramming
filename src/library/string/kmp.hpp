/*

 * pattern を指定の文字列から検索 *

 next[i] = i == 0 の場合 -1
 max{ j | 0 < j < i | pattern[?] ... pattern[i-1] が pattern[0] ... pattern[j-1] と一致する }
 jが存在しない場合 0

 とすると、検索時に、pattern[0] から見ていってpattern[k]で失敗した場合、

 検索対象の位置はそのままで、pattern[ next[k] ] からやり直せば良い

 （pattern[?] ... pattern[k-1] は pattern[0] ... pattern[ next[k] - 1 ] と一致するから）

 （ただし、 next[i] == j になると直前と同じことをやり直すことになるので j < i
 同じ理由で next[0] = -1 とし、この場合は検索対象を一つ進めるとうまくいく）

 * next の構成例 *

 検索対象文字列 s, 検索文字列 p = "abab"とする

 next[0] = -1

 next[1] =  0

 next[2] =  0  :  p[? > 0] ... p[2-1] = {"b"} で、 j 存在しない(j = 2 は j < iでないのでx)

 next[3] =  1  :  p[? > 0] ... p[3-1] = {"ba", "a",} で j = 0 + 1

 next[4] =  2  :  p[? > 0] ... p[4-1] = {"bab", "ab", "b"} で j = 1 + 1

 * nextの構成方法 *

 next[0 ... i] が決まっているとする

 next[k] = a <=> p[0] ... p[a-1] == p[?] ... p[k-1] と

 next[a] = b <=> p[0] ... p[b-1] == p[??] ... p[a-1] から

 p[0] ... p[b-1] == p[???] ... p[k-1] である事がわかる

 next[k+1] = c <=> p[0] ... p[c-1] == p[?] ... p[k] なので、

 next[k+1] = if p[ next[k] ] == p[k] : next[k] + 1
 else if p[ next[ next[k] ] ] == p[k] : next[ next[k] ] + 1
 else ...

 みたいにdpで計算できる

 最終的に next[0] = -1 に達した時に終われば、 next[k+1] = -1 + 1 = 0 とうまくいく

*/

class KMP{
    const string pattern;
    vector<int> next;
  public :
    KMP(const string &p) : pattern(p){
        int m = p.size();
        next.resize(m + 1);
        next[0] = -1;
        int j = -1;
        rep(i, m){
            while( j >= 0 and p[j] != p[i]) j = next[j];
            // assert( j = -1 or p[j] == p[i] );
            next[i+1] = ++j;
        }
    }

    // sを対象にして patternを探索
    // 各一致の先頭indexを返す
    vector<int> search(const string &s){
        const string &p = pattern;
        vector<int> matches;
        int k = 0;
        rep(i, s.size()){
            while(k >= 0 and p[k] != s[i]) k = next[k];
            if(++k == (int)p.size()){
                matches.push_back(i - p.size() + 1);
                k = next[k];
            }
        }
        return matches;
    }
};

template<class T>
class KMP2{
    const vector<T> pattern;
    vector<int> next;
  public :
    KMP2(const vector<T> &p) : pattern(p){
        int m = p.size();
        next.resize(m + 1);
        next[0] = -1;
        int j = -1;
        rep(i, m){
            while( j >= 0 and p[j] != p[i]) j = next[j];
            // assert( j = -1 or p[j] == p[i] );
            next[i+1] = ++j;
        }
    }
    // sを対象にして patternを探索
    // 各一致の先頭indexを返す
    template<class InputIterator>
    vector<int> search(InputIterator first, InputIterator last){
        const vector<T> &p = pattern;
        vector<int> matches;
        int k = 0;
        for(int i = 0; first != last; first++, i++){
            while(k >= 0 and p[k] != *first) k = next[k];
            if(++k == (int)p.size()){
                matches.push_back(i - p.size() + 1);
                k = next[k];
            }
        }
        return matches;
    }
};
