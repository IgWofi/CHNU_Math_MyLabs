#include <iostream>
#include <vector>

using namespace std;

using Matrix = vector<vector<int>>;

struct Point {
	int x;
	int y;
};

Matrix readMatrix(size_t rows, size_t cols) {
	Matrix m(rows, vector<int>(cols));
	for (size_t i = 0; i < rows; ++i) {
		cout << "Enter row " << i + 1 << " (" << cols << " numbers): ";
		for (int& x : m[i]) cin >> x;
	}
	return m;
}

Point findMinAndMaxInMatrix(const Matrix& matrix, int m, int n) {
	int min = matrix[0][0], max = matrix[0][0];
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (min > matrix[i][j]) min = matrix[i][j];
			else if (max < matrix[i][j]) max = matrix[i][j];
		}
	}

	return { min, max };
}

int main() {
	size_t m = 10, n; cout << "Enter columns: "; cin >> n;

	cout << "\nEnter matrix A:\n";
	Matrix A = readMatrix(m, n);

	Point MinAndMax = findMinAndMaxInMatrix(A, m, n);

	cout << "\nArithmetic mean of min and max: " << (MinAndMax.x + MinAndMax.y) / 2.0;
	
	return 0;
}