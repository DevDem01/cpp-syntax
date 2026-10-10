#include "Matrix.h"

#include <cassert>
#include <iostream>


Matrix::Matrix() {
   rows = 0;
   cols = 0;
   data = nullptr;
}

Matrix::Matrix(int r, int c)
   : rows(r), cols(c) {
   data = new double[rows * cols] {};
}

// Copy constructor: deep copy
Matrix::Matrix(const Matrix& other) {
   rows = other.rows;
   cols = other.cols;

   if (rows * cols == 0) {
       data = nullptr;
   }
   else {
       data = new double[rows * cols];
       for (int i = 0; i < rows * cols; i++) {
           data[i] = other.data[i];
       }
   }
}

Matrix::~Matrix() {
   delete[] data;
}

// Copy assignment operator: deep copy
Matrix& Matrix::operator=(const Matrix& other) {
   if (this == &other) {
       return *this;
   }

   delete[] data;

   rows = other.rows;
   cols = other.cols;

   if (rows * cols == 0) {
       data = nullptr;
   }
   else {
       data = new double[rows * cols];
       for (int i = 0; i < rows * cols; i++) {
           data[i] = other.data[i];
       }
   }

   return *this;
}

void Matrix::printMatrix() {
   for (int r = 0; r < rows; r++) {
       for (int c = 0; c < cols; c++) {
           std::cout << data[r * cols + c] << " ";
       }
       std::cout << std::endl;
   }
}

// Matrix-style access A(r, c)
double& Matrix::operator() (int r, int c) {
   assert(r >=0 && r < rows);
   assert(c >=0 && c < cols);

   return data[r * cols + c];
}

// read-only A(r, c)
const double& Matrix::operator() (int r, int c) const {
   assert(r >=0 && r < rows);
   assert(c >=0 && c < cols);

   return data[r * cols + c];
}

int Matrix::getRows() {
   return rows;
}

int Matrix::getCols() {
   return cols;
}

// Matrix addition
Matrix Matrix::add(const Matrix& other) const {
   assert(rows == other.rows);
   assert(cols == other.cols);

   Matrix result(rows, cols);

   // for (int i = 0; i < rows * cols; i++) {
   //     result.data[i] = data[i] + other.data[i];
   // }

   for (int r = 0; r < rows; r++){
       for (int c = 0; c < cols; c++){
           result(r, c) = (*this)(r, c) + other(r, c);
       }
   }

   return result;
}

// matrix multiplication
Matrix Matrix::multiply(const Matrix& other) const {
   assert(cols == other.rows);

   Matrix result(rows, other.cols);

   for (int r = 0; r < rows; r++){
       for (int c = 0; c < other.cols; c++){
          
           double sum = 0;
          
           for (int k = 0; k < cols; k++){
               sum += (*this)(r, k) * other(k, c);
           }

           result(r, c) = sum;
       }
   }

   return result;
}
