#pragma once

namespace otterEngine {
	class otterMatrix {
	private:
	
	public:
		//matrix elements
		float matrixElement[9] = { 0.0f };

		//constructors
		otterMatrix();
		otterMatrix(float _0, float _3, float _6, float _1, float _4, float _7, float _2, float _5, float _8);

		//destructor
		~otterMatrix();

		//copy constructor
		/*otterMatrix(const otterMatrix& m);
		otterMatrix& operator=(const otterMatrix& m);*/

		//matrix addition
		void operator+=(const otterMatrix& m);
		otterMatrix& operator+(const otterMatrix& m) const;

		//matrix subtraction
		void operator-=(const otterMatrix& m);
		otterMatrix& operator-(const otterMatrix& m) const;

		//scalar multiplication
		void operator*=(float s);
		otterMatrix& operator*(float s) const;

		//scalar division
		void operator/=(float s);
		otterMatrix& operator/(float s) const;

		//matrix product
		void operator*=(const otterMatrix& m);
		otterMatrix& operator*(const otterMatrix& m) const;
		static otterMatrix& matrixProduct(const otterMatrix& m1, const otterMatrix& m2);

		//vector transformation
		otterVector& operator*(const otterVector& v) const;
		static otterVector& vectorTransformation(const otterMatrix& m, const otterVector& v);

		//identity matrix
		static otterMatrix& identity();

		//determinant
		float determinant() const;
		static float determinant(const otterMatrix& m);

		//transpose
		void transpose();
		static otterMatrix& transpose(const otterMatrix& m);

		//adjugate
		void adjugate();
		static otterMatrix& adjugate(const otterMatrix& m);

		//inverse
		void invert();
		static otterMatrix& inverse(const otterMatrix& m);
	};
}