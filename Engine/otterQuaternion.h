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

		//quaternion addition
		void operator+=(const otterQuaternion& q);
		otterQuaternion& operator+(const otterQuaternion& q) const;

		//quaternion subtraction
		void operator-=(const otterQuaternion& q);
		otterQuaternion& operator-(const otterQuaternion& q) const;

		//scalar multiplication
		void operator*=(const float s);
		otterQuaternion& operator*(const float s) const;

		//scalar division
		void operator/=(const float s);
		otterQuaternion& operator/(const float s) const;

		//quaternion product
		void operator*=(const otterQuaternion& q);
		otterQuaternion& operator*(const otterQuaternion& q) const;

		//quaternion norm
		static float norm(const otterQuaternion& q);
	};
}

