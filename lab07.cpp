#include <iostream>
using namespace std;

class Matrix{
private:
    int m, n;
    float **values;

public:
    Matrix(int m = 1, int n = 1){           //Байгуулагч
        this->m = m;
        this->n = n;

        if(m <= 0 || n <= 0){
            this->m = this->n = 0;
            values = nullptr;
            return;
        }

        values = new float*[m];
        for(int i = 0; i < m; i++)
            values[i] = new float[n];
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                values[i][j] = 0;
    }

    Matrix(const Matrix &A){            //Хуулбарлагч байгуулагч
        m = A.m;
        n = A.n;

        if(m == 0 || n == 0){
            values = nullptr;
            return;
        }
        values = new float*[m];

        for(int i = 0; i < m; i++){
            values[i] = new float[n];
            for(int j = 0; j < n; j++)
                values[i][j] = A.values[i][j];
        }
    }

    ~Matrix(){    //Устгагч
        if (values!=nullptr) {
        for(int i = 0; i < m; i++){
            delete[] values[i];
        }
        delete[] values;
        }
    }

    //set функц
    void set(int i, int j, float x){
        if(i >= 0 && i < m && j >= 0 && j < n)
            values[i][j] = x;
    }

    // get функц
    float get(int i, int j) const{
        if(i >= 0 && i < m && j >= 0 && j < n)
            return values[i][j];
        return 0;
    }

    void input(){              //Матриц оруулах
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> values[i][j];
    }

    void print() const{             // Матриц хэвлэх
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
                cout << values[i][j] << "\t";
            cout << endl;
        }
    }

    Matrix operator+(const Matrix &A) const{             //(1a)
        if(m != A.m || n != A.n)
            return Matrix(0, 0);

        Matrix R(m, n);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                R.values[i][j] = values[i][j] + A.values[i][j];
        return R;
    }

    Matrix operator+(float x) const{                    //(1b)
        Matrix R(m, n);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                R.values[i][j] = values[i][j] + x;
        return R;
    }

    Matrix operator*(const Matrix &A) const{            //(2)
        if(n != A.m)
            return Matrix(0, 0);

        Matrix R(m, A.n);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < A.n; j++)
                for(int k = 0; k < n; k++)
                    R.values[i][j] += values[i][k] * A.values[k][j];
        return R;
    }

    Matrix operator-(const Matrix &A) const{            //(3)
        if(m != A.m || n != A.n)
            return Matrix(0, 0);

        Matrix R(m, n);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                R.values[i][j] = values[i][j] - A.values[i][j];
        return R;
    }

    Matrix& operator=(const Matrix &A){                 //(4)
        if(this == &A)
            return *this;

        for(int i = 0; i < m; i++)
            delete[] values[i];
        delete[] values;

        m = A.m;
        n = A.n;

        if(m == 0 || n == 0){
            values = nullptr;
            return *this;
        }
        values = new float*[m];

        for(int i = 0; i < m; i++){
            values[i] = new float[n];
            for(int j = 0; j < n; j++)
                values[i][j] = A.values[i][j];
        }
        return *this;
    }

    Matrix& operator++(){                       //(5)
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                values[i][j]++;
        return *this;
    }

    Matrix& operator--(){                   //(6)
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                values[i][j]--;
        return *this;
    }

    Matrix& operator+=(const Matrix &A){        //(7)matrix deer matrix nemeh
        if(m != A.m || n != A.n)
            return *this;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                values[i][j] += A.values[i][j];
        return *this;
    }

    Matrix& operator+=(float x){       //(7)matrix deer too nemeh
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                values[i][j] += x;
        return *this;
    }

    Matrix& operator-=(const Matrix &A){    //(8)matrixaas matrix hasah
        if(m != A.m || n != A.n)
            return *this;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                values[i][j] -= A.values[i][j];
        return *this;
    }

    Matrix& operator-=(float x){    //(8)matrixaas too hasah
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                values[i][j] -= x;
        return *this;
    }

    Matrix& operator*=(const Matrix &A){       //(9)matrixiig matrixaar urjuuleh
        *this = *this * A;
        return *this;
    }

    Matrix& operator*=(float x){    //(9)matrixiig toogoor urjuuleh
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                values[i][j] *= x;
        return *this;
    }

    Matrix operator~() const{   //(10)matrixiig hurvuuleh
        Matrix R(n, m);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                R.values[j][i] = values[i][j];
        return R;
    }
};

int main(){
    int m, n, p, q;

    cout << "A matrixiin muriin too: ";
    cin >> m;
    cout << "A matrixiin baganiin too: ";
    cin >> n;

    cout << "B matrixiin muriin too: ";
    cin >> p;
    cout << "B matrixiin baganiin too: ";
    cin >> q;

    Matrix A(m, n), B(p, q), R, C;

    cout << "A matrixiin utguudiig oruul:\n";
    A.input();

    cout << "B matrixiin utguudiig oruul:\n";
    B.input();

    cout << "\nA + 12.5 =\n";
    R = A + 12.5f;
    R.print();

    cout << "\nA + B =\n";
    if(m == p && n == q){
        R = A + B;
        R.print();
    } else
        cout << "Hemjee taarahgui!\n";

    cout << "\nA * B =\n";
    if(n == p){
        R = A * B;
        R.print();
    } else
        cout << "Urjuuleh bolomjgui! (A bagana != B muriin too)\n";

    cout << "\nA - B =\n";
    if(m == p && n == q){
        R = A - B;
        R.print();
    } else
        cout << "Hemjee taarahgui!\n";

    cout << "\n++A =\n";
    ++A;
    A.print();

    cout << "\n--A =\n";
    --A;
    A.print();

    cout << "\nA += B =\n";
    A += B;
    A.print();

    cout << "\nA -= B =\n";
    A -= B;
    A.print();

    cout << "\nA *= 2 =\n";
    A *= 2;
    A.print();

    cout << "\nA *= B =\n";
    if(n == p){
        A *= B;
        A.print();
    } else
        cout << "Urjuuleh bolomjgui!\n";

    cout << "\nA matrix hurvuuleh =\n";
    R = ~A;
    R.print();

    cout << "\nC (A-iin utga) = \n";
    C = A;
    C.print();

    return 0;
}
