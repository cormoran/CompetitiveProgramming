#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cassert>
#include<cstdint>
//#include<>
using namespace std;

typedef int64_t i64;typedef int32_t i32;
typedef int16_t i16;typedef int8_t i8;
typedef uint64_t ui64;typedef uint32_t ui32;
typedef uint16_t ui16;typedef uint8_t ui8;

typedef i32 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define repeat_eq(i,j,k) for(int__ i=(j);i<=(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30; // = 10E10

// 簡易的な行列クラス
// typedefよりは使いやすいけどtypedef並み
template<typename T>
class Mat : public vector<vector<T>>{
public:
    Mat(int r,int c){
        assert( r > 0 and c > 0);
        this->resize(r,vector<T>(c));
    }
    int rows() const { return this->size(); }
    int cols() const { return (*this)[0].size(); }
    
    Mat operator * (const Mat &b) const {
        assert( this->cols() == b.cols() );
        Mat ans( this->rows(), b.cols() );
        rep(r, this->rows()){
            rep(c, b.cols()){
                ans[r][c] = 0;
                rep(i, this->cols()){
                    ans[r][c] += (*this)[r][i] * b[i][c];
                }
            }
        }
        return ans;
    }
    
    
    Mat operator + (const Mat &b) const {
        assert( this->rows() == b.rows() and this->cols() == b.cols() );
        Mat ans = (*this);
        rep(r, this->rows()){
            rep(c, this->cols()){
                ans[r][c] += b[r][c];
            }
        }
    }

    Mat operator - (const Mat &b) const {
        assert( this->rows() == b.rows() and this->cols() == b.cols() );
        Mat ans = (*this);
        rep(r, this->rows()){
            rep(c, this->cols()){
                ans[r][c] -= b[r][c];
            }
        }
    }
};

template<typename T>
ostream & operator << (ostream& os,const Mat<T>& a){
    rep(r, a.rows()){
        rep(c, a.cols()){
            os << a[r][c] << (c == a.cols()-1 ? "\n" : " ");
        }
    }
    return os;
}


int main()
{
  Mat<int> a(3,3),b(3,3);
  rep(i,3){
      a[i][i] = 1;
      b[i][i] = 2;
  }
  cout<<a<<endl;
  cout<<b<<endl;
  
  cout<<a*b<<endl;
  
  
  return 0;
}















