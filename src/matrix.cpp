#include "tmath.hpp"
#include <sstream>

// Initialize a new 2d matrix with these values.
TMath::Matrix::Matrix(std::initializer_list<std::initializer_list<DOUBLE>> list) {
	int height = list.size(), index = 0;
	if (height < 1) throw TMath::EMPTY_MATRIX_ERROR;

	elements = std::vector<std::vector<DOUBLE>>(height);
	for (auto& row : list) elements[index++] = std::vector<DOUBLE>(row);

	int common = elements[index-1].size();
	for (auto& row : elements) if (row.size() != common) throw TMath::DIMENSION_ERROR;
}

// Initialize a new matrix with a specific width and height.
TMath::Matrix::Matrix(const int& width, const int& height) {
	if (width < 1 || height < 1) throw TMath::EMPTY_MATRIX_ERROR;

	elements = std::vector<std::vector<DOUBLE>>(height);
	for (int index = 0; index < width; index++) {
		elements[index] = std::vector<DOUBLE>(width);
	}
}

// Initialize a new matrix as a copy of the matrix m.
TMath::Matrix::Matrix(const Matrix& m) {
	int height = m.elements.size();
	elements = std::vector<std::vector<DOUBLE>>(m.elements.size());
	for (int index = 0; index < height; index++) elements[index] = std::vector<DOUBLE>(m.elements[index]);
}

// Check if the two matrices have the same dimensions.
std::pair<int, int> TMath::Matrix::validate(const Matrix& m) const {
	int w = width(), h = height();
	if (m.width() != w || m.height() != h) throw TMath::DIMENSION_ERROR;
	return std::pair<int, int>(w, h);
}

// Access a matrix row.
std::vector<TMath::DOUBLE>& TMath::Matrix::operator[](const int& i) {
	return elements[i];
}

// Test if the matrices are equal or nearly equal as specificed by the epsilon.
bool TMath::Matrix::equal(const Matrix& m, const DOUBLE& eps) const {
	std::pair<int, int> dimensions = validate(m);

	for (int i = 0; i < dimensions.second; i++) for (int j = 0; j < dimensions.first; j++) 
		if (!TMath::equal(elements[i][j], m.elements[i][j], eps)) return false;

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
int TMath::Matrix::width() const {
	return elements[0].size();
}

// Get the matrix row count.
int TMath::Matrix::height() const {
	return elements.size();
}

// Add two matrices.
TMath::Matrix TMath::Matrix::operator+(const Matrix& a) const {
	int w = width(), h = height();
	if (a.width() != w || a.height() != h) throw TMath::DIMENSION_ERROR;

	Matrix result(a);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			result[i][j] += elements[i][j];
		}
	}

	return result;
}

// Subtract two matrices.
TMath::Matrix TMath::Matrix::operator-(const Matrix& a) const {
	int w = width(), h = height();
	if (a.width() != w || a.height() != h) throw TMath::DIMENSION_ERROR;

	Matrix result(*this);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			result[i][j] -= a.elements[i][j];
		}
	}

	return result;
}

// Generate a string representation of the matrix.
std::string TMath::Matrix::to_string() const {
	int w = width(), h = height();
	std::stringstream stream;
	stream << "{[";
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w-1; j++) {
			stream << elements[i][j] << ", ";
		}
		stream << elements[i][w-1];
		if (i < h-1) stream << "], [";
	}
	stream << "]}";
	return stream.str();
}
