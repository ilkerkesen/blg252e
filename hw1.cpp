#include <iostream>

#define MAXROWS 10
#define MAXCOLS 10

using namespace std;

class Matrix {
    public:
        Matrix();
        Matrix(float data[MAXROWS][MAXCOLS], int rows, int cols);
        void print(void);
        Matrix operator+(const Matrix &);
        Matrix operator+(float scalar_value);
        void operator++(void);
        void operator+=(const Matrix &);
    private:
        int rows;
        int cols;
        float data[MAXROWS][MAXCOLS];
        bool test_stochastic(void);
}

Matrix::Matrix()
{
    int i, j;
    for (i = 0; i < MAXROWS; i++) {
        for (j = 0; j < MAXCOLS; j++) {
            data[i][j] = 0;
        }
    }   
}

Matrix::Matrix(float data[MAXROWS][MAXCOLS], int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;

    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            this->data[i][j] = data[i][j];
        }
    }
}

bool Matrix::test_stochastic(void)
{
    if (rows != cols)
        return false;

    int sum, i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0, sum = 0; j < cols; j++) {
            if (data[i][j] < 0)
                return false;
            sum += data[i][j];
        }

        if (sum != 1)
            return false;
    }

    return true;
}

void Matrix::print(void)
{
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }

    if (test_stochastic())
        cout << "THIS MATRIX IS STOCHASTIC" << endl;

    cout << “===============================” << endl;
}
