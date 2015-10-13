#include <iostream>
#include <fstream>

#define MAXROWS 10
#define MAXCOLS 10
#define MAXSIZE 20

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
};

int main()
{
    int i, j, k, rows, cols, size;
    float data[MAXROWS][MAXCOLS];
    Matrix Mat[MAXSIZE];
    Matrix Result1, Result2;

    ifstream file("MATRICES.TXT");
    if (!file.is_open()) {
        cout << "File cannot be opened." << endl;
        return 0;
    } 

    for (k = 0; !file.eof(); k++) {
        file >> rows;
        file >> cols;

        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                file >> data[i][j];
            }
        }

        Mat[k] = Matrix(data, rows, cols);
    }

    size = k;
    file.close();

    cout << "Result1 Matrix" << endl;
    Result1 = Mat[0] + Mat[2];
    Result1.print();

    cout << "Result2 Matrix" << endl;
    Result2 = Mat[4] + 70;
    Result2.print();

    ++Mat[2];
    Mat[3] += Mat[1];

    for (k = 0; k < size; k++) {
        cout << "Matrix #" << k << endl;
        Mat[k].print();
    }

    return 0;
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

    int i, j;
    float sum;
    for (i = 0; i < rows; i++) {
        for (j = 0, sum = 0; j < cols; j++) {
            if (data[i][j] < 0)
                return false;
            sum += data[i][j];
        }

        if (sum != 1.0)
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

    cout << "==============================" << endl;
}

Matrix Matrix::operator+(const Matrix& b)
{
    if (this->rows != b.rows || this->cols != b.cols) {
        cout << "Operation cannot be performed because of dimension inequality." << endl;
        return *this;
    }

    float data_new[MAXROWS][MAXCOLS];
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            data_new[i][j] = data[i][j] + b.data[i][j];
        }
    }

    return Matrix(data_new, rows, cols);    
}

Matrix Matrix::operator+(float scalar_value)
{
    float data_new[MAXROWS][MAXCOLS];
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            data_new[i][j] = data[i][j] + scalar_value;
        }
    }

    return Matrix(data_new, rows, cols);
}

void Matrix::operator++(void)
{
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            this->data[i][j] += 1;
}

void Matrix::operator+=(const Matrix& b)
{
    if (this->rows != rows || this->cols != cols)
        cout << "Operation cannot be performed because of dimension inequality." << endl;

    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            this->data[i][j] += b.data[i][j];
}