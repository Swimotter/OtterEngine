#pragma once
namespace otterMath {
	class otterVector {
	private:

	public:
		//x, y, z components of vector
		float x;
		float y;
		float z;

		//constructors
		otterVector();
		otterVector(float _x, float _y, float _z);

		//destructor
		~otterVector();

		//copy constructors
		otterVector(const otterVector& v);
		otterVector& operator=(const otterVector& v);

		//addition
		void operator+=(const otterVector& v);
		otterVector operator+(const otterVector& v) const;

		//subtraction
		void operator-=(const otterVector& v);
		otterVector operator-(const otterVector& v) const;

		//scalar multiplication
		void operator*=(float s);
		otterVector operator*(float s) const;

		//scalar division
		void operator/=(float s);
		otterVector operator/(float s) const;

		//dot product
		float operator*(const otterVector& v) const;
		float dot(const otterVector& v) const;
		static float dot(const otterVector& v1, const otterVector& v2);

		//cross product
		otterVector cross(const otterVector& v) const;
		static otterVector cross(const otterVector& v1, const otterVector& v2);

		//magnitude
		float magnitude();
		static float magnitude(const otterVector& v);

		//sqr magnitude
		float sqrMagnitude();
		static float sqrMagnitude(const otterVector& v);

		//normalize
		void normalized();
		static otterVector normalize(const otterVector& v);

		//zero vector
		static otterVector zero();

		//rotate vector
		static otterVector rotateVector(float _angle, const otterVector& _axis);
	};
}