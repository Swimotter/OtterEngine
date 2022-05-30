#include "otterQuaternion.h"
#include "otterVector.h"

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
}