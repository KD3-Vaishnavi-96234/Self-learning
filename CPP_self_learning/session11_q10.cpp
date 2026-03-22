#include <iostream>
using namespace std;
class Matrix
{
private:
    int rows;
    int cols;
    int **data;

public:
    Matrix(int r, int c) : rows(r), cols(c)
    {
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = 0;
            }
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }
    void setElement(int r, int c, int value)
    {
        if (r >= 0 && r < rows && c >= 0 && c < cols)
        {
            data[r][c] = value;
        }
    }
    Matrix operator+(const Matrix &other)
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    Matrix operator-(const Matrix &other)
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
    Matrix operator*(const Matrix &other)
    {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.cols; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Matrix A(2, 2);
    Matrix B(2, 2);
    A.setElement(0, 0, 1);
    A.setElement(0, 1, 2);
    A.setElement(1, 0, 3);
    A.setElement(1, 1, 4);
    B.setElement(0, 0, 5);
    B.setElement(0, 1, 6);
    B.setElement(1, 0, 7);
    B.setElement(1, 1, 8);
    cout << "Matrix A:" << endl;
    A.display();
    cout << "Matrix B:" << endl;
    B.display();
    Matrix C = A + B;
    cout << "A + B:" << endl;
    C.display();
    Matrix D = A - B;
    cout << "A - B:" << endl;
    D.display();
    Matrix E = A * B;
    cout << "A * B:" << endl;
    E.display();
    return 0;
}
