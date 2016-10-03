#include "tmath.hpp"
#include <sstream>

TMath::Matrix::Matrix(std::initializer_list<std::initializer_list<DOUBLE>> list) {
	size_t height = list.size(), index = 0;
	if (height < 1) throw TMath::EMPTY_MATRIX_ERROR;

	elements = std::vector<std::vector<DOUBLE>>(height);
	for (auto& row : list) elements[index++] = std::vector<DOUBLE>(row);

	size_t common = elements[index-1].size();
	for (auto& row : elements) if (row.size() != common) throw TMath::DIMENSION_ERROR;
}

TMath::Matrix::Matrix(const int& width, const int& height) {
	if (width < 1 || height < 1) throw TMath::EMPTY_MATRIX_ERROR;

	elements = std::vector<std::vector<DOUBLE>>(height);
	for (size_t index = 0; index < width; index++) {
		elements[index] = std::vector<DOUBLE>(width);
	}
}

TMath::Matrix::Matrix(const Matrix& m) {
	size_t height = m.elements.size();
	elements = std::vector<std::vector<DOUBLE>>(m.elements.size());
	for (size_t index = 0; index < height; index++) elements[index] = std::vector<DOUBLE>(m.elements[index]);
}

std::pair<size_t, size_t> TMath::Matrix::validate(const Matrix& m) const {
	size_t w = width(), h = height();
	if (m.width() != w || m.height() != h) throw TMath::DIMENSION_ERROR;
	return std::pair<size_t, size_t>(w, h);
}

std::vector<TMath::DOUBLE>& TMath::Matrix::operator[](const int& i) {
	return elements[i];
}

bool TMath::Matrix::equal(const Matrix& m, const DOUBLE& eps) const {
	std::pair<size_t, size_t> dimensions = validate(m);

	for (size_t i = 0; i < dimensions.second; i++) for (size_t j = 0; j < dimensions.first; j++) 
		if (!TMath::equal(elements[i][j], m.elements[i][j], eps)) return false;

	return true;
}

bool TMath::Matrix::operator==(const Matrix& m) const {
	return equal(m, EQUAL_EPSILON);
}

bool TMath::Matrix::operator!=(const Matrix& m) const {
	return !equal(m, EQUAL_EPSILON);
}
	
size_t TMath::Matrix::width() const {
	return elements[0].size();
}

size_t TMath::Matrix::height() const {
	return elements.size();
}

std::string TMath::Matrix::to_string() const {
	size_t w = width(), h = height();
	std::stringstream stream;
	stream << "{[";
	for (size_t i = 0; i < h; i++) {
		for (size_t j = 0; j < w-1; j++) {
			stream << elements[i][j] << ", ";
		}
		stream << elements[i][w-1];
		if (i < h-1) stream << "], [";
	}
	stream << "]}";
	return stream.str();
}
