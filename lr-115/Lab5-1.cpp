#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
using Matrix = vector<vector<T>>;

enum class IndexMode { Sum, SumOfSquares };
enum class Trig { Sin, Cos };

Matrix<int> readMatrix(size_t rows, size_t cols) {
    Matrix<int> m(rows, vector<int>(cols));
    for (size_t i = 0; i < rows; ++i) {
        cout << "Enter row " << i + 1 << " (" << cols << " numbers): ";
        for (int& x : m[i]) cin >> x;
    }
    return m;
}

template <typename T>
Matrix<T> add(const Matrix<T>& a, const Matrix<T>& b) {
    Matrix<T> c = a;
    for (size_t i = 0; i < c.size(); ++i)
        for (size_t j = 0; j < c[i].size(); ++j)
            c[i][j] += b[i][j];
    return c;
}

Matrix<int> scaleByIndices(const Matrix<int>& m, IndexMode mode) {
    Matrix<int> c = m;
    for (size_t i = 0; i < c.size(); ++i) {
        for (size_t j = 0; j < c[i].size(); ++j) {
            int factor = (mode == IndexMode::Sum)
                ? int(i + j)
                : int(i * i + j * j);
            c[i][j] *= factor;
        }
    }
    return c;
}

Matrix<double> applyTrig(const Matrix<int>& m, Trig f) {
    Matrix<double> c(m.size(), vector<double>(m[0].size()));
    for (size_t i = 0; i < m.size(); ++i)
        for (size_t j = 0; j < m[i].size(); ++j)
            c[i][j] = (f == Trig::Sin) ? sin(m[i][j]) : cos(m[i][j]);
    return c;
}

template <typename T>
void print(const Matrix<T>& m) {
    cout << "\n";
    for (const auto& row : m) {
        cout << "\t";
        for (const T& x : row) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    size_t n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    cout << "\nEnter matrix A:\n";
    Matrix<int> A = readMatrix(n, m);
    cout << "\nEnter matrix B:\n";
    Matrix<int> B = readMatrix(n, m);

    cout << "\nA + B:";
    print(add(A, B));

    cout << "\nA*(i+j) + B*(i^2+j^2):";
    print(add(scaleByIndices(A, IndexMode::Sum),
        scaleByIndices(B, IndexMode::SumOfSquares)));

    cout << "\nsin(A) + cos(B):" << fixed << setprecision(2);
    print(add(applyTrig(A, Trig::Sin), applyTrig(B, Trig::Cos)));

    return 0;
}
