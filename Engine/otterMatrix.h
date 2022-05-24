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
		otterMatrix& operator=(const otterMatrix& m);

		//matrix addition
		void operator+=(const otterMatrix& m);
		otterMatrix& operator+(const otterMatrix& m) const;

		//matrix subtraction
		void operator-=(const otterMatrix& m);
		otterMatrix& operator-(const otterMatrix& m) const;
	};
}