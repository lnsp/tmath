#include "tmath.hpp"
#include <iostream>

TMath::Matrix::Matrix(std::initializer_list<std::initializer_list<DOUBLE>> list) {
	size_t height = list.size(), index = 0;
	if (height < 1) throw TMath::EMPTY_MATRIX_ERROR;

	elements = std::vector<std::vector<DOUBLE>>(height);
	for (auto& row : list) elements[index++] = std::vector<DOUBLE>(row.size());

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
