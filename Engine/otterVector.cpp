#include "otterVector.h"
#include "otterQuaternion.h"
#include <iostream>

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
		return *this* v;
	}
	float otterVector::dot(const otterVector& v1, const otterVector& v2) {
		return v1 * v2;
	}

	//cross product
	otterVector otterVector::cross(const otterVector& v) const {
		return cross(*this, v);
	}
	otterVector otterVector::cross(const otterVector& v1, const otterVector& v2) {
		return otterVector(
			v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x);
	}

	//magnitude
	float otterVector::magnitude() {
		return magnitude(*this);
	}
	float otterVector::magnitude(const otterVector& v) {
		return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	}

	//sqr magnitude
	float otterVector::sqrMagnitude() {
		return sqrMagnitude(*this);
	}
	float otterVector::sqrMagnitude(const otterVector& v) {
		return v.x * v.x + v.y * v.y + v.z * v.z;
	}

	//normalize
	void otterVector::normalized() {
		*this = normalize(*this);
	}
	otterVector otterVector::normalize(const otterVector& v) {
		float mag = magnitude(v);
		if (mag > 0.0f) {
			return otterVector(v / mag);
		}
		return v;
	}

	//zero vector
	otterVector otterVector::zero() {
		return otterVector();
	}

	//rotate vector
	otterVector otterVector::rotateVector(float _angle, const otterVector& _axis)
	{
		otterQuaternion real(_angle, normalize(_axis));
		return (real * otterQuaternion(0, _axis) * otterQuaternion::inverse(otterQuaternion::unitNorm(real))).v;
	}
}