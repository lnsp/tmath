#include "tmath.hpp"
#include <sstream>

// checkDimensions check if the dimensions of the vectors are equal.
int TMath::Vector::checkDimensions(const Vector &a) const {
	int mdim = dim();
	if (mdim != a.dim()) throw TMath::DIMENSION_ERROR;
	return mdim;
}

// [n] operator accesses the n-th element of the vector by reference.
TMath::DOUBLE& TMath::Vector::operator[](const int &i) {
	if (i >= dim()) throw BAD_OPERATION;
	return elements.at(i);
};

// at operation accesses the n-th element of the vector by value.
TMath::DOUBLE TMath::Vector::at(const int &i) const {
	if (i >= dim() || i < 0) throw BAD_OPERATION;
	return elements.at(i);
}

// + operator sums up two vectors.
// result = this + a
TMath::Vector TMath::Vector::operator+(const Vector &a) const {
	int d = checkDimensions(a);
	Vector b(d);
	for (unsigned int i = 0; i < d; i++) {
		b[i] = elements.at(i) + a.elements.at(i);
	}
	return b;
};

// - operator calculates the difference vector of the two vectors.
// result = this - a
TMath::Vector TMath::Vector::operator-(const Vector &a) const {
	int d = checkDimensions(a);
	Vector b(d);
	for (unsigned int i = 0; i < d; i++) {
		b[i] = elements.at(i) - a.elements.at(i);
	}
	return b;
};

// - operator calculates the inversion of the vector.
TMath::Vector TMath::Vector::operator-() const {
	int d = dim();
	Vector b(d);
	for (unsigned int i = 0; i < d; i++) {
		b[i] = -elements.at(i);
	}
	return b;
}

// * operator scales the vector by the scalar.
TMath::Vector TMath::Vector::operator*(const DOUBLE &scalar) const {
	int d = dim();
	Vector b(d);
	for (unsigned int i = 0; i < d; i++) {
		b[i] = elements.at(i) * scalar;
	}
	return b;
};

// / operator scales the vector by the inverse value of the scalar.
TMath::Vector TMath::Vector::operator/(const DOUBLE &scalar) const {
	int d = dim();
	Vector b(d);
	for (unsigned int i = 0; i < d; i++) {
		b[i] = elements.at(i) / scalar;
	}
	return b;
};

// equal checks for equality of both vectors.
bool TMath::Vector::equal(const Vector &a, const DOUBLE &eps) const {
	int d = checkDimensions(a);
	for (unsigned int i = 0; i < d; i++) {
		if (!TMath::equal(elements.at(i), a.elements.at(i), eps)) return false;
	}
	return true;
};

// == operator checks for equality with a constant accuracy of EQUAL_EPSILON.
bool TMath::Vector::operator==(const Vector &a) const {
	int d = checkDimensions(a);
	return this->equal(a, EQUAL_EPSILON);
};

// != operator checks for inequality.
bool TMath::Vector::operator!=(const Vector &a) const {
	int d = checkDimensions(a);
	return !this->equal(a, EQUAL_EPSILON);
};

// dot operator calculates the dot product of the two vectors.
TMath::DOUBLE TMath::Vector::dot(const Vector &a) const {
	int d = checkDimensions(a);
	Vector b(d);
	DOUBLE sum = 0;
	for (unsigned int i = 0; i < d; i++) sum += elements.at(i) * a.elements.at(i);
	return sum;
};

// cross operator calculates the cross product of the two vectors.
TMath::Vector TMath::Vector::cross(const Vector &a) const {
	int d = checkDimensions(a);
	if (d != 3) throw BAD_OPERATION;
	Vector b(3);
	for (unsigned int i = 0; i < 3; i++) {
		unsigned int p = (i+1) % 3, q = (i+2) % 3;
		b[i] = elements.at(i) * a.elements.at(q) - elements.at(q) * a.elements.at(p);
	}
	return b;
};

// sum operator calculates the element sum of the vector.
TMath::DOUBLE TMath::Vector::sum() const {
	int d = dim();
	DOUBLE sum = 0;
	for (unsigned int i = 0; i < d; i++) sum += elements[i];
	return sum;
};

// norm operator calculates a normalized vector.
TMath::Vector TMath::Vector::norm() const {
	int d = dim();
	if (d == 0) throw BAD_OPERATION;
	DOUBLE l = length();
	if (l == 0) throw ZERO_LENGTH;
	return *this / l;
}

// length operator calculates the length of the vector.
TMath::DOUBLE TMath::Vector::length() const {
	int d = dim();
	if (d == 0) throw BAD_OPERATION;
	DOUBLE sum = 0;
	for (unsigned int i = 0; i < d; i++) sum += elements[i] * elements[i];
	return TMath::sqrt(sum);
}

// dim returns the vector tuple size.
int TMath::Vector::dim() const {
	return elements.size();
}

// to_string returns a string representation of the vector.
std::string TMath::Vector::to_string() const {
	std::stringstream stream;
	stream << "{";
	int d = dim();
	for (unsigned int i = 0; i < d - 1; i++) stream << elements[i] << ", ";
	if (d > 0) stream << elements[d-1];
	stream << "}";
	return stream.str();
}