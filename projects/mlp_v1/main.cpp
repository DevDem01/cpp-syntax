#include "MLP.h"

#include <iostream>

int main() {

    Matrix input(4, 1);
    input(0, 0) = 1;
    input(1, 0) = 2;
    input(2, 0) = 3;
    input(3, 0) = 4;

    std::cout << "input:" << std::endl;
    input.printMatrix();

    MLP model;

    Matrix output = model.forward(input);

    std::cout << "output:" << std::endl;
    output.printMatrix();

    std::cout << "model weights:" << std::endl;
    model.getWeights();

    return 0;
}