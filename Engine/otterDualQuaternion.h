#pragma once
#include "otterQuaternion.h"

namespace otterMath {
	class otterDualQuaternion
	{
	private:

	public:
		//rotational quaternion
		otterQuaternion qRot;

		//translational quaternion
		otterQuaternion qPos;

		//constructors
		otterDualQuaternion();
		otterDualQuaternion(otterQuaternion _qRot, otterQuaternion _qPos);

		//destructors
		~otterDualQuaternion();

		//copy constructors
		otterDualQuaternion(const otterDualQuaternion& dq);
		otterDualQuaternion& operator=(const otterDualQuaternion& dq);

		//dual quaternion addition
		void operator+=(const otterDualQuaternion& dq);
		otterDualQuaternion operator+(const otterDualQuaternion& dq);

		//dual quaternion subtraction
		void operator-=(const otterDualQuaternion& dq);
		otterDualQuaternion operator-(const otterDualQuaternion& dq);
	};
}