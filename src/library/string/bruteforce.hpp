/*
  文字列検索


 */

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

// src から pattern を検索する O(n*m)
vector<int> bruteforce(const string &src, const string &pattern){
    assert( pattern.size() > 0 );
    if( src.size() < pattern.size()) return {};

    vector<int> ret;
    rep(i, src.size() - pattern.size() + 1){
        bool flg = true;
        rep(j, pattern.size()){
            if(src[i+j] != pattern[j]){
                flg = false;
                break;
            }
        }
        if(flg) ret.push_back(i);
    }
    return ret;
}

// 任意の配列で比較
template<class T>
vector<int> bruteforce(const vector<T> &src, const vector<T> &pattern){
    assert( pattern.size() > 0 );
    if( src.size() < pattern.size()) return {};

    vector<int> ret;
    rep(i, src.size() - pattern.size() + 1){
        bool flg = true;
        rep(j, pattern.size()){
            if(src[i+j] != pattern[j]){
                flg = false;
                break;
            }
        }
        if(flg) ret.push_back(i);
    }
    return ret;
}


#define BOOST_TEST_MAIN    // main関数を定義
#include <boost/test/included/unit_test.hpp>
 
BOOST_AUTO_TEST_CASE(hoge){
    string src = "asdfghjkl";
    string pattern = "asdf";
    vector<int> expect = {0}, ret = bruteforce(src, pattern);
    BOOST_CHECK_EQUAL_COLLECTIONS(ret.begin(), ret.end(), expect.begin(), expect.end());
}
 
BOOST_AUTO_TEST_CASE(fuga){
    string src = "aaaaa";
    string pattern = "aa";
    vector<int> expect = {0,1,2,3}, ret = bruteforce(src, pattern);
    BOOST_CHECK_EQUAL_COLLECTIONS(ret.begin(), ret.end(), expect.begin(), expect.end());
}
 
//BOOST_AUTO_TEST_SUITE_END()
