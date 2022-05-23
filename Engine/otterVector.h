namespace otterEngine {
	class otterVector {
	private:

	public:
		//position in cartesian coordinates
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
		void operator*=(const float s);
		otterVector operator*(const float s) const;

		//scalar division
		void operator/=(const float s);
		otterVector operator/(const float s) const;

		//dot product
		float operator*(const otterVector& v) const;
		float dot(const otterVector& v) const;

		//cross product
		otterVector cross(const otterVector& v) const;

		//magnitude
		float magnitude();

		//normalize
		void normalize();
	};
}