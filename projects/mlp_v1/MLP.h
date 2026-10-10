#include "Matrix.h"


class Linear {
private:
   Matrix weights;
   Matrix bias;

public:
   Linear(int inputSize, int outputSize);
   Matrix forward(Matrix& input);
   void getWeights();
};

class ReLU {
public:
   Matrix forward(Matrix& input);
};

class MLP {
private:
   Linear fc1;
   ReLU relu;
   Linear fc2;

public:
   MLP();
   Matrix forward(Matrix& input);
   void getWeights();
};
