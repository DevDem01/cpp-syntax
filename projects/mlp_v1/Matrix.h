class Matrix {
private:
   int rows;
   int cols;
   double* data;

public:
   Matrix();
   Matrix(int r, int c);
   Matrix(const Matrix& other);
   ~Matrix();

   Matrix& operator=(const Matrix& other);
   double& operator() (int r, int c);
   const double& operator() (int r, int c) const;

   void printMatrix();

   int getRows();
   int getCols();

   Matrix add(const Matrix& other) const;
   Matrix multiply(const Matrix& other) const;

};


