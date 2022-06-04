#include "otterDualQuaternion.h"
#include "otterQuaternion.h"
#include <iostream>

namespace otterMath {
	//constructors
	otterDualQuaternion::otterDualQuaternion() :
		qRot(otterQuaternion()),
		qPos(otterQuaternion()) {};
	otterDualQuaternion::otterDualQuaternion(otterQuaternion _qRot, otterQuaternion _qPos) :
		qRot(_qRot),
		qPos(_qPos) {};

	//destructor
	otterDualQuaternion::~otterDualQuaternion() {};

	//copy constructors
	otterDualQuaternion::otterDualQuaternion(const otterDualQuaternion& dq) :
		qRot(dq.qRot),
		qPos(dq.qPos) {};
	otterDualQuaternion& otterDualQuaternion::operator=(const otterDualQuaternion& dq) {
		qRot = dq.qRot;
		qPos = dq.qPos;
		return *this;
	}

	//dual quaternion addition
	void otterDualQuaternion::operator+=(const otterDualQuaternion& dq) {
		qRot += dq.qRot;
		qPos += dq.qPos;
	}
	otterDualQuaternion otterDualQuaternion::operator+(const otterDualQuaternion& dq) {
		return otterDualQuaternion(qRot + dq.qRot, qPos + dq.qPos);
	}

	//dual quaternion subtraction
	void otterDualQuaternion::operator-=(const otterDualQuaternion& dq) {
		qRot -= dq.qRot;
		qPos -= dq.qPos;
	}
	otterDualQuaternion otterDualQuaternion::operator-(const otterDualQuaternion& dq) {
		return otterDualQuaternion(qRot - dq.qRot, qPos - dq.qPos);
	}

	//scalar multiplication
	void otterDualQuaternion::operator*=(float s) {
		qRot *= s;
		qPos *= s;
	}
	otterDualQuaternion otterDualQuaternion::operator*(float s) {
		return otterDualQuaternion(qRot * s, qPos * s);
	}

	//scalar division
	void otterDualQuaternion::operator/=(float s) {
		qRot /= s;
		qPos /= s;
	}
	otterDualQuaternion otterDualQuaternion::operator/(float s) {
		return otterDualQuaternion(qRot / s, qPos / s);
	}

	//dual quaternion multiplication
	void otterDualQuaternion::operator*=(const otterDualQuaternion& dq) {
		qRot *= dq.qRot;
		qPos = qPos * dq.qRot + dq.qPos * qRot;
	}
	otterDualQuaternion otterDualQuaternion::operator*(const otterDualQuaternion& dq) {
		return otterDualQuaternion(qRot * dq.qRot, qPos * dq.qRot + dq.qPos * qRot);
	}

	//first conjugate
	otterDualQuaternion otterDualQuaternion::firstConjugate(const otterDualQuaternion& dq) {
		return otterDualQuaternion(otterQuaternion::conjugate(dq.qRot), otterQuaternion::conjugate(dq.qPos));
	}

	//second conjugate
	otterDualQuaternion otterDualQuaternion::secondConjugate(const otterDualQuaternion& dq) {
		return otterDualQuaternion(dq.qRot, dq.qPos * -1);
	}

	//third conjugate
	otterDualQuaternion otterDualQuaternion::thirdConjugate(const otterDualQuaternion& dq) {
		return otterDualQuaternion(otterQuaternion::conjugate(dq.qRot), otterQuaternion::conjugate(dq.qPos) * -1);
	}

	//norm
	otterDual otterDualQuaternion::norm(const otterDualQuaternion& dq) {
		float mag = otterQuaternion::norm(dq.qRot);
		if (mag == 0) {
			return otterDual(0, otterQuaternion::norm(dq.qPos));
		}
		return otterDual(otterQuaternion::norm(dq.qRot), (dq.qRot * otterQuaternion::conjugate(dq.qPos) + dq.qPos * otterQuaternion::conjugate(dq.qRot)).s / (2 * mag));
	}

	//normalize
	otterDualQuaternion otterDualQuaternion::normalize(const otterDualQuaternion& dq) {
		float mag = otterQuaternion::norm(dq.qRot);
		return otterDualQuaternion(dq.qRot / mag, dq.qPos / mag);
	}
}