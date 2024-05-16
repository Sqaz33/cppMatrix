// #include "matrix.h"
// using namespace matrix;

#include <stdexcept>
#include <iostream>
#include "matrix.h"

using namespace matrix;

int main(int argc, char* argv[]) {
    int arr1[matrix::MAX_ROWS][matrix::MAX_COLS] = {
        {2, -3, 1},
        {5, 4, -2}
    };
    Matrix m1 = matrix::matrix(2, 3, arr1);

    int arr2[matrix::MAX_ROWS][matrix::MAX_COLS] = {
        {-7, 5},
        {2, -1},
        {4, 3}
    };
    Matrix m2 = matrix::matrix(3, 2, arr2);

    Matrix dt = matrix::dot(&m1, &m2);
    matrix::print(&dt);

    return 0;
}