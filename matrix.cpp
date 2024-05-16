#include "matrix.h"

namespace matrix {
    Matrix matrix::matrix(int n, int m, int arr[MAX_ROWS][MAX_COLS]) {
        if (n > MAX_ROWS || m > MAX_COLS) {
            throw std::invalid_argument("matrix size exceeds permissible limits");
        }
        Matrix nw;
        nw.rows = n;
        nw.cols = m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                nw.matrix[i][j] = arr[i][j];
            }
        }
        return nw;
    }

    Matrix matrix::dot(const Matrix* m1, const Matrix* m2) {
        if (m1->cols != m2->rows) {
            throw std::range_error("The number of columns in the first matrix does" 
                                "not equal the number of rows in the second matrix.");
        }

        Matrix dt {m1->rows, m2->cols};
        for (int r = 0; r < m1->rows; r++) {
            for (int c = 0; c < m2->cols; c++) {
                int el = 0;
                for (int i = 0; i < m1->cols; i++) {
                    el += m1->matrix[r][i] * m2->matrix[i][c];
                }
                dt.matrix[r][c] = el;
            }
        }

        return dt;
    }

    void matrix::print(const Matrix* m) {
        for (int r = 0; r < m->rows; r++) {
            for (int c = 0; c < m->cols; c++) {
                std::cout << m->matrix[r][c] << " ";
            }
            std::cout << std::endl;
        }
    }
}