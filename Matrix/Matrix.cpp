#include "Matrix.h"
#include "../Core/Core.h"

#include <vector>
#include <random>

Matrix::Matrix(int di, int dj, bool isRandomDefault, double defaultValue) 
	: dimensions(di, dj) 
{

#ifdef DEBUG
	if (di <= 0 || dj <= 0) throw std::invalid_argument("Invalid matrix dimensions");
#endif

	size_t totalElements = di * dj;

	if (!isRandomDefault) {
		body.resize(totalElements, defaultValue);
		return;
	}

	body.reserve(totalElements);

	std::mt19937& instantGenerator = getGenerator();
	std::uniform_real_distribution<double> distributionFormat(-0.5, 0.5);

	for (size_t i = 0; i < totalElements; ++i) {
		body.push_back(distributionFormat(instantGenerator));
	}

}

Matrix::Matrix(std::vector<double> vector) 
	: dimensions(vector.size(), 1), body(vector) 
{}

std::pair<int, int> Matrix::getDimensions() const {
	return dimensions;
}

double Matrix::get(int di, int dj) const {
#ifdef DEBUG
	if (di > dimensions.first || dj > dimensions.second) throw std::invalid_argument("Matrix out of range");
#endif
	return body[di * dimensions.second + dj];
}

void Matrix::set(double value, int di, int dj) {
#ifdef DEBUG
	if (di > dimensions.first || dj > dimensions.second) throw std::invalid_argument("Matrix out of range");
#endif
	body[di * dimensions.second + dj] = value;
}

std::vector<double> Matrix::getbody() const {
	return body;
}

void Matrix::todoeach(void (*function)(double&)) {
	for (size_t i = 0; i < body.size(); ++i) {
		function(body[i]);
	}
}

Matrix Matrix::todoeach(void (*function)(double&), bool isNewInstance) {	
	Matrix result = *this;
	for (size_t i = 0; i < body.size(); ++i) {
		function(result.body[i]);
	}
	return result;
}

Matrix operator*(const Matrix& a, const Matrix& b) {

#ifdef DEBUG
	if (a.getDimensions().second != b.getDimensions().first) throw std::invalid_argument("Matrix dimensions mismatch for multiplication");
#endif

	Matrix result(a.getDimensions().first, b.getDimensions().second, false);

	size_t resultDimensionFirst  = result.getDimensions().first
		 , resultDimensionSecond = result.getDimensions().second
		 , aDimensionSecond      = a.getDimensions().second;

	for (size_t ia = 0; ia < resultDimensionFirst; ++ia) {
		for (size_t jb = 0; jb < resultDimensionSecond; ++jb) {
			double buffer = 0.0;
			for (size_t k = 0; k < aDimensionSecond; ++k) {
				buffer += a.get(ia, k) * b.get(k, jb);
			}
			result.set(buffer, ia, jb);
		}
	}

	return result;

}

Matrix& Matrix::operator*=(const Matrix & other) {
	*this = std::move(*this * other);
	return *this;
}

Matrix operator-(const Matrix& a, const Matrix& b) {

#ifdef DEBUG
	if (a.getDimensions() != b.getDimensions()) throw std::invalid_argument("Matrix dimensions mismatch for subtraction");
#endif

	Matrix result(a.getDimensions().first, a.getDimensions().second, false);

	size_t totalElementsNumber = a.getDimensions().first * a.getDimensions().second;

	for (size_t k = 0; k < totalElementsNumber; ++k) {
		result.body[k] = a.body[k] - b.body[k];
	}

	return result;

}

Matrix& Matrix::operator-=(const Matrix& other) {
	*this = std::move(*this - other);
	return *this;
}

Matrix operator+(const Matrix& a, const Matrix& b) {

#ifdef DEBUG
	if (a.getDimensions() != b.getDimensions()) throw std::invalid_argument("Matrix dimensions mismatch for subtraction");
#endif

	Matrix result(a.getDimensions().first, a.getDimensions().second, false);

	size_t totalElementsNumber = a.getDimensions().first * a.getDimensions().second;

	for (size_t k = 0; k < totalElementsNumber; ++k) {
		result.body[k] = a.body[k] + b.body[k];
	}

	return result;

}

Matrix& Matrix::operator+=(const Matrix& other) {
	*this = std::move(*this + other);
	return *this;
}

Matrix operator*(const Matrix& a, const double& b) {
	Matrix result = a;
	for (size_t i = 0; i < result.body.size(); ++i) {
		result.body[i] *= b;
	}
	return result;
}

Matrix& Matrix::operator*=(const double& a) {
	*this = std::move(*this * a);
	return *this;
}

Matrix Matrix::elementWiseMultiply(const Matrix& other) const {

#ifdef DEBUG
	if (dimensions != other.dimensions) throw std::invalid_argument("Element-wise dimensions mismatch");
#endif

	Matrix result = *this;

	for (size_t i = 0; i < body.size(); ++i) {
		result.body[i] *= other.body[i];
	}

	return result;

}

Matrix Matrix::transposed() const {
	
	Matrix result(this->dimensions.second, this->dimensions.first, false);

	for (size_t di = 0; di < dimensions.first; ++di) {
		for (size_t dj = 0; dj < dimensions.second; ++dj) {
			result.set(this->get(di, dj), dj, di);
		}
	}

	return result;

}
