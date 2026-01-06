#pragma once

#include <utility>
#include <vector>

class Matrix {
public:
	
	void init(int di, int dj, bool isRandomDefault = true, double defaultValue = 0.0);

	Matrix(int di, int dj, bool isRandomDefault = true, double defaultValue = 0.0);
	Matrix(std::vector<double> vector);
	Matrix() = default;

	double get(int di, int dj) const;
	std::vector<double> getbody() const;
	std::pair<int, int> getDimensions() const;

	void set(double value, int di, int dj);
	void todoeach(void (*function)(double&));
	Matrix todoeach(void (*function)(double&), bool isNewInstance);

	Matrix transposed() const;

	Matrix& operator*=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator+=(const Matrix& other);
	Matrix& operator*=(const double& a);

	friend Matrix operator-(const Matrix& a, const Matrix& b);
	friend Matrix operator*(const Matrix& a, const Matrix& b);
	friend Matrix operator*(const Matrix& a, const double& b);
	friend Matrix operator+(const Matrix& a, const Matrix& b);

	Matrix elementWiseMultiply(const Matrix& other) const;

private:
	std::pair<int, int> dimensions;
	std::vector<double> body;
};

Matrix operator*(const Matrix& a, const Matrix& b);
Matrix operator*(const Matrix& a, const double& b);
Matrix operator-(const Matrix& a, const Matrix& b);
Matrix operator+(const Matrix& a, const Matrix& b);
