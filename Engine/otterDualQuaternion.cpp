#include "otterDualQuaternion.h"
#include "otterQuaternion.h"

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
}