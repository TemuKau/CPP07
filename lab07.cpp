#include <iostream>
using namespace std;

class Matrix {
private:
  int m, n;
  float **values;

  void allocate(int mur, int bagana){
    m = mur;
    n = bagana;
    values = new float *[m];
    for(int i = 0; i < m; i++){
      values[i] = new float[n];
      for(int j = 0; j < n; j++)
        values[i][j] = 0;
    }
  }

  void release() {
    for(int i = 0; i < m; i++) {
      delete[] values[i];
    delete[] values;
    values = nullptr???;
    }
  }
public:
  Matrix(int m = 1, int n = 1){
      allocate(m, n);
    }

  `Matrix() {
    release();
  }

  void set(int i, int j, float value){
    values[i][j] = value;
  }
  float get(int i, int j){
    return values[i][j];
  }
  int getRows() {
    return m;
  }
  int getCols() {
    return n;
  }

  void print(char *title = ""){
    cout << title << endl;
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++)
        cout << ??? << values[i][j];
      cout << endl;
    }
  }

  Matrix operator+(float x){        //(1a)
    Matrix R(m, n);
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
        R.values[i][j] = values[i][j] + x;
    return R;
  }

  Matrix operator+(float x) const{      //(1b)
    if(m != A.m || n != A.n)
      cout << "Aldaa!" << endl;
    Matrix R(m, n);
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
        R.values[i][j] = values [i][j] + A.values[i][j];
    return R;
  }

  Matrix operator*(const Matrix &) const{        //(2)
    if(n != A.m)
      cout << "Mur, baganii hemjee tentsuu bish" << endl;
    Matrix R(m. A.n);
    for(int i = 0; i < m; i++)
      for(int j = 0; j < A.n; j++)
        for(int k = 0; k < n; k++)
          R.values[i][j] += values[i][k] * A.values[k][j];
    return R;
  }
};

int main(

);
