#pragma once
#include "otterVector.h"

namespace otterMath {
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
		otterQuaternion(float _s, const otterVector& _v);

		//destructor
		~otterQuaternion();

		//copy constructors
		otterQuaternion(const otterQuaternion& q);
		otterQuaternion& operator=(const otterQuaternion& q);

		//quaternion addition
		void operator+=(const otterQuaternion& q);
		otterQuaternion operator+(const otterQuaternion& q) const;

		//quaternion subtraction
		void operator-=(const otterQuaternion& q);
		otterQuaternion operator-(const otterQuaternion& q) const;

		//scalar multiplication
		void operator*=(float s);
		otterQuaternion operator*(float s) const;

		//scalar division
		void operator/=(float s);
		otterQuaternion operator/(float s) const;

		//quaternion product
		void operator*=(const otterQuaternion& q);
		otterQuaternion operator*(const otterQuaternion& q) const;

		//quaternion norm
		static float norm(const otterQuaternion& q);

		//quaternion norm squared
		static float normSqr(const otterQuaternion& q);

		//normalize
		static otterQuaternion unitNorm(const otterQuaternion& q);

		//conjugate
		static otterQuaternion conjugate(const otterQuaternion& q);

		//inverse
		static otterQuaternion inverse(const otterQuaternion& q);

		//dot product
		static float dot(const otterQuaternion& q1, const otterQuaternion& q2);
	};
}