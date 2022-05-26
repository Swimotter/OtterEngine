#include "otterMatrix.h"
#include <iostream>

namespace otterEngine {
	//constructors
	//
	//3x3 matrix--column major
	//0 3 6
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

	//matrix product
	void otterMatrix::operator*=(const otterMatrix& m) {
		*this = *this * m;
	}
	otterMatrix& otterMatrix::operator*(const otterMatrix& m) const {
		return matrixProduct(*this, m);
	}
	otterMatrix& otterMatrix::matrixProduct(const otterMatrix& m1, const otterMatrix& m2) {
		otterMatrix newMatrix;
		for (int i = 0; i < 9; i++) {
			newMatrix.matrixElement[i] = m1.matrixElement[i % 3] * m2.matrixElement[i / 3 * 3] +
				m1.matrixElement[i % 3 + 3] * m2.matrixElement[i / 3 * 3 + 1] +
				m1.matrixElement[i % 3 + 6] * m2.matrixElement[i / 3 * 3 + 2];
		}
		return newMatrix;
	}

	//identity matrix
	otterMatrix& otterMatrix::identity() {
		otterMatrix m;
		return m;
	}

	//determinant
	float otterMatrix::determinant() const {
		return determinant(*this);
	}
	float otterMatrix::determinant(const otterMatrix& m) {
		float output = 0;
		for (int i = 0; i < 3; i++) {
			std::cout << (((i + 1) * 3 + 1) % 9 + 9) % 9 << ',' << (((i + 1) * -6 + 5) % 9 + 9) % 9 << ',' << (((i + 1) * -6 + 4) % 9 + 9) % 9 << ',' << (((i + 1) * 3 + 2) % 9 + 9) % 9 << '\n';
			output += m.matrixElement[i * 3] *
				(m.matrixElement[(((i + 1) * 3 + 1) % 9 + 9) % 9] * m.matrixElement[(((i + 1) * -6 + 5) % 9 + 9) % 9] -
				m.matrixElement[(((i + 1) * -6 + 4) % 9 + 9) % 9] * m.matrixElement[(((i + 1) * 3 + 2) % 9 + 9) % 9]);
		}
		return output;
	}

	//transpose
	void otterMatrix::transpose() {
		float temp = matrixElement[1];
		matrixElement[1] = matrixElement[3];
		matrixElement[3] = temp;
		temp = matrixElement[2];
		matrixElement[2] = matrixElement[6];
		matrixElement[6] = temp;
		temp = matrixElement[5];
		matrixElement[5] = matrixElement[7];
		matrixElement[7] = temp;
	}
	otterMatrix& otterMatrix::transpose(const otterMatrix& m) {
		otterMatrix newMatrix = otterMatrix(
			m.matrixElement[0],
			m.matrixElement[3],
			m.matrixElement[6],
			m.matrixElement[1],
			m.matrixElement[4],
			m.matrixElement[7],
			m.matrixElement[2],
			m.matrixElement[5],
			m.matrixElement[8]);
		return newMatrix;
	}

	//adjugate
	void otterMatrix::adjugate() {
		*this = adjugate(*this);
	}
	otterMatrix& otterMatrix::adjugate(otterMatrix& m) {
		otterMatrix newMatrix = otterMatrix();
		float invd = 1.0f / determinant(m);
		newMatrix.matrixElement[0] = (m.matrixElement[4] * m.matrixElement[8] - m.matrixElement[5] * m.matrixElement[7]) * invd;
		newMatrix.matrixElement[1] = (m.matrixElement[3] * m.matrixElement[8] - m.matrixElement[5] * m.matrixElement[6]) * invd;
		newMatrix.matrixElement[2] = (m.matrixElement[3] * m.matrixElement[7] - m.matrixElement[4] * m.matrixElement[6]) * invd;
		newMatrix.matrixElement[3] = (m.matrixElement[1] * m.matrixElement[8] - m.matrixElement[2] * m.matrixElement[7]) * invd;
		newMatrix.matrixElement[4] = (m.matrixElement[0] * m.matrixElement[8] - m.matrixElement[2] * m.matrixElement[6]) * invd;
		newMatrix.matrixElement[5] = (m.matrixElement[0] * m.matrixElement[7] - m.matrixElement[1] * m.matrixElement[6]) * invd;

		newMatrix.matrixElement[6] = (m.matrixElement[1] * m.matrixElement[5] - m.matrixElement[2] * m.matrixElement[4]) * invd;
		newMatrix.matrixElement[7] = (m.matrixElement[0] * m.matrixElement[5] - m.matrixElement[2] * m.matrixElement[3]) * invd;
		newMatrix.matrixElement[8] = (m.matrixElement[0] * m.matrixElement[4] - m.matrixElement[1] * m.matrixElement[3]) * invd;
		/*for (int i = 0; i < 9; i++) {
			newMatrix.matrixElement[i] =
				m.matrixElement[((i + 1) * 17 - 4) % 9] * m.matrixElement[((i + 1) * -6 + 5) % 9] -
				m.matrixElement[((i + 1) * -6 + 4) % 9] * m.matrixElement[((i + 1) * 3 + 2) % 9];
		}*/
		return newMatrix;
	}
}