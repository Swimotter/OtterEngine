#pragma once
#include "otterVector.h"

namespace otterEngine {
	class otterQuaternion
	{
	private:

	public:
		//scalar component
		float s;

		//vector component
		otterVector v;

		//constructors
		otterQuaternion();
		otterQuaternion(float _s, otterVector& _v);

		//destructor
		~otterQuaternion();

		//copy constructors
		otterQuaternion(const otterQuaternion& q);
		otterQuaternion& operator=(const otterQuaternion& q);
	};
}

