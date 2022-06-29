#pragma once
#include "otterQuaternion.h"
#include "otterDual.h"

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
		otterDualQuaternion operator+(const otterDualQuaternion& dq) const;

		//dual quaternion subtraction
		void operator-=(const otterDualQuaternion& dq);
		otterDualQuaternion operator-(const otterDualQuaternion& dq) const;

		//scalar multiplication
		void operator*=(float s);
		otterDualQuaternion operator*(float s) const;

		//scalar division
		void operator/=(float s);
		otterDualQuaternion operator/(float s) const;

		//dual quaternion multiplication
		void operator*=(const otterDualQuaternion& dq);
		otterDualQuaternion operator*(const otterDualQuaternion& dq) const;

		//first conjugate
		static otterDualQuaternion firstConjugate(const otterDualQuaternion& dq);

		//second conjugate
		static otterDualQuaternion secondConjugate(const otterDualQuaternion& dq);

		//third conjugate
		static otterDualQuaternion thirdConjugate(const otterDualQuaternion& dq);

		//norm
		static otterDual norm(const otterDualQuaternion& dq);

		//normalize
		static otterDualQuaternion normalize(const otterDualQuaternion& dq);
	};
}