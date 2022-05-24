#include "otterMatrix.h"
#include <iostream>

namespace otterEngine {
	//constructors
	//
	//3x3 matrix--column major
	//0	3 6
	//1 4 7
	//2 5 8
	otterMatrix::otterMatrix() {
		for (int i = 0; i < 9; i++) {
			matrixElement[i] = 0.0f;
		}
		matrixElement[0] = matrixElement[4] = matrixElement[8] = 1.0f;
	}
	otterMatrix::otterMatrix(float _0, float _3, float _6, float _1, float _4, float _7, float _2, float _5, float _8) {
		matrixElement[0] = (_0);
		matrixElement[3] = (_3);
		matrixElement[6] = (_6);

		matrixElement[1] = (_1);
		matrixElement[4] = (_4);
		matrixElement[7] = (_7);

		matrixElement[2] = (_2);
		matrixElement[5] = (_5);
		matrixElement[8] = (_8);
	}

	//destructor
	otterMatrix::~otterMatrix() {};

	//copy constructor
	otterMatrix& otterMatrix::operator=(const otterMatrix& m) {
		for (int i = 0; i < 9; i++) {
			matrixElement[i] = m.matrixElement[i];
		}
		return *this;
	}

	//matrix addition
	void otterMatrix::operator+=(const otterMatrix& m) {
		for (int i = 0; i < 9; i++) {
			matrixElement[i] += m.matrixElement[i];
		}
	}
	otterMatrix& otterMatrix::operator+(const otterMatrix& m) const {
		otterMatrix newMatrix;
		for (int i = 0; i < 9; i++) {
			newMatrix.matrixElement[i] = matrixElement[i] + m.matrixElement[i];
		}
		return newMatrix;
	}

	//matrix subtraction
	void otterMatrix::operator-=(const otterMatrix& m) {
		for (int i = 0; i < 9; i++) {
			matrixElement[i] -= m.matrixElement[i];
		}
	}
	otterMatrix& otterMatrix::operator-(const otterMatrix& m) const {
		otterMatrix newMatrix;
		for (int i = 0; i < 9; i++) {
			newMatrix.matrixElement[i] = matrixElement[i] - m.matrixElement[i];
		}
		return newMatrix;
	}

	//scalar multiplication
	void otterMatrix::operator*=(const float s) {
		for (int i = 0; i < 9; i++) {
			matrixElement[i] *= s;
		}
	}
	otterMatrix& otterMatrix::operator*(const float s) const {
		otterMatrix newMatrix;
		for (int i = 0; i < 9; i++) {
			newMatrix.matrixElement[i] = matrixElement[i] * s;
		}
		return newMatrix;
	}

	//scalar division
	void otterMatrix::operator/=(const float s) {
		for (int i = 0; i < 9; i++) {
			matrixElement[i] /= s;
		}
	}
	otterMatrix& otterMatrix::operator/(const float s) const {
		otterMatrix newMatrix;
		for (int i = 0; i < 9; i++) {
			newMatrix.matrixElement[i] = matrixElement[i] / s;
		}
		return newMatrix;
	}

	//matrix multiplication
	void otterMatrix::operator*=(const otterMatrix& m) {
		*this = otterMatrix::operator*(m);
	}
	otterMatrix& otterMatrix::operator*(const otterMatrix& m) const {
		otterMatrix newMatrix;
		for (int i = 0; i < 9; i++) {
			newMatrix.matrixElement[i] = matrixElement[i % 3] * m.matrixElement[i / 3 * 3] +
				matrixElement[i % 3 + 3] * m.matrixElement[i / 3 * 3 + 1] +
				matrixElement[i % 3 + 6] * m.matrixElement[i / 3 * 3 + 2];
		}
		return newMatrix;
	}
}