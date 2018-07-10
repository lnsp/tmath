#include "tmath.hpp"
#include <sstream>

// Initialize a new 2d matrix with these values.
TMath::Matrix::Matrix(std::initializer_list<std::initializer_list<DOUBLE>> list) {
	int height = list.size(), index = 0;
	if (height < 1) throw TMath::EMPTY_MATRIX_ERROR;

	elements = std::vector<Vector>(height);
	for (auto& row : list) elements[index++] = Vector(row);

	int common = elements[index-1].dim();
	for (auto& row : elements) if (row.dim() != common) throw TMath::DIMENSION_ERROR;
}

// Initialize a new matrix with a specific rows and cols.
TMath::Matrix::Matrix(const int& rows, const int& cols) {
	if (rows < 1 || cols < 1) throw TMath::EMPTY_MATRIX_ERROR;

	elements = std::vector<Vector>(rows);
	for (int index = 0; index < rows; index++) {
		elements[index] = Vector(cols);
	}
}

// Initialize a new matrix as a copy of the matrix m.
TMath::Matrix::Matrix(const Matrix& m) {
	int height = m.elements.size();
	elements = std::vector<Vector>(m.elements.size());
	for (int index = 0; index < height; index++) elements[index] = Vector(m.elements[index]);
}

// Check if the two matrices have the same dimensions.
std::pair<int, int> TMath::Matrix::validate(const Matrix& m) const {
	int w = colCount(), h = rowCount();
	if (m.colCount() != w || m.rowCount() != h) throw TMath::DIMENSION_ERROR;
	return std::pair<int, int>(w, h);
}

// Access a matrix row.
TMath::Vector& TMath::Matrix::operator[](const int& i) {
	if (i >= rowCount() || i < 0) throw OUT_OF_BOUNDS;
	return elements[i];
}

// Access a matrix row as a constant.
TMath::Vector TMath::Matrix::row(const int& i) const {
	if (i >= rowCount() || i < 0) throw OUT_OF_BOUNDS;
	return elements[i];
}

// Access a matrix col as a constant.
TMath::Vector TMath::Matrix::col(const int& j) const {
	if (j >= colCount() || j < 0) throw OUT_OF_BOUNDS;
	Vector column(rowCount());
	for (int i = 0; i < rowCount(); i++) {
		column[i] = at(i, j);
	}
	return column;
}

// Access a matrix item as a constant.
TMath::DOUBLE TMath::Matrix::at(const int& i, const int& j) const {
	if (i >= rowCount() || i < 0 || j < 0 || j >= colCount()) throw OUT_OF_BOUNDS;
	return elements[i].at(j);
}

// Test if the matrices are equal or nearly equal as specificed by the epsilon.
bool TMath::Matrix::equal(const Matrix& m, const DOUBLE& eps) const {
	std::pair<int, int> dimensions = validate(m);

	for (int i = 0; i < dimensions.second; i++) for (int j = 0; j < dimensions.first; j++) 
		if (!TMath::equal(elements[i].at(j), m.elements[i].at(j), eps)) return false;

	return true;
}

// Test if the matrices are equal.
bool TMath::Matrix::operator==(const Matrix& m) const {
	return equal(m, EQUAL_EPSILON);
}

// Test if the matrices are unequal.
bool TMath::Matrix::operator!=(const Matrix& m) const {
	return !equal(m, EQUAL_EPSILON);
}

// Get the matrix col count.
int TMath::Matrix::colCount() const {
	return elements[0].dim();
}

// Get the matrix row count.
int TMath::Matrix::rowCount() const {
	return elements.size();
}

// Add two matrices.
TMath::Matrix TMath::Matrix::operator+(const Matrix& a) const {
	int w = colCount(), h = rowCount();
	if (a.colCount() != w || a.rowCount() != h) throw TMath::DIMENSION_ERROR;

	Matrix result(a);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			result[i][j] += elements[i].at(j);
		}
	}

	return result;
}

// Subtract two matrices.
TMath::Matrix TMath::Matrix::operator-(const Matrix& a) const {
	int w = colCount(), h = rowCount();
	if (a.colCount() != w || a.rowCount() != h) throw TMath::DIMENSION_ERROR;

	Matrix result(*this);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			result[i][j] -= a.elements[i].at(j);
		}
	}

	return result;
}

// Invert matrice values.
TMath::Matrix TMath::Matrix::operator-() const {
	return *this * -1.0;
}

// Generate a string representation of the matrix.
std::string TMath::Matrix::to_string() const {
	int w = colCount(), h = rowCount();
	std::stringstream stream;
	stream << "{[";
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w-1; j++) {
			stream << elements[i].at(j) << ", ";
		}
		stream << elements[i].at(w-1);
		if (i < h-1) stream << "], [";
	}
	stream << "]}";
	return stream.str();
}

TMath::Matrix TMath::Matrix::operator*(const DOUBLE& a) const {
	Matrix result(*this);
	for (int i = 0; i < rowCount(); i++) {
		result[i] = result[i] * a;
	}
	return result;
}

// Multiply a matrix with a vector.
TMath::Vector TMath::Matrix::operator*(const Vector& a) const {
	int w = colCount(), wv = a.dim(), h = rowCount();
	if (w != wv) throw TMath::DIMENSION_ERROR;

	Vector result(h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			result[i] += elements[i].at(j) * a.at(j);
		}
	}

	return result;
}

// Multiply a matrix with a matrix;
TMath::Matrix TMath::Matrix::operator*(const Matrix& a) const {
	if (a.rowCount() != colCount()) throw TMath::DIMENSION_ERROR;

	// pre compute cols
	std::vector<Vector> cols;
	for (int i = 0; i < a.colCount(); i++) {
		cols.push_back(a.col(i));
	}

	// pre compute rows
	std::vector<Vector> rows;
	for (int i = 0; i < rowCount(); i++) {
		rows.push_back(row(i));
	}

	Matrix result(rowCount(), a.colCount());
	for (int i = 0; i < rowCount(); i++) {
		for (int j = 0; j < a.colCount(); j++) {
			result[i][j] = rows[i].dot(cols[j]);
		}
	}

	return result;
}

TMath::Matrix TMath::Matrix::identity(const int& d) {
	TMath::Matrix id(d, d);
	for (int i = 0; i < d; i++) id[i][i] = 1.;
	return id;
}