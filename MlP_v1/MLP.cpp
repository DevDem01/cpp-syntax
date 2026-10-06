#include "MLP.h"

#include<cstdlib>
#include<iostream>

Linear::Linear(int inputSize, int outputSize)
: weights(outputSize, inputSize), bias(outputSize, 1) {
    for (int r = 0; r < outputSize; r++) {
        for (int c = 0; c < inputSize; c++) {
            weights(r, c) = (double) std::rand() / RAND_MAX;
        }
        bias(r, 0) = (double) std::rand() / RAND_MAX;
    }
}

Matrix Linear::forward(Matrix& input) {
    // output = W * x + b
    Matrix output = weights.multiply(input);
    return output.add(bias);
}

void Linear::getWeights() {
    std::cout << "weights:" << std::endl;
    weights.printMatrix();
    std::cout << "bias:" << std::endl;
    bias.printMatrix();
}

Matrix ReLU::forward(Matrix& input) {
    // output = max (0, input)
    Matrix output = input;
    for (int r = 0; r < output.getRows(); r++) {
        for (int c = 0; c < output.getCols(); c++) {
            output(r, c) = (output(r, c) < 0) ? 0 : output(r, c);
        }
    }
    return output;
}


MLP::MLP()
: fc1(4, 3), fc2(3, 2) {

}


Matrix MLP::forward(Matrix& input) {
    Matrix hidden = fc1.forward(input);
    Matrix activation = relu.forward(hidden);
    Matrix output = fc2.forward(activation);
    return output;
}


void MLP::getWeights() {
    std::cout << "fc1:" << std::endl;
    fc1.getWeights();
    std::cout << "fc2:" << std::endl;
    fc2.getWeights();
}