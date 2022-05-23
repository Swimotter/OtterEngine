#include "otterVector.h"

namespace otterEngine {
	//constructors
	otterVector::otterVector() :
		x(0.0),
		y(0.0),
		z(0.0) {};
	otterVector::otterVector(float _x, float _y, float _z) :
		x(_x),
		y(_y),
		z(_z) {};

	//destructor
	otterVector::~otterVector() {};

	//copy constructors
	otterVector::otterVector(const otterVector& v) :
		x(v.x),
		y(v.y),
		z(v.z) {};
	otterVector& otterVector::operator=(const otterVector& v) {
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	//vector addition
	void otterVector::operator+=(const otterVector& v) {
		x += v.x;
		y += v.y;
		z += v.z;
	}
	otterVector otterVector::operator+(const otterVector& v) const {
		return otterVector(x + v.x, y + v.y, z + v.z);
	}

	//vector subtraction
	void otterVector::operator-=(const otterVector& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}
	otterVector otterVector::operator-(const otterVector& v) const {
		return otterVector(x - v.x, y - v.y, z - v.z);
	}

	//scalar multiplication
	void otterVector::operator*=(const float s) {
		x *= s;
		y *= s;
		z *= s;
	}
	otterVector otterVector::operator*(const float s) const {
		return otterVector(x * s, y * s, z * s);
	}

	//scalar division
	void otterVector::operator/=(const float s) {
		x /= s;
		y /= s;
		z /= s;
	}
	otterVector otterVector::operator/(const float s) const {
		return otterVector(x / s, y / s, z / s);
	}

	//dot product
	float otterVector::operator*(const otterVector& v) const {
		return x * v.x + y * v.y + z * v.z;
	}
	float otterVector::dot(const otterVector& v) const {
		return x * v.x + y * v.y + z * v.z;
	}

	//cross product
	otterVector otterVector::cross(const otterVector& v) const {
		return otterVector(y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x);
	}
}