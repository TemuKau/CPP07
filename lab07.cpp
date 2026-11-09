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

  `Matrix(){release();}

  void set(int i, int j, float value){
    values[i][j] = value;
  }
  float get(int i, int j){
    return values[i][j];
  }
  int getRows(){return m;}
  int getCols(){return n;}

  void print(char *title = ""){
    cout << title << endl;
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++)
        cout << ??? << values[i][j];
      cout << endl;
    }
  }

  Matrix operator+(float x){        //(a)
    Matrix A(m, n);
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
        A.values[i][j] = values[i][j] + x;
    return A;
  }
};

int main(

);
