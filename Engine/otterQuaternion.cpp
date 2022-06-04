#include "otterQuaternion.h"
#include "otterVector.h"
#include <iostream>

namespace otterMath {
	//constructors
	otterQuaternion::otterQuaternion() :
		s(0.0),
		v(otterVector()) {};
	otterQuaternion::otterQuaternion(float _s, const otterVector& _v) :
		s(_s),
		v(_v) {};

	//destructor
	otterQuaternion::~otterQuaternion() {};

	//copy constructors
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
	otterQuaternion otterQuaternion::operator+(const otterQuaternion& q) const {
		return otterQuaternion(s + q.s, v + q.v);
	}

	//quaternion subtraction
	void otterQuaternion::operator-=(const otterQuaternion& q) {
		s -= q.s;
		v -= q.v;
	}
	otterQuaternion otterQuaternion::operator-(const otterQuaternion& q) const {
		return otterQuaternion(s - q.s, v - q.v);
	}

	//scalar multiplication
	void otterQuaternion::operator*=(const float _s) {
		s *= _s;
		v *= _s;
	}
	otterQuaternion otterQuaternion::operator*(float _s) const {
		return otterQuaternion(s * _s, v * _s);
	}

	//scalar division
	void otterQuaternion::operator/=(const float _s) {
		s /= _s;
		v /= _s;
	}
	otterQuaternion otterQuaternion::operator/(float _s) const {
		return otterQuaternion(s / _s, v / _s);
	}

	//quaternion product
	void otterQuaternion::operator*=(const otterQuaternion& q) {
		s = s * q.s + v * q.v;
		v = q.v * s + v * q.s + otterVector::cross(v, q.v);
	}
	otterQuaternion otterQuaternion::operator*(const otterQuaternion& q) const {
		return otterQuaternion(s * q.s + v * q.v, q.v * s + v * q.s + otterVector::cross(v, q.v));
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
	otterQuaternion otterQuaternion::unitNorm(const otterQuaternion& q) {
		float quaternionNorm = norm(q);
		if (quaternionNorm == !0) {
			return q / quaternionNorm;
		}
		return q;
	}

	//conjugate
	otterQuaternion otterQuaternion::conjugate(const otterQuaternion& q) {
		return otterQuaternion(q.s, q.v * -1);
	}

	//inverse
	otterQuaternion otterQuaternion::inverse(const otterQuaternion& q) {
		return otterQuaternion(conjugate(q) / normSqr(q));
	}
}