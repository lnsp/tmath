#include "tmath.hpp"
#include <iostream>

TMath::Matrix::Matrix(std::initializer_list<std::initializer_list<DOUBLE>> list) {
	size_t width = list.size(), index = 0;
	if (width < 1) throw TMath::DIMENSION_ERROR;

	elements = std::vector<std::vector<DOUBLE>>(width);
	for (auto& row : list) elements[index++] = std::vector<DOUBLE>(row.size());

	size_t common = elements[index-1].size();
	for (auto& row : elements) if (row.size() != common) throw TMath::DIMENSION_ERROR;
}
