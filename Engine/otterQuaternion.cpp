#include "otterQuaternion.h"
#include "otterVector.h"
#include <iostream>

namespace otterEngine {
	//constructors
	otterQuaternion::otterQuaternion() :
		s(0.0),
		v(otterVector()) {};
	otterQuaternion::otterQuaternion(float _s, otterVector& _v) :
		s(_s),
		v(_v) {};

	//destructor
	otterQuaternion::~otterQuaternion() {};

	//copy constructor
	otterQuaternion::otterQuaternion(const otterQuaternion& q) :
		s(q.s),
		v(q.v) {};
	otterQuaternion& otterQuaternion::operator=(const otterQuaternion& q) {
		s = q.s;
		v = q.v;
		return *this;
	}

	//quaternion addition
	void otterQuaternion::operator+=(const otterQuaternion& q) {
		s += q.s;
		v += q.v;
	}
	otterQuaternion& otterQuaternion::operator+(const otterQuaternion& q) const
	{
		float scalar = s + q.s;
		otterVector vector = v + q.v;
		otterQuaternion newQuaternion = otterQuaternion(scalar, vector);
		return newQuaternion;
	}

	//quaternion subtraction
	void otterQuaternion::operator-=(const otterQuaternion& q) {
		s -= q.s;
		v -= q.v;
	}
	otterQuaternion& otterQuaternion::operator-(const otterQuaternion& q) const
	{
		float scalar = s - q.s;
		otterVector vector = v - q.v;
		otterQuaternion newQuaternion = otterQuaternion(scalar, vector);
		return newQuaternion;
	}

	//scalar multiplication
	void otterQuaternion::operator*=(const float _s) {
		s *= _s;
		v *= _s;
	}
	otterQuaternion& otterQuaternion::operator*(const float _s) const {
		float scalar = s * _s;
		otterVector vector = v * _s;
		otterQuaternion newQuaternion = otterQuaternion(scalar, vector);
		return newQuaternion;
	}

	//scalar division
	void otterQuaternion::operator/=(const float _s) {
		s /= _s;
		v /= _s;
	}
	otterQuaternion& otterQuaternion::operator/(const float _s) const {
		float scalar = s / _s;
		otterVector vector = v / _s;
		otterQuaternion newQuaternion = otterQuaternion(scalar, vector);
		return newQuaternion;
	}

	//quaternion product
	void otterQuaternion::operator*=(const otterQuaternion& q) {
		s = s * q.s + v * q.v;
		v = q.v * s + v * q.s + otterVector::cross(v, q.v);
	}

	otterQuaternion& otterQuaternion::operator*(const otterQuaternion& q) const {
		float scalar = s * q.s + v * q.v;
		otterVector vector = q.v * s + v * q.s + otterVector::cross(v, q.v);
		otterQuaternion newQuaternion = otterQuaternion(scalar, vector);
		return newQuaternion;
	}

	//quaternion norm
	float otterQuaternion::norm(const otterQuaternion& q) {
		return std::sqrt(q.s * q.s + q.v * q.v);
	}

	//quaternion norm squared
	float otterQuaternion::normSqr(const otterQuaternion& q) {
		return q.s * q.s + q.v * q.v;
	}

	//normalize
	otterQuaternion& otterQuaternion::unitNorm(const otterQuaternion& q) {
		float quaternionNorm = norm(q);
		otterQuaternion output = q;
		if (quaternionNorm == !0) {
			output = q / norm(q);
		}
		return output;
	}

	//conjugate
	otterQuaternion& otterQuaternion::conjugate(const otterQuaternion& q) {
		otterVector vector = q.v * -1;
		otterQuaternion newQuaternion = otterQuaternion(q.s, vector);
		return newQuaternion;
	}

	//inverse
	otterQuaternion& otterQuaternion::inverse(const otterQuaternion& q) {
		otterQuaternion conj = conjugate(q);
		float sqrNorm = normSqr(q);
		otterQuaternion newQuaternion = otterQuaternion(conj / sqrNorm);
		return newQuaternion;
	}
}