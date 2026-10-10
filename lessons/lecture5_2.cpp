#include <iostream>
#include <cassert>

class Matrix {

private:
    int rows;
    int cols;
    double* data;

public:
    Matrix() {
        rows = 0;
        cols = 0;
        data = nullptr;
    }

    Matrix(int r, int c)
    : rows(r), cols(c) {
        // heap
        data = new double[r*c] {};
    }

    // copy constructor
    Matrix(const Matrix& other) {
        rows = other.rows;
        cols = other.cols;

        data = new double[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            data[i] = other.data[i];
        }

    }

    ~Matrix() {
        delete[] data;
    }
    
    // data[r, c] = value
    // 2D-matrix:
    // 1 2
    // 3 4
    // 5 6
    // # rows = 3, # cols = 2, r = 1, c= 1
    // what we have on heap (1D-array)
    // 1 2, 3 4, 5 6
    // void set(int r, int c, double value) {
    //     data[r * cols + c] = value;
    // }

    // double get(int r, int c) {
    //     return data[r * cols + c];
    // }

    // Matrix style access  A(r,c)
    double& operator()(int r, int c)
    {
        assert(r >= 0 && r < rows);
        assert(c >= 0 && c < cols);
        return data[r * cols + c];
    }

    const double& operator()(int r, int c) const
    {
        assert(r >= 0 && r < rows);
        assert(c >= 0 && c < cols);
        return data[r * cols + c];
    }

    void set(int r, int c, double value)
    {
        (*this)(r, c) = value;
    }

    //get rows and colums 
    int getRows()
    {
        return rows;
    }
    int getcols()
    {
        return cols;
    }
    void printMatrix() {
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++) {
                std::cout << data[r * cols + c] << " ";
            }
            std::cout << std::endl;
        }
    }
   ///Matrix mutli
    Matrix operator*(const Matrix& other){
        assert(cols == other.rows);

        Matrix result(rows, other.cols);
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < other.cols; c++) {
                double sum = 0;
                for (int i = 0; i < cols; i++) {
                    sum += (*this)(r, i) * other(i, c);
                }
                result(r, c) = sum;
            }
        }
        return result;
   }
    //Matrix additions
    Matrix operator+(const Matrix& other ){
        assert(rows== other.rows);
        assert(cols == other.cols);
        
       Matrix result(rows,cols);
        // for(int i=0;i<rows*cols;i++){
        //     result.data[i]=data[i]+other.data[i];

        // }
        for(int r=0; r<rows;r++){
            for(int c=0;c<cols;c++){
              result(r,c )=(*this)(r,c)+other(r,c);
            }
        }

                return result;
         
    }
    
    
    // overload assignment operation
    Matrix& operator=(const Matrix& other) {

        // if self-assignment: A = A
        if (this == &other) {
            return *this;
        }

        delete[] data;

        rows = other.rows;
        cols = other.cols;

        data = new double[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            data[i] = other.data[i];
        }

        return *this;

    }

};

int main() {

    // Matrix A;
    // A.printMatrix();

    // ------------
    
    Matrix A(2, 2);
    A.set(1, 1, 10);
    A.printMatrix();
    std::cout << std::endl;

    // Matrix B = A;   
    // B.set(1, 1, 100);
    // B.printMatrix();
    // std::cout << std::endl;

    // A.printMatrix();

    // ------------
    
    Matrix C;
    C = A;
    C.set(1, 1, 100);
    C.printMatrix();
    std::cout << std::endl;

    A.printMatrix();

    return 0;
}