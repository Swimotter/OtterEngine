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
}