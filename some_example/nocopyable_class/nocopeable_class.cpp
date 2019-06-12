#include "general.h"

template <typename T>
class Matrix
{
public:
    Matrix(){}

private:
    Matrix(const Matrix<T>&);
    Matrix<T>& operator = (const Matrix<T>&);
};

class Matrix_c11
{
public:
    Matrix_c11(){}
    Matrix_c11(const Matrix_c11&) = delete;
    Matrix_c11&operator = (const Matrix_c11&) = delete;
};

int main()
{
    Matrix<int> matrix;
    Matrix_c11 matrix_c11;
}